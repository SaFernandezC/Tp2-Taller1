#include <iostream>
#include <mutex>
#include <map>

class UrlStates{

  private:
    std::mutex mtx;
    std::map<std::string, std::string> states;


  public:

    UrlStates(){};

    void push(const std::string& url, const std::string& state){
      std::lock_guard<std::mutex> lock(mtx);
      states[url] = state;
    }

    void print_urls(){
      std::map<std::string, std::string>::const_iterator it;

      for(it = states.begin(); it != states.end(); it++){
        std::cout << it->first << " -> " << it->second  <<  std::endl;
      }
    }




    ~UrlStates(){};

  private:
    UrlStates(const UrlStates &other) = delete;
    UrlStates& operator=(const UrlStates &other) = delete;


};
