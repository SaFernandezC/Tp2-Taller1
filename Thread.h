#ifndef _THREAD_H
#define _THREAD_H

#include <thread>

class Thread {
  private:
    std::thread thread;


  public:
    Thread();

    void start();

    void join();

    virtual void run() = 0;   //Virtual puro para
                          //forzar que lo defina cada clase hija

    virtual ~Thread(){};

    Thread(const Thread&) = delete; // Fuerzo a que no se puedan copiar hilos
    Thread& operator=(const Thread&) = delete;

    Thread(Thread&& other);

    Thread& operator=(Thread&& other);
};

#endif
