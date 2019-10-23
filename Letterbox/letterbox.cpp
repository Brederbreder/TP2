#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>

// DataStorageManager x = DataStorageManager();
// DataStorageManager *x = new DataStorageManager();
// DataStorageManager x();

class DataStorageManager{
    public:
        void dispatch(const std::vector<std::string> &message){
            if(!message[0].compare("init")){
                this->init(message[1]);
            }
        }

        void init(const std::string &path){
            std::regex e("[\\w_]+");
            std::fstream in(path);
            std::string x;
            while (in >> x){
                this->data += x;    
            }
            for (std::sregex_iterator it(data.begin(), data.end(), e), it_end; it != it_end; ++it) {
                std::cout << (*it)[0] << "\n";
            }
        }
    private:
        std::string data;
};

class StopWordManager{

};

class WordFrequencyManager{

};

class WordFrequencyController{
    public:
        void dispatch(const std::vector<std::string> &message){
            if(!message[0].compare("init")){
                auto m = message[1];
                this->init(m);
            }else if(message[0].compare("run")){

            }else{
                throw std::invalid_argument("mensagem nao compreendida");
            }
        }

        void init(std::string &path){
            this->dsm = DataStorageManager();
            this->swm = StopWordManager();
            this->wfm = WordFrequencyManager();
            this->dsm.dispatch({"init", path});
        }
        
    private:
        WordFrequencyManager wfm;
        StopWordManager swm;
        DataStorageManager dsm;
        
};

int main(const int argc, const char **argv){
    auto wfcontroller = WordFrequencyController();
    wfcontroller.dispatch({"init", *++argv});
    
}