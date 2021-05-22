#include <iostream>

// #include "Index.cpp"
// #include "MonitorCola.cpp"
#include "WebThread.cpp" //Incluye al monitor

#include <fstream>

#include <string>

#include <queue>
#include <vector>
#include <chrono>         // std::chrono::second

// #include <sstream>

class WebCrawler{

  private:
    Index index;
    int cant_threads;
    MonitorCola url_to_procces;
    std::vector<WebThread*> web_threads;  //vector de threads
    std::string allowed_domain;
    UrlStates states;

    int sleep_time;


    public:

      WebCrawler(const std::string& target, const std::string& idx, const std::string& allowed, const std::string& pages_file, int cant_threads, int wait_time): index(idx), url_to_procces(target), cant_threads(cant_threads), sleep_time(wait_time), allowed_domain(allowed){
        for (int i = 0; i < cant_threads; i++) {
          web_threads.push_back(new WebThread(url_to_procces, index, pages_file, allowed_domain, states));
        }
      }


      void ejecutar(){

        // std::cout << sleep_time << std::endl;
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


      ~WebCrawler(){
        for (int i = 0; i < cant_threads; ++i) {
          delete web_threads[i];
        }
      }



};
