#ifndef _WEB_THREAD_H
#define _WEB_THREAD_H

#include "Thread.h"
#include "Index.h"
#include "PageAnalizer.h"
#include "UrlStates.h"

class WebThread: public Thread{
  private:
    MonitorCola& targets_queue;
    UrlStates& states;
    Index& index;
    PageAnalizer analizer;

  public:
    WebThread(MonitorCola& url_to_procces, Index& idx,
              const std::string& pages_file, std::string& allowed,
              UrlStates& estados);

    virtual void run() override;

    ~WebThread();
};

#endif
