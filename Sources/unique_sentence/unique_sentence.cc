#include <iostream>
#include <set> 
#include <stdlib.h>


bool UniqueSetence(const char* target) {

  if(!target)
    return false;

  char* cursor = const_cast<char*>(target);
  bool ret = true;
  std::set<char> dup_table;
  std::set<char>::iterator it;

  while(*cursor != '\0') {
    it = dup_table.find(*cursor);
    if(it != dup_table.end()){
      ret = false;
      break;
    }
    dup_table.insert(*cursor);
    cursor++;
  }

  return ret;
}

int main(int argc, char *argv[]) {
  if(argc != 2) {
    std::cerr << "Usage : " << argv[0] << " sentence" << std::endl;
    exit(1);
  }

  if(UniqueSetence(argv[1]))
    std::cout << "Unique " << std::endl;
  else 
    std::cout << "Duplicate " << std::endl;

  return 0;
}
