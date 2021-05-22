
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <mutex>

#include <condition_variable>


class MonitorCola{

  private:
    std::mutex mtx;
    std::queue<std::string> targets_queue;
    std::condition_variable is_empty;
    bool closed;

  public:
    MonitorCola(const std::string& file_name): closed(false){
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


    std::string pop() {  //pop_if_not_empty

      std::unique_lock<std::mutex> lock(mtx);

      while(targets_queue.empty()) {
        if(closed == true){
          return NULL;
          //ACA IRIA UNA EXCEPCION?
        }
        is_empty.wait(lock);
      }

      std::string url = targets_queue.front();
      targets_queue.pop();

      return url;
}

    void push(const std::string& url){

      std::unique_lock<std::mutex> lock(mtx);

      if(closed == false){
        targets_queue.push(url);
        //HAGO EL UNLOCK ANTES?
        is_empty.notify_all(); //Notify_one ?
      }
    }

    bool empty(){
      std::unique_lock<std::mutex> lock(mtx);
      return targets_queue.empty();
    }

    bool is_closed(){
      std::unique_lock<std::mutex> lock(mtx);
      return closed;
    }
    void close(){
      closed = true;
      is_empty.notify_all();
    }


};
