#include "list.h"
#include <iostream>
int main() {

  List<int> list;
  for (unsigned i = 1; i < 9; i++) { list.insertBack(i); }
  //REQUIRE(list.size() == 10);
//std::cout<<list<<std::endl;
//list.print(std::cout);
//std::cout<<"NOTHING"<<std::endl;
std::cout<<list<<std::endl;
list.waterfall();
//list.reverseNth(3);
std::cout<<list<<std::endl;
//list.print(std::cout);
}
