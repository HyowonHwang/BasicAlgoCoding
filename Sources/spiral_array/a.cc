#include <iostream>
#include <iomanip>


#define MAKE_NONCOPYABLE(classname) \
  classname(classname&); \
  classname& operator=(classname&);

//ScopePtr  Class
template <typename T>
class ScopePtr{
  public:
    ScopePtr(T* ptr = 0) : ptr_(ptr) {
    }
    virtual ~ScopePtr(){
      std::cout<<"Deconstruct" << std::endl;
      delete ptr_;
    }
    T& operator*() { return *ptr_;}
    T* operator->() { return ptr_;}

    T& operator[](int index) { return *(ptr_+index);}
    T* Get() { return ptr_;} 
  private:
    T* ptr_;
    MAKE_NONCOPYABLE(ScopePtr)
};

// 1. init array with input
// 2. get Next positoin
// 3. Valid position
// 4. print value

const unsigned int kMaxSzCol = 10;
const unsigned int kMaxSzCum = 10;

enum eDirection {
  PLUS_X_DELTA = 0,
  PLUS_Y_DELTA = 1,
  MINUS_X_DELTA = 2,
  MINUS_Y_DELTA = 3
};

int** InitArray( unsigned int width,
                 unsigned int height) {
  //Remind 64Bit sizeof(int*) = 8

  int **data_array = new int* [height];
  for(unsigned int line = 0; line < height ; line++) {
    data_array[line] = new int [width];
    for(unsigned int row = 0; row < width; row++) {
      data_array[line][row] = -1;
    }
  }
 return data_array; 
}
void ReleaseArray( int** array_,
                   unsigned int height) {
  //Remind 64Bit sizeof(int*) = 8

  for(unsigned int line = 0; line < height ; line++) {
    delete array_[line];
  }
  delete []array_;
}

void DisplaySpArray(int** sp_array,
                    unsigned int width,
                    unsigned int height) {
  for(unsigned int line =0 ; line < height; line++) {
    for(unsigned int row =0 ; row < width; row++) {
      std::cout << std::setw(5) << sp_array[line][row];
    }
    std::cout<<std::endl;
  }
}

void GetNextPosition(enum eDirection direction,
                     int current_x, int current_y,
                     int& next_x, int& next_y ) {

  next_x = current_x;
  next_y = current_y;

  switch(direction) {
    case PLUS_X_DELTA:
      next_x = current_x + 1; 
      break;
    case PLUS_Y_DELTA:
      next_y = current_y + 1;
      break;
    case MINUS_X_DELTA:
      next_x = current_x - 1;
      break;
    case MINUS_Y_DELTA:
      next_y = current_y - 1;
      break;
    default: //TODO(hyowon.hwang) : Add log class 
      std::cerr << "Invald Error" << std::endl;
      break;
  }
}

bool ValidNextPosition(enum eDirection& direction,
                        int** sp_array,int next_x, int next_y,
                        int& max_bound_row, int& max_bound_line,
                        int& min_bound_row,
                        const int input_width,
                        const int input_height) {
  bool ret = true;
  unsigned int ui4_direction = static_cast<unsigned int>(direction);
 
  if((0 <= next_x && next_x < input_width) &&
    (0 <= next_y && next_y < input_height) &&
    (-1 != sp_array[next_y][next_x])) {
    direction = static_cast<enum eDirection>((ui4_direction+1) % 4);
    return false;
  }

  if((next_x >= max_bound_row) &&
    (PLUS_X_DELTA == direction)) {
    max_bound_row--;
    ret = false;
    direction = static_cast<enum eDirection>((ui4_direction+1) % 4);
  } else if((next_y >= max_bound_line) &&
    (PLUS_Y_DELTA == direction)) {
    max_bound_line--;
    ret = false;
    direction = static_cast<enum eDirection>((ui4_direction+1) % 4);
  } else if((next_x < min_bound_row) &&
    (MINUS_X_DELTA == direction)) {
    min_bound_row++;
    ret = false;
    direction = static_cast<enum eDirection>((ui4_direction+1) % 4);
  }

  return ret;
}

int main(int argc, char *argv[]) {
  unsigned int count = 0;
  unsigned int failed_count = 0;
  int input_width_ = 5;
  int input_height_ = 5;

  int cus_x_ = -1;
  int cus_y_ = 0;
  int next_x_ = -1;
  int next_y_ = 0;
  int count_value_ = 0; // Increase Mono
  int max_bound_row_ = input_width_;
  int max_bound_line_ = input_height_; 
  int min_bound_row_ = 0;

  enum eDirection direction_ = PLUS_X_DELTA;
  bool done_ = false;

  int **sp_array_ = InitArray(input_width_, input_height_);
  //(sp_array_[3])[0] = 99;
  while(!done_) {
    GetNextPosition(direction_,
        cus_x_, cus_y_,
        next_x_, next_y_);

    if(ValidNextPosition(direction_, 
          sp_array_, next_x_, next_y_,
          max_bound_row_, max_bound_line_,
          min_bound_row_,
          input_width_,
          input_height_)) {
      sp_array_[next_y_][next_x_] = count_value_++;
      cus_x_ = next_x_;
      cus_y_ = next_y_;
      failed_count = 0;
    } else {
      failed_count++;
      if(failed_count >=2)
        done_ = true;
    }

    std::cout << "cus_x :" << cus_x_ << " cus_y :" << cus_y_
      << " next_x_ : " << next_x_ << " next_y_ : " << next_y_
      << " direction : " << direction_ << std::endl; 
    count++;
  }

  DisplaySpArray(sp_array_, input_width_, input_height_); 
  ReleaseArray(sp_array_, input_height_);
  return 0;
}
