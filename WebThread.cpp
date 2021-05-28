// #include <iostream>
// #include <string>
// #include "MonitorCola.cpp"
// #include "Thread.cpp"
// #include "Thread.h"
// #include "Index.h"
// #include "Index.cpp"
// #include "PageAnalizer.cpp"
// #include "PageAnalizer.h"
// #include "UrlStates.cpp"
// #include "UrlStates.h"

#include "WebThread.h"

WebThread::WebThread(MonitorCola& url_to_procces, Index& idx,
  const std::string& pages_file, std::string& allowed,
  UrlStates& estados):targets_queue(url_to_procces),states(estados),
  index(idx), analizer(pages_file, allowed, url_to_procces){}

void WebThread::run(){
  //Toma un url de la MonitorCola

  while (!targets_queue.empty() && !targets_queue.is_closed()){
    std::string url = targets_queue.pop();
    //Busca size y offset
    int offset, size;
    int valid = index.get_values(url, offset, size);
    if (valid == VALID){
      analizer.analize(offset, size);
      states.push(url, "explored");
    } else {
      states.push(url, "dead");
    }
  }

  return;
    //analiza

    // if(error){
      //   estado == "explored"
      // } else {
        //   estado == "dead"
        // }
        // std::ifstream pages_file("pages");
        // if (pages_file.fail()) {
          //   return; //TRATAR EXCEPCION
          // }
          //
          //
          // pages_file.seekg(offset, pages_file.beg);
          // std::string word;
          // while (pages_file.tellg() != -1 &&
          //pages_file.tellg() < offset + size) {
            //   pages_file >> word;
            //   if (/*parser.is_allowed(word)*/ ){
              //     std::cout << word << std::endl;
              //     // targets.push(word);
              //   }
              // }




              //La sube a la cola de analizadas
}

WebThread::~WebThread(){}
