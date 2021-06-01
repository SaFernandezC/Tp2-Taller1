#ifndef _PAGE_ANALIZER_H
#define _PAGE_ANALIZER_H


#include <fstream>
#include <string>
#include "MonitorCola.h"

class PageAnalizer{
  private:
    std::ifstream pages_file;
    std::string allowed_dom;


  public:
    /*
    * Inicializa los campos allowed_dom y targets_queue con las
    * referencias que recibe. Abre el archivo pages con el nombre file_name.
    */
    PageAnalizer(const std::string& file_name, const std::string& allowed);

    /*
    * Recibe la cola de targets, un offset y un size. Analiza todas
    * las palabras en ese bloque de pagina y si encuentra url que cumplan
    * la condicion dada por allowed, las pushea a la targets_queue.
    */
    void analize(MonitorCola& targets_queue, int offset, int size);

    /*
    * Cierra el archivo pages.
    */
    ~PageAnalizer();

    PageAnalizer(PageAnalizer&& other);
    PageAnalizer& operator=(PageAnalizer&& other);

  private:
    PageAnalizer(const PageAnalizer&) = delete;
    PageAnalizer& operator=(const PageAnalizer&) = delete;
};

#endif
