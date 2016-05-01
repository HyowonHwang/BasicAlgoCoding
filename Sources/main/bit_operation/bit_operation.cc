#include <iostream>

/*
 * Refer to bit operation in kernel source
 *
*/
static unsigned long __ffs(unsigned long word)
{
	int num = 0;

	if ((word & 0xffffffff) == 0) {
		num += 32;
		word >>= 32;
	}
	if ((word & 0xffff) == 0) {
		num += 16;
		word >>= 16;
	}
	if ((word & 0xff) == 0) {
		num += 8;
		word >>= 8;
	}
	if ((word & 0xf) == 0) {
		num += 4;
		word >>= 4;
	}
	if ((word & 0x3) == 0) {
		num += 2;
		word >>= 2;
	}
	if ((word & 0x1) == 0)
		num += 1;
	return num;
}
#if 0
int main(){
  unsigned long mask = 0x1000000000000000;
  unsigned long find_bit = 0 ;
  
  if(mask != 0)
    find_bit = __ffs(mask);

  std::cout << "unsigned long size : " << sizeof(unsigned long) << std::endl;
  std::cout << "ffs :" << find_bit << std::endl;
  return 0;
}
#endif
