#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <iterator>
#include <functional>
#include <algorithm>

class Controller {
  public:
    explicit Controller(const std::string &path) {
        file.open(path);
        if (!file.is_open()) {
            throw std::invalid_argument("nao foi possivel abrir o arquivo");
        }
    }

    virtual ~Controller() = default;

    virtual void dispatch(const char **args) = 0;
  protected:
    std::ifstream file;
};

template <typename T>
void printer(const std::vector<T> v) {
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, "--"));
}

class StopWordManager : public Controller {
  public:
    StopWordManager(const std::string &path) : Controller(path) {
        std::string x;
        while (file >> x) {
            this->_stop_words.push_back(x);
            this->file.ignore(1); // pula a ','
        }
        std::for_each(this->_stop_words.begin(), this->_stop_words.end(), [](const std::string &s) {std::cout << s << "\n\n";});

        std::for_each(this->_stop_words.begin(), this->_stop_words.end(),
            [](std::string &s) {
                std::transform(s.begin(), s.end(), s.begin(),
                    [](unsigned char c) {
                        return std::tolower(c);
                    }); 
            });
    }

    ~StopWordManager() = default;
    
    template <typename T>
    using my_map = std::map<std::string, std::function<void(std::vector<T> v)>>;

    void dispatch(const char **args) override {
        my_map<std::string> funcoes = {
           {"init", printer<std::string>}
        };

        return funcoes[args[1]](this->_stop_words);
    }

  private:
    std::vector<std::string> _stop_words;
};

int main(const int argc, const char **argv) {
    auto swm = new StopWordManager("teste.txt");
    swm->dispatch(argv);
    return 0;
}
