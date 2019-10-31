#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include <list>
#include <map>

class DataStorageManager{
    public:
        std::list<std::string> dispatch(const std::vector<std::string> &message){
            if(!message[0].compare("init")){
                this->init(message[1]);
            }else if(!message[0].compare("words")){
                this->words();
            }else{
                throw std::invalid_argument("Message not understoood\n");
            }
            return this->list_of_words;
        }

        void init(const std::string &path){
            std::fstream in(path);
            std::string x;
            while (in >> x){
                this->data += x;
                this->data += ' ';    
            }

            for(unsigned int i=0; i<this->data.length(); i++){
                if((this->data[i] < 'a' || this->data[i] > 'z') && (this->data[i] < 'A' || this->data[i] > 'Z')){
                    this->data[i] = ' ';
                }
            }

            std::transform(this->data.begin(), this->data.end(), this->data.begin(),
                [](unsigned char c){
                return std::tolower(c); 
            });

            for(unsigned int i=0; i<this->data.size(); i++){
                if(this->data[i] >= 'a' && this->data[i] <= 'z'){
                    dataOut += data[i];
                }
                if(this->data[i] == ' ' && this->data[i+1] != ' ' && this->data[i+1] != '\0'){
                    dataOut += data[i];
                }
            }
        }

        std::list<std::string> words(){
            std::string aux;
            for(unsigned int i=0; i<=this->dataOut.size(); i++){
                if(this->dataOut[i] != ' '){
                    aux += this->dataOut[i];
                }
                if(this->dataOut[i] == ' ' || this->dataOut[i] == '\0'){
                    list_of_words.push_back(aux);
                    aux = "";
                }
            }
            return list_of_words;
        }

    private:
        std::string data;
        std::string dataOut;
        std::list<std::string> list_of_words;
};

class StopWordManager{
    public:
        bool dispatch(const std::vector<std::string> &message){
            bool x;
            if(!message[0].compare("init")){
                this->init();
            }else if(!message[0].compare("is_stop_word")){
                auto m = message[1];
                x = this->is_stop_word(m);
            }else{
                throw std::invalid_argument("Message not understoood\n");
            }
            return x;
        }

        void init(){
            std::fstream in;
            in.open("stop_words.txt");
            std::string x, aux;
            in >> x;
            
            for(unsigned int i=0; i<=x.size(); i++){
                if(x[i] == ',' || x[i] == '\0'){
                    this->stop_words.push_back(aux);
                    aux = "";
                }else{
                    aux += x[i];
                }
            }
            in.close();
        }

        bool is_stop_word(std::string &word){
            std::string x = word;
            bool ret;
            for(auto p:this->stop_words){
                if(!p.compare(x)){
                    ret = true;
                    break;
                }else{
                    ret = false;;
                }
            }
            return ret;
        }

    private:
        std::list<std::string> stop_words;
};

class WordFrequencyManager{
    public:
        std::map<std::string, int> word_freq;

        void dispatch(const std::vector<std::string> &message){
            if(!message[0].compare("increment_count")){
                auto s = message[1];
                this->increment_cout(s);
            }else{
                throw std::invalid_argument("Message not understoood\n");
            }
        }

        void increment_cout(std::string &word){
            word_freq[word] += 1;
        }
};

class WordFrequencyController{
    public:
        void dispatch(const std::vector<std::string> &message){
            if(!message[0].compare("init")){
                auto m = message[1];
                this->init(m);
            }else if(!message[0].compare("run")){
                this->run();
            }else{
                throw std::invalid_argument("Message not understoood\n");
            }
        }

        void init(std::string &path){
            this->dsm = DataStorageManager();
            this->swm = StopWordManager();
            this->wfm = WordFrequencyManager();
            this->dsm.dispatch({"init", path});
            this->swm.dispatch({"init"});
        }

        void run(){
            std::list<std::string> aux;
            std::string s;
            bool x;
            aux = this->dsm.dispatch({"words"});
            
            for(auto p:aux){
                x = this->swm.dispatch({"is_stop_word", p});
                if(!x){
                    this->wfm.dispatch({"increment_count", p});
                }
            }

            std::vector<std::pair<int, std::string>> vec;

            for(auto p:this->wfm.word_freq){
                vec.push_back(make_pair(p.second, p.first));
            }

            sort(vec.begin(), vec.end());
            reverse(vec.begin(), vec.end());

            // for(auto p:vec){
            //     std::cout << p.second << " - " << p.first << "\n";
            // }

            for(int i=0; i<25; i++){
                std::cout << vec[i].second << " - " << vec[i].first << "\n";
            }
        }
        
    private:
        WordFrequencyManager wfm;
        StopWordManager swm;
        DataStorageManager dsm;
};

int main(const int argc, const char **argv){
    auto wfcontroller = WordFrequencyController();
    wfcontroller.dispatch({"init", *++argv});
    wfcontroller.dispatch({"run"});
}