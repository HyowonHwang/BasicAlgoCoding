#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdint.h>

void reverse_book(char* target_str) {
  if(!target_str)
    return;

  char* end = target_str;
  char temp;
  while(*end)
    end++;
  end--;
  
  while(target_str < end) {
   temp = *target_str;
   *target_str++ = *end;
   *end-- = temp;
  }
}

char* reverse_1(char* target_str) {

  if(!target_str)
    return nullptr;

  uint32_t idx = 0;
  uint32_t len_str = strlen(target_str);
  char* temp_string = new char[sizeof(char)*(len_str+1)];
  
  for(int i = len_str -1 ; i >= 0 ; i--) 
    temp_string[idx++] = target_str[i];
  temp_string[idx] = '\0';

  return temp_string;
}

void swap_2(char* src, char* dest) {
  char temp = 0;
  temp = *src;
  *src = *dest;
  *dest = temp;
}

void reverse_2(char* target_str) {
  // 1. len == odd
  // 2. len == even 
  if(!target_str)
    return;
  
  uint32_t len_str = strlen(target_str);

  for(int i = 0, j = len_str-1 ; i < (len_str/2) ; i++, j--) 
      swap_2(target_str+i, target_str+j);
  
}
int main(int argc, char *argv[]) {

  if(2 != argc) {
    std::cerr<<"Usage : " << argv[0] << " setence" <<  std::endl;
    exit(1);
  }

  char* reverse_str_1 = reverse_1(argv[1]);
  char* reverse_str_2 = strdup(argv[1]);
  char* reverse_str_book = strdup(argv[1]);
  
  reverse_2(reverse_str_2);
  reverse_book(reverse_str_book);

  std::cout <<"reverse 111: " << reverse_str_1 << std::endl;

  std::cout <<"reverse 222: " << reverse_str_2 << std::endl;
  std::cout <<"reverse book: " << reverse_str_book << std::endl;

  if(reverse_str_1) 
    delete []reverse_str_1;

  delete reverse_str_2;
  delete reverse_str_book;

  return 0;
}
