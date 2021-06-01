#ifndef _WEB_CRAWLER_H
#define _WEB_CRAWLER_H

#include "WebThread.h"
#include <queue>
#include <string>
#include <vector>

class WebCrawler{
  private:
    Index index;
    MonitorCola url_to_procces;
    int cant_threads;
    int sleep_time;
    std::string allowed_domain;
    std::vector<WebThread*> web_threads;
    UrlStates states;

  public:
    /*
    * Inicializa todos los atributos del objeto. Crea la cantidad
    * de threads indicada por cant_threads y los inserta al
    * vector de web_threads.
    */
    WebCrawler(const std::string& idx, const std::string& target,
              const std::string& allowed, const std::string& pages_file,
              int cant_threads, int wait_time);

    /*
    * Ejecuta el WebCrawler. Corre todos los hilos, espera wait_time,
    * luego cierra la cola, join de los hilos e imprime las url analizadas.
    */
    void ejecutar();

    /*
    * Delete de todos los hilos.
    */
    ~WebCrawler();

  private:
    WebCrawler(const WebCrawler&) = delete;
    WebCrawler& operator=(const WebCrawler&) = delete;
};

#endif
