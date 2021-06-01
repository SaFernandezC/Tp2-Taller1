#include <string>
#include "WebThread.h"

#define EXPLORED "explored"
#define DEAD "dead"

WebThread::WebThread(MonitorCola& url_to_procces, Index& idx,
  const std::string& pages_file, std::string& allowed,
  UrlStates& estados):targets_queue(url_to_procces),states(estados),
  index(idx), analizer(pages_file, allowed){}

void WebThread::run(){
  while (!targets_queue.empty() && !targets_queue.is_closed()){
    //Ver si sacar el empty
    std::string url = targets_queue.pop();
    //Busca size y offset
    int offset, size;
    int valid = index.get_values(url, offset, size);
    if (valid == VALID){
      analizer.analize(targets_queue ,offset, size);
      states.push(url, EXPLORED);
    } else {
      states.push(url, DEAD);
    }
  }
}

WebThread::~WebThread(){}
