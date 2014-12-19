#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

const double EPS = 1e-5;
typedef pair<double, double> point;

class line{
public:
  double slope;
  double yintercept;
  explicit line(double _slope, double _yintercept)
    : slope(_slope), yintercept(_yintercept) {}
};
struct square{
  explicit square(point c, double len)
    : center(c), length(len) {}
  point center;
  double length;
};

//the line connecting the centers of two
//squares exactly split them into two equal halves

line splitSquare(square& a, square& b){
  point& c1 = a.center;
  point& c2 = b.center;
  if (abs(c1.first - c2.first) < EPS and abs(c1.second - c2.second) < EPS){
    return line(0, c1.second);
  }
  double slope = (c1.second - c2.second) / (c1.first - c2.first);
  double yintercept = c1.second - slope * c1.first;
  return line(slope, yintercept);
}

int main(){
  square a(point(1,1), 2);
  //square b(point(2,-2), 3);
  square b(point(1,1), 4);
  line cut = splitSquare(a, b);
  cout << "the splitting line is y=" << cut.slope << "x+" << cut.yintercept << endl;
  return 0;
}
