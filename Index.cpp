// #include <iostream>
// #include <string>
// #include <map>
// #include <vector>
#include <fstream>

#include "Index.h"

  Index::Index(const std::string& file_name){
    std::ifstream index_file(file_name.c_str());
    if (index_file.fail()) {
      return; //TRATAR EXCEPCION
    }

    std::string url;
    int offset, size;

    while (index_file >> url){
      std::vector<int> v(2);
      index_file >> std::hex >> offset;
      v[0] = offset;
      index_file >> std::hex >> size;
      v[1] = size;
      index[url] = v;
    }

    index_file.close();
  }

  int Index::get_values(std::string url, int& offset, int& size){
    if (index.find(url) == index.end()){
      return NOT_VALID;
    }
    std::vector<int> vec = index.at(url);
    offset = vec[0];
    size = vec[1];
    return VALID;
  }

  Index::~Index(){}
