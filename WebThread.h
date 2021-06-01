#ifndef _WEB_THREAD_H
#define _WEB_THREAD_H

#include "Thread.h"
#include "Index.h"
#include "PageAnalizer.h"
#include "UrlStates.h"
#include <string>

class WebThread: public Thread{
  private:
    MonitorCola& targets_queue;
    UrlStates& states;
    Index& index;
    PageAnalizer analizer;

  public:
    /*
    * Constructor. Inicializa los atributos del thread y crea
    * un PageAnalizer.
    */
    WebThread(MonitorCola& url_to_procces, Index& idx,
              const std::string& pages_file, std::string& allowed,
              UrlStates& estados);

    /*
    * Mientras que la cola no este vacia ni cerrada, toma una url de
    * la cola, busca el offset y size en el indice, la manda a analizar
    * al analizer y luego la inserta en las url ya analizadas con su
    * respectivo estado (explored or dead)
    */
    virtual void run() override;

    ~WebThread();

  private:
    WebThread(const WebThread&) = delete;
    WebThread& operator=(const WebThread&) = delete;
};

#endif
