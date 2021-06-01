#ifndef _URL_STATES_H
#define _URL_STATES_H

#include <mutex>
#include <map>
#include <string>

class UrlStates{
  private:
    std::mutex mtx;
    std::map<std::string, std::string> states;


  public:
    UrlStates();
    /*
    * Carga al mapa states la url con su estado.
    */
    void push(const std::string& url, const std::string& state);

    /*
    * Itera el mapa de estados imprimiendo por salida estadar
    * cada url con su estado.
    */
    void print_urls();

    ~UrlStates();


  private:
    UrlStates(const UrlStates &other) = delete;
    UrlStates& operator=(const UrlStates &other) = delete;
};

#endif
