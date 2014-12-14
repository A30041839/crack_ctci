#include <iostream>
#include <vector>

using namespace std;

void printbyte(unsigned char byte){
  int i = 7;
  while (i >= 0){
    cout << ((byte & (1 << i)) >> i); 
    i--;
  }
}

void drawHorizontalLine(vector<unsigned char>& screen, int width, int x1, int x2, int y){
  int start_pixel = y * width + x1;
  int end_pixel = start_pixel + x2 - x1;
  int start_byte =  start_pixel >> 3;
  int start_byte_pos = start_pixel % 8;
  int end_byte = end_pixel >> 3;
  int end_byte_pos = end_pixel % 8;

  screen[start_byte] = ~0;
  screen[start_byte] = screen[start_byte] >> start_byte_pos;
  if (start_byte != end_byte){
    screen[end_byte] = ~0;
  }
  screen[end_byte] = screen[end_byte] & (~0 << (7 - end_byte_pos));
  for (int k = start_byte + 1; k < end_byte; k++){
    screen[k] = ~0;
  }
  for (int i = 0; i < screen.size(); i++){
    printbyte(screen[i]);
    if ((i + 1) % (width >> 3) == 0){
      cout << endl;
    }
  }
}

int main(){
  vector<unsigned char> screen(16, 0);
  drawHorizontalLine(screen, 32, 2, 10, 2);
  return 0;
}
