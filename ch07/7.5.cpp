#include "../ctci.h"

using namespace std;

const double EPS = 1e-5;

//assuming the origin is at the left-bottom cornor
struct point {
  double x;
  double y;
  point(): x(0), y(0) {}
  explicit point(double _x, double _y): x(_x), y(_y) {}
};

struct lineSegment{
  point start;
  point end;
  explicit lineSegment(point _start, point _end) {
    this->start.x = _start.x;
    this->start.y = _start.y;
    this->end.x = _end.x;
    this->end.y = _end.y;
  }
};

struct square{
  double length;
  point center;

  explicit square(point a, point b) {
    this->length = fabs(a.x - b.x);
    this->center.x = (a.x + b.x) / 2;
    this->center.y = (a.y + b.y) / 2;
  }

  pair<point, point> intersect(point& mid1, point& mid2, double len1) {
    if (fabs(mid1.x - mid2.x) < EPS) {
      point a(mid1.x, mid1.y + len1 / 2);
      point b(mid1.x, mid1.y - len1 / 2);
      return {a, b};
    }
    double slope = (mid1.x - mid2.x) / (mid1.y - mid2.y);
    if (fabs(slope) < EPS) {
      point a(mid1.x - len1 / 2, mid1.y);
      point b(mid1.x + len1 / 2, mid1.y);
      return {a, b};
    }else if (fabs(fabs(slope) - 1) < EPS) {
      point a(mid1.x + len1 / slope / 2, mid1.y + len1 / 2);
      point b(mid1.x - len1 / slope / 2, mid1.y - len1 / 2);
      return {a, b};
    }else if ((slope < 0 and slope > -1) or (slope > 0 and slope < 1)) {
      point a(mid1.x - len1 / 2, mid1.y - slope * len1 / 2);
      point b(mid1.x + len1 / 2, mid1.y + slope * len1 / 2);
      return {a, b};
    }else if (slope < -1 or slope > 1) {
      point a(mid1.x + len1 / slope / 2, mid1.y + len1 / 2);
      point b(mid1.x - len1 / slope / 2, mid1.y - len1 / 2);
      return {a, b};
    }
  }

  lineSegment split(square& other) {
    auto pair1 = intersect(this->center, other.center, this->length);
    auto pair2 = intersect(other.center, this->center, other.length);
    point& p1 = pair1.first.x < pair1.second.x ? pair1.first : pair1.second;
    point& p2 = pair2.first.x < pair2.second.x ? pair2.first : pair2.second;
    point& start = p1.x < p2.x ? p1 : p2;
    point& p3 = pair1.first.x > pair1.second.x ? pair1.first : pair1.second;
    point& p4 = pair2.first.x > pair2.second.x ? pair2.first : pair2.second;
    point& end = p3.x > p4.x ? p3 : p4;
    return lineSegment(start, end);
  }
};

int main(){
  square s1(point(0, 1), point(2, 3));
  square s2(point(1, 2), point(4, 5));
  lineSegment l = s1.split(s2);
  printf("the start point is (%f,%f), the end point is (%f,%f)\n",
    l.start.x, l.start.y, l.end.x, l.end.y);
  return 0;
}
