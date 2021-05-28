#ifndef _URL_STATES_H
#define _URL_STATES_H

#include <mutex>
#include <map>

class UrlStates{

  private:
    std::mutex mtx;
    std::map<std::string, std::string> states;


  public:
    UrlStates();

    void push(const std::string& url, const std::string& state);

    void print_urls();




    ~UrlStates();

  private:
    UrlStates(const UrlStates &other) = delete;
    UrlStates& operator=(const UrlStates &other) = delete;
};

#endif
