#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-5;

class line{
public:
  double slope;
  double yintercept;
  explicit line(double _slope, double _yintercept)
    : slope(_slope), yintercept(_yintercept) {}
};

bool intersect(line a, line b){
  return (abs(a.slope - b.slope) > EPS || abs(a.yintercept - b.yintercept) < EPS); 
}

int main(){
  line a(-1, 2);
  line b(-1.5, 2);
  if (intersect(a, b) == true){
    cout << "the two lines intersects." << endl;
  }else{
    cout << "the two line doesn't intersect." << endl;
  }
  return 0;
}
