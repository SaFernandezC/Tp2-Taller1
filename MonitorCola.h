#ifndef _MONITOR_COLA_H
#define _MONITOR_COLA_H

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
    explicit MonitorCola(const std::string& file_name);


    std::string pop();

    void push(const std::string& url);

    bool empty();

    bool is_closed();

    void close();
};

#endif
