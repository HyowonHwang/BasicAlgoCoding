#include <iostream>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void exchage_whitespace(char* target, int string_len) {
  if(!target || 0 >= string_len )
    return;

  uint32_t len_max_str = strlen(target);
  uint32_t spare_len = len_max_str - string_len;
  char* cursor = target;
  int count = 1;

  while(spare_len >= 2 || count < ) {
    if(*cursor == ' ') {
      memmove(cursor+3, cursor+1, len_max_str - count);
      *cursor = '%';
      *(cursor+1) = '2';
      *(cursor+2) = '0';
      count += 2;
      spare_len -= 2;
    }
    count++;
    cursor = cursor + count;
  }
}

int main(int argc, char* argv[]) {
  char* dest = strdup("Mr John Smith    ");
  exchage_whitespace(dest, 13);
  std::cout<< dest << std::endl;

  delete dest;
  return 0;
}

// John m a  d 
// John%20m a  d 
