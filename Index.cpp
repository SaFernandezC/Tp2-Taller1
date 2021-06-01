#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include "Index.h"

#define VECTOR_SIZE 2

Index::Index(const std::string& file_name){
  std::ifstream index_file(file_name.c_str());
  if (index_file.fail()) {
    return;
  }

  std::string url;
  int offset, size;

  while (index_file >> url){
    std::vector<int> v(VECTOR_SIZE);
    index_file >> std::hex >> offset;
    v[0] = offset;
    index_file >> std::hex >> size;
    v[1] = size;
    index[url] = v;
  }

  index_file.close();
}

int Index::get_values(std::string url, int& offset, int& size) const{
  if (index.find(url) == index.end()){
    return NOT_VALID;
  }
  std::vector<int> vec = index.at(url);
  offset = vec[0];
  size = vec[1];
  return VALID;
}

Index::Index(Index&& other){
  this->index = std::move(other.index);
}

Index& Index::operator=(Index&& other){
  this->index = std::move(other.index);
  return *this;
}

Index::~Index(){}
