#ifndef _MONITOR_COLA_H
#define _MONITOR_COLA_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <string>

class MonitorCola{
  private:
    std::mutex mtx;
    std::queue<std::string> targets_queue;
    std::condition_variable is_empty;
    bool closed;

  public:
    /*
    * Carga todas las url del archivo target en la cola
    */
    explicit MonitorCola(const std::string& file_name);

    /*
    * Inserta una url a la cola (si no esta cerrada) y
    * luego notifica a todos los hilos que pueden estar esperando un pop.
    */
    void push(const std::string& url);

    /*
    * Devuelve el primer elemento de la cola. Es un
    * metodo bloqueante, si la cola esta vacia espera
    * a que alguien inserte algo. Si la cola esta vacia
    * retorna NULL
    */
    std::string pop();

    /*
    * Retorna true si la cola esta vacia, false en
    * caso contrario.
    */
    bool empty();

    /*
    * Retrona true si la cola esta cerrada, false en
    * caso contrario.
    */
    bool is_closed();

    /*
    * Cambia el estado de la cola a cerrada y notifica
    * a todos los hilos que esperaban para pop.
    */
    void close();

  private:
    MonitorCola(const MonitorCola&) = delete;
    MonitorCola& operator=(const MonitorCola&) = delete;
};

#endif
