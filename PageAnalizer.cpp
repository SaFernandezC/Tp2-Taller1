#include <string>
#include <utility>
#include "PageAnalizer.h"

#define ERROR -1
#define INIT_CHARS "http://"
#define INIT_CHARS_SIZE 8
#define BEGIN 0

PageAnalizer::PageAnalizer(const std::string& file_name,
  const std::string& allowed):allowed_dom(allowed){
    pages_file.open(file_name, std::ifstream::in);
    if (pages_file.fail()) {
      return; //TRATAR EXCEPCION
    }
  }

void PageAnalizer::analize(MonitorCola& targets_queue, int offset, int size){
  pages_file.seekg(offset, pages_file.beg);
  std::string word;
  while (pages_file.tellg() != ERROR && pages_file.tellg() < offset + size) {
    pages_file >> word;
    if (word.find(INIT_CHARS) == BEGIN &&
    word.find(allowed_dom + "/") !=  std::string::npos  &&
    word.find(allowed_dom + "/") < word.find("/", INIT_CHARS_SIZE)){
      targets_queue.push(word);
    }
  }
}

PageAnalizer::PageAnalizer(PageAnalizer&& other){
  this->pages_file = std::move(other.pages_file);
  this->allowed_dom = std::move(other.allowed_dom);
}

PageAnalizer& PageAnalizer::operator=(PageAnalizer&& other){
  this->pages_file = std::move(other.pages_file);
  this->allowed_dom = std::move(other.allowed_dom);
  return *this;
}

PageAnalizer::~PageAnalizer(){
  if (pages_file){
    pages_file.close();
  }
}
