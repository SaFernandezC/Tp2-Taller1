
// #include <iostream>
#include <fstream>
// #include <vector>
// #include <string>
// #include <queue>
// #include <mutex>
//
// #include <condition_variable>
#include "MonitorCola.h"


MonitorCola::MonitorCola(const std::string& file_name): closed(false){
  std::ifstream targets_file(file_name);
  if (targets_file.fail()) {
    // return -1; //TRATAR EXCEPCION
    return;
  }
  std::string url;

  while (targets_file >> url){ //Cargo los targets en la queue
    targets_queue.push(url);
  }
  targets_file.close();
}


std::string MonitorCola::pop() {  //pop_if_not_empty
  std::unique_lock<std::mutex> lock(mtx);

  while (targets_queue.empty()) {
    if (closed == true){
      return NULL;
      //ACA IRIA UNA EXCEPCION?
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
    //HAGO EL UNLOCK ANTES?
    is_empty.notify_all(); //Notify_one ?
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
  closed = true;
  is_empty.notify_all();
}
