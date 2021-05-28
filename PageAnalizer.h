#ifndef _PAGE_ANALIZER_H
#define _PAGE_ANALIZER_H


#include <fstream>
#include "MonitorCola.h"

class PageAnalizer{
  private:
    std::ifstream pages_file;
    std::string allowed_dom;
    MonitorCola& targets_queue;


  public:
    PageAnalizer(const std::string& file_name, const std::string& allowed,
                MonitorCola& url_to_procces);

    void analize(int offset, int size);

    ~PageAnalizer();
};

#endif
