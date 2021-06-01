#include "WebCrawler.h"
#include <string>
#include <chrono> // std::chrono::second


WebCrawler::WebCrawler(const std::string& idx, const std::string& target,
  const std::string& allowed, const std::string& pages_file,
  int cant_threads, int wait_time): index(idx),
  url_to_procces(target), cant_threads(cant_threads),
  sleep_time(wait_time), allowed_domain(allowed){
    for (int i = 0; i < cant_threads; i++) {
      web_threads.push_back(new WebThread(url_to_procces, index,
        pages_file, allowed_domain, states));
      }
}


void WebCrawler::ejecutar(){
  for (int i = 0; i < cant_threads; i++) {
    web_threads[i]->start();
  }

  std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
  url_to_procces.close();

  for (int i = 0; i < cant_threads; ++i) {
    web_threads[i]->join();
  }

  states.print_urls();
}


WebCrawler::~WebCrawler(){
  for (int i = 0; i < cant_threads; ++i) {
    delete web_threads[i];
  }
}
