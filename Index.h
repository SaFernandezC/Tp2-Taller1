#ifndef _INDEX_H
#define _INDEX_H

// #include <string>
#include <map>
#include <vector>
// #include <fstream>

#define NOT_VALID -1
#define VALID 0

class Index{

  private:
    std::map <std::string, std::vector<int>> index;

  public:

    explicit Index(const std::string& file_name);

    int get_values(std::string url, int& offset, int& size);

    ~Index();
};

#endif
