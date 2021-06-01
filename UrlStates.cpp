#include <iostream>
#include "UrlStates.h"
#include <map>
#include <string>

UrlStates::UrlStates(){}

void UrlStates::push(const std::string& url, const std::string& state){
  std::lock_guard<std::mutex> lock(mtx);
  states[url] = state;
}

void UrlStates::print_urls(){
  std::map<std::string, std::string>::const_iterator it;

  for (it = states.begin(); it != states.end(); ++it){
    std::cout << it->first << " -> " << it->second  <<  std::endl;
  }
}

UrlStates::~UrlStates(){}
