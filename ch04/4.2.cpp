#include "../stl/header/Graph.hpp"
#include <iostream>
#include <utility>

using namespace std;

template<class T>
bool dfs(DirectedGraph<T>& g, Gnode<T>* start, Gnode<T>* end){
  for (int i = 0; i < start->adjacents.size(); ++i){
    if (start->adjacents[i]->visited == false){
      start->adjacents[i]->visited = true;
      if (start->adjacents[i] == end){
        return true;
      }
      if (dfs(g, start->adjacents[i], end) == true){
        return true;
      }
    }
  }
  return false;
}

template<class T>
bool findPath(DirectedGraph<T>& g, T start, T end){
  Gnode<T>* s = g.findNode(start);
  Gnode<T>* e = g.findNode(end);
  if (s == NULL or e == NULL){
    return false;
  }
  bool res = dfs(g, s, e);
  for (int i = 0; i < g.m_graph.size(); ++i){
   g.m_graph[i]->visited = false;
  } 
  return res;
}

int main(){
  DirectedGraph<int> graph;
  graph.insertEdge(make_pair(1, 2));
  graph.insertEdge(make_pair(2, 3));
  graph.insertEdge(make_pair(3, 4));
  graph.insertEdge(make_pair(4, 2));
  graph.insertEdge(make_pair(1, 5));
  graph.insertEdge(make_pair(6, 5));
  
  if (findPath(graph, 4, 3) == true){
    cout << "the graph contains this route." << endl;
  }else{
    cout << "the graph doesn't contain this route." << endl;
  }

  return 0;
}
