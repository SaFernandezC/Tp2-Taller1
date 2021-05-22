#include <iostream>
#include <fstream>
#include <string>
#include "MonitorCola.cpp"


class PageAnalizer{


  private:
    std::ifstream pages_file;
    std::string allowed_dom;
    MonitorCola& targets_queue;


  public:
    PageAnalizer(const std::string& file_name, const std::string& allowed, MonitorCola& url_to_procces):allowed_dom(allowed), targets_queue(url_to_procces){
      // pages_file(file_name);
      pages_file.open(file_name, std::ifstream::in);
      if (pages_file.fail()) {
        return; //TRATAR EXCEPCION
      }
    }


    void analize(int offset, int size){
      pages_file.seekg(offset, pages_file.beg);
      std::string word;
      while (pages_file.tellg() != -1 && pages_file.tellg() < offset + size) {
        pages_file >> word;
        if (word.find("http://") == 0 && word.find(allowed_dom + "/") !=  std::string::npos){
          targets_queue.push(word);
          // std::cout << word << std::endl;
        }
      }
    }



    ~PageAnalizer(){
      if(pages_file){
        pages_file.close();
      }
    }




};
