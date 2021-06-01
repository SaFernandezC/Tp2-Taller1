#ifndef _INDEX_H
#define _INDEX_H

#include <string>
#include <map>
#include <vector>

#define NOT_VALID -1
#define VALID 0

class Index{
  private:
    std::map <std::string, std::vector<int>> index;

  public:
    /*
    * Carga en el mapa de inidices todas las url
    * del archivo index, junto a su offset y size.
    */
    explicit Index(const std::string& file_name);

    /*
    * Guardara el offset y el size para una url dada.
    * Retorna VALID si la url existe y NOT_VALID
    * en caso contrario.
    */
    int get_values(std::string url, int& offset, int& size) const;

    ~Index();

    Index(Index&& other);
    Index& operator=(Index&& other);

  private:
    Index(const Index&) = delete;
    Index& operator=(const Index&) = delete;
};

#endif
