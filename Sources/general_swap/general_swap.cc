void generalSwap(void* src, void* dst, int size) {
  char t;
  do {
    t = *(char*)src;
    *(char*)src++ = *(char*)dst;
    *(char*)dst++ = t;
  } while(--size > 0);
}
