#include "../ctci.h"

using namespace std;

struct Animal{
  explicit Animal(string _tag, string _name)
  : tag(_tag), name(_name) {}
  string tag;
  string name;  
  int order;

  bool isOlderthan(const Animal& other) const {
    return this->order < other.order;
  }
};

//use a single queue to store two kinds of animals,
//time complexity is bad when dequeue a specific kind
//of animal
class AnimalShelter1{
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

//use two separate queues to store different kinds
//of animals, use a timestamp variable to determine
//the enqueue time of an animal
class AnimalShelter2{
public:
  void enqueue(Animal animal){
    animal.order = m_time_stamp++;
    if (animal.tag == "cat") {
      m_cats.push(animal);
    }else if (animal.tag == "dog") {
      m_dogs.push(animal);
    }
  }

  Animal dequeAny(){
    if (m_dogs.empty()) {
      return dequeCat();
    }else if (m_cats.empty()) {
      return dequeDog();
    }
    Animal cat = m_cats.front();
    Animal dog = m_dogs.front();
    if (cat.isOlderthan(dog)) {
      m_cats.pop();
      return cat;
    }else {
      m_dogs.pop();
      return dog;
    }
  }

  Animal dequeDog(){
    if (!m_dogs.empty()) {
      Animal res = m_dogs.front();
      m_dogs.pop();
      return res;
    }else {
      throw exception();
    }
  }

  Animal dequeCat() {
    if (!m_cats.empty()) {
      Animal res = m_cats.front();
      m_cats.pop();
      return res;
    }else {
      throw exception();
    }
  }

private:
 queue<Animal> m_cats;
 queue<Animal> m_dogs;
 unsigned int m_time_stamp = 1;
};


int main(){
  AnimalShelter2 as;
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
