#include "../ctci.h"

using namespace std;

struct Animal{
  Animal(string _tag, string _name)
  : tag(_tag), name(_name) {}
  string tag;
  string name;  
};

class AnimalShelter{
public:
  void enqueue(Animal animal){
    m_q.push_back(animal);
  }
  Animal dequeAny(){
    if (!m_q.empty()){
      Animal res = m_q.front();
      m_q.pop_front();
      return res;
    }else{
      throw exception();
    }
  }
  Animal dequeDog(){
    list<Animal>::iterator iter = m_q.begin();
    while (iter != m_q.end()){
      if (iter->tag == "dog"){
        break;
      }
      ++iter;
    }
    if (iter == m_q.end()){
      throw exception();
    }
    Animal res = *iter;
    m_q.erase(iter);
    return res;
  }
  Animal dequeCat(){
    list<Animal>::iterator iter = m_q.begin();
    while (iter != m_q.end()){
      if (iter->tag == "cat"){
        break;
      }
      ++iter;
    }
    if (iter == m_q.end()){
      throw exception();
    }
    Animal res = *iter;
    m_q.erase(iter);
    return res;
  }

private:
 list<Animal> m_q;
};

int main(){
  AnimalShelter as;
  as.enqueue(Animal("cat", "c1"));
  as.enqueue(Animal("cat", "c2"));
  as.enqueue(Animal("dog", "d1"));
  as.enqueue(Animal("cat", "c3"));
  as.enqueue(Animal("dog", "d2"));
  as.enqueue(Animal("dog", "d3"));
  as.enqueue(Animal("cat", "c4"));
  as.enqueue(Animal("dog", "d4"));
  as.enqueue(Animal("dog", "d5"));
  as.enqueue(Animal("cat", "c5"));
  Animal a = as.dequeAny();
  cout << a.name << endl;
  a = as.dequeDog();
  cout << a.name << endl;
  a = as.dequeDog();
  cout << a.name << endl;
  a = as.dequeAny();
  cout << a.name << endl;
  a = as.dequeCat();
  cout << a.name << endl;
  a = as.dequeCat();
  cout << a.name << endl;
  return 0;
}
