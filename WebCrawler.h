#ifndef _WEB_CRAWLER_H
#define _WEB_CRAWLER_H

#include "WebThread.h" //Incluye al monitor
#include <queue>
#include <vector>

class WebCrawler{
  private:
    Index index;
    MonitorCola url_to_procces;
    int cant_threads;
    int sleep_time;
    std::string allowed_domain;
    std::vector<WebThread*> web_threads;  //vector de threads
    UrlStates states;

    public:
      WebCrawler(const std::string& idx, const std::string& target,
                const std::string& allowed, const std::string& pages_file,
                int cant_threads, int wait_time);


      void ejecutar();


      ~WebCrawler();
};

#endif
