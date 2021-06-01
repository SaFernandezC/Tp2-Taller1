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


  WebCrawler web_crawler(index, targets, allowed, pages,
                        cant_threads, wait_time);

  web_crawler.ejecutar();
  return 0;
}
