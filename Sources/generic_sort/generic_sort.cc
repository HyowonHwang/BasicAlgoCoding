#include <iostream>

// Toggle intergers(char, int , long)
#define SWAP_INT(a,b) ((a != b)?(a ^=b ^=a ^=b) :1)

inline void generalSwap(void* src, void* dst, int size) {
  char t;
  char *pSrc = static_cast<char*>(src);
  char *pDst = static_cast<char*>(dst);

  do {
    t = *pSrc;
    *pSrc++ = *pDst;
    *pDst++ = t;
  } while(--size > 0); 
}

/*
* 1. Start easily with bubbleSort 
*     O(n^2)
*/
static const int kMaxDataArraySize = 10;

void bubbleSortInterger(int *a, int n) {
  int i;
  int j;

  for(i = 0; i < n-1; i++) {
    for(j = 0; j < n-i-1; j++) {
      if(a[j] > a[j+1]) 
        SWAP_INT(a[j], a[j+1]);
    }
  }
}

void generalbubbleSortInterger(void *data,int n, int size,
                               int (*cmp)(const void*, const void*)) {

  int i;
  int j;

  for(i = 0; i < n-1; i++) {
    for(j = 0; j < n-i-1; j++) {
      if(cmp(static_cast<char*>(data)+j*size,
             static_cast<char*>(data)+ (j+1)*size) > 0) {
        generalSwap(static_cast<char*>(data)+j*size,
            static_cast<char*>(data)+ (j+1)*size,
            size);
      }
    }
  }
}

/*  
 * 2. MergeSort 
*     O(log^n)
 */
static void merge(int *data, int startIndex, int midIndex, int endIndex) {
  if(!data)
    return;

  int target_len = endIndex-startIndex+1;
  int* new_data = new int[target_len];
  int dst_index = 0;
  int iterator_1 = 0;

  int left_index = startIndex;
  int right_index = midIndex+1;
  int iterator_2 = 0; 

  while(left_index <= midIndex && right_index <= endIndex) {
    if(data[left_index] < data[right_index]) {
      new_data[dst_index] =  data[left_index];
      left_index++;
    } else {
      new_data[dst_index] =  data[right_index];
      right_index++;
    }
    dst_index++;
  }

  while(left_index <= midIndex) {
   new_data[dst_index++] = data[left_index++];
  }

  while(right_index <= endIndex) {
   new_data[dst_index++] = data[right_index++];
  }

  for(iterator_1 = 0, iterator_2 = startIndex;
      iterator_1 < target_len; iterator_1++, iterator_2++) {
    data[iterator_2] = new_data[iterator_1];
  }

  delete []new_data;
}

void mergeSortInterger(int *data, int startIndex, int endIndex) {
  if(!data || startIndex >= endIndex)
    return;
  // (3 + 7) / 2  = 5 
  int midIndex = (startIndex+endIndex) /2;

  mergeSortInterger(data, startIndex, midIndex);
  mergeSortInterger(data, midIndex+1, endIndex);
  merge(data, startIndex, midIndex, endIndex);
}

void displayInterArray(int *data, int n) {
  int i;
  int j;

  for(i = 0; i <n ; i++) {
    std::cout<<"["<<data[i]<<"] "<< std::endl;
  }
}

inline int interger_asc(const void* num1, const void* num2) {
  int* pNum1 = static_cast<int*>(const_cast<void*>(num1));
  int* pNum2 = static_cast<int*>(const_cast<void*>(num2));
  return *pNum1 - *pNum2; 
}

inline int interger_desc(const void* num1, const void* num2) {
  int* pNum1 = static_cast<int*>(const_cast<void*>(num1));
  int* pNum2 = static_cast<int*>(const_cast<void*>(num2));
  return *pNum2 - *pNum1; 
}

int main() {
  int a[kMaxDataArraySize] = {9, 7, 2, 3, 0, 5, 6, 1, 8, 4};
  int a1[kMaxDataArraySize] = {9, 7, 2, 3, 0, 5, 6, 1, 8, 4};
  int a2[kMaxDataArraySize] = {9, 7, 2, 3, 0, 5, 6, 1, 8, 4};
  int num1 = 3;
  int num2 = 4;

  std::cout<<"bubbleSort" << std::endl;
  bubbleSortInterger(a, kMaxDataArraySize);
  displayInterArray(a, kMaxDataArraySize);

  std::cout<<"MergeSort" << std::endl;
  mergeSortInterger(a1, 0, kMaxDataArraySize-1);
  displayInterArray(a1, kMaxDataArraySize);

  std::cout<<"GeneralSwap" << std::endl;
  generalSwap(&num1, &num2, sizeof(int));
  std::cout << "a = " << num1 << " b= " << num2 << std::endl;

  std::cout<<"GeneralBubbleSort" << std::endl;
  generalbubbleSortInterger(a2, kMaxDataArraySize, sizeof(int), interger_desc);
  displayInterArray(a2, kMaxDataArraySize);

  return 0;
}
