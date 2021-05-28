#include <iostream>

#include <string>
#include "WebCrawler.h"

// using namespace std;

int main(int argc, char const *argv[]) {
  if (argc != 7) {
		std::cout << "Cantidad incorrecta de parametros" << std::endl;
		return 0;
	}

  std::string targets(argv[1]);
  std::string allowed(argv[2]);
  int cant_threads = std::stoi(argv[3]);
  std::string index(argv[4]);
  std::string pages(argv[5]);
  int wait_time = std::stoi(argv[6]);

  //ESTADOS --> ready: la URL fue encontrada pero
  //            aún la página web no fue leída ni analizada.
  //        --> explored: la página web direccionada
  //            por la URL fue leída y procesada.
  //        --> dead: la URL apunta a una página
  //            web inexistente (no encontrada).


  // Index idx(index);

  WebCrawler web_crawler(index, targets, allowed, pages,
                        cant_threads, wait_time);

  web_crawler.ejecutar();
  /******************************************************************/

  // std::ifstream targets_file(targets);
  // if (targets_file.fail()) {
  //   return -1; //TRATAR EXCEPCION
  // }
  //
  // std::queue<std::string> targets_queue;
  // std::string url;
  //
  // while (targets_file >> url){ //Cargo los targets
  //   targets_queue.push(url);
  // }

  /******************************************************************/

  // std::ifstream pages_file(pages);
  // if (pages_file.fail()) {
  //   return -1; //TRATAR EXCEPCION
  // }
  //
  // int offset, size = 0;
  //
  // idx.get_values(targets_queue.front(), offset, size);
  //
  //
	// pages_file.seekg(offset, pages_file.beg);
	// std::string word;
	// while (pages_file.tellg() != -1 && pages_file.tellg() < offset + size) {
	// 	pages_file >> word;
  //   std::cout << word << std::endl;
	// 	// if (parser.is_allowed(word))
	// 	// 	targets.push(word);
  // }
  return 0;
}
