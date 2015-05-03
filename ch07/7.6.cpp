#include "../ctci.h"

using namespace std;

typedef pair<double, double> point;
const double EPS = 1e-5;

class line{
public:
  double slope;
  double yintercept;
  explicit line(double _slope, double _yintercept)
    : slope(_slope), yintercept(_yintercept) {}
};

void selectPoint(int n, int k, int j, vector<int>& tmp, vector<vector<int > >& res){
  if (j == n){
    int sum = 0;
    vector<int> v;
    for (int i = 0; i < n; ++i){
      sum += tmp[i];
      if (tmp[i] == 1){
        v.push_back(i);
      }
    }
    if (sum == k){
      res.push_back(v);
    }
    return;
  }
  tmp[j] = 0;
  selectPoint(n, k, j + 1, tmp, res);
  tmp[j] = 1;
  selectPoint(n, k, j + 1, tmp, res);
}

pair<line, int> lineCrossMostPoints(vector<point>& points){
  for (int k = points.size(); k > 2; k--){
    vector<int> tmp(points.size(), 0);
    vector<vector<int> > res;
    selectPoint(points.size(), k, 0, tmp, res);
    for (int j = 0; j < res.size(); ++j){
      bool f = true;
      point& a = points[res[j][0]];
      point& b = points[res[j][1]];
      double slope = (b.second - a.second) / (b.first - a.first);
      for (int m = 2; m < res[j].size(); ++m){
        point& c = points[res[j][m]];
        if (abs(slope - (c.second - a.second) / (c.first - a.first)) > EPS){
          f = false;
          break;
        }
      }
      if (f){
        return pair<line, int>(line(slope, a.second - a.first * slope), k);
      }
    }
  }
  point& a = points[0];
  point& b = points[1];
  double slope = (b.second - a.second) / (b.first - a.first);
  return pair<line, int>(line(slope, a.second - a.first * slope), 2);
}

int main(){
  vector<point> points;
  points.push_back(point(0,0));
  points.push_back(point(1,1));
  points.push_back(point(1,3));
  points.push_back(point(2,0));  
  points.push_back(point(2,2));
  points.push_back(point(3,1));
  points.push_back(point(3,3));

  pair<line, int> res = lineCrossMostPoints(points);
  cout << "The line y=" << res.first.slope << "x+" << res.first.yintercept << " crosses "
    << res.second << " points" << endl;
  return 0;
}
