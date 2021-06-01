#include <fstream>
#include <string>
#include <utility>
#include "MonitorCola.h"


MonitorCola::MonitorCola(const std::string& file_name): closed(false){
  std::ifstream targets_file(file_name);
  if (targets_file.fail()) {
    return;
  }
  std::string url;

  while (targets_file >> url){
    targets_queue.push(url);
  }
  targets_file.close();
}


std::string MonitorCola::pop() {
  std::unique_lock<std::mutex> lock(mtx);

  while (targets_queue.empty()) {
    if (closed == true){
      return NULL; //ACA IRIA UNA EXCEPCION?
    }
    is_empty.wait(lock);
  }

  std::string url = targets_queue.front();
  targets_queue.pop();

  return url;
}

void MonitorCola::push(const std::string& url){
  std::unique_lock<std::mutex> lock(mtx);

  if (closed == false){
    targets_queue.push(url);
    is_empty.notify_all();
  }
}

bool MonitorCola::empty(){
  std::unique_lock<std::mutex> lock(mtx);
  return targets_queue.empty();
}

bool MonitorCola::is_closed(){
  std::unique_lock<std::mutex> lock(mtx);
  return closed;
}

void MonitorCola::close(){
  std::unique_lock<std::mutex> lock(mtx);
  closed = true;
  is_empty.notify_all();
}
