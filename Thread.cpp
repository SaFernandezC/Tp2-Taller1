// #include <iostream>
#include "Thread.h"



Thread::Thread(){}

void Thread::start(){
  thread = std::thread(&Thread::run, this);
}

void Thread::join(){
  thread.join();
}

// virtual void Thread::run() = 0;   //Virtual puro para
//forzar que lo defina cada clase hija

// virtual ~Thread() {}  //Destructor Virtual,
//siempre hacerlo virtual si voy a usar herencia


// Thread(const Thread&) = delete; // Fuerzo a que no se puedan copiar hilos
// Thread& operator=(const Thread&) = delete;


//Si tiene sentido que el hilo pueda moverse --> implemento
// constructor y operador asignacion por movimiento
Thread::Thread(Thread&& other){
  this->thread = std::move(other.thread);
  //Explicitamente le digo: "move" el hilo other.thread hacia this.thread
} // pero no lo copies

Thread& Thread::operator=(Thread&& other){
  this->thread = std::move(other.thread);
  return *this;
}
