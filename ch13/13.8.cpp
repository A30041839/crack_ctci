/*A thread-safe smart pointer
 */
#include <iostream>
#include <mutex>

using namespace std;

class _referenceCounter{
private:
  int count;
  mutex mtx;
public:
  explicit _referenceCounter(): count(0) {}
  void increase(){
    mtx.lock();
    count++;
    mtx.unlock();
  }
  
  int decrease(){
    mtx.lock();
    count--;
    mtx.unlock();
    return count;
  }
};
  
template<class T>
class SmartPointer{
private:
  T* pointer;
  _referenceCounter* rc;

public:
  //constructors
  SmartPointer(): pointer(0), rc(0){}
  SmartPointer(T* ptr): pointer(ptr), rc(0){
    rc = new _referenceCounter();
    rc->increase();
  }
  SmartPointer(const SmartPointer& sp): pointer(sp.pointer), rc(sp.rc){
     rc->increase();
  }
  
  SmartPointer& operator=(const SmartPointer& sp){
    if (this != &sp){
      if (rc != NULL and rc->decrease() == 0){
        delete pointer;
        delete rc;
      }
      pointer = sp.pointer;
      rc = sp.rc;
      rc->increase();
    }
    return *this;
  }
  T* operator->() const{
    return pointer;
  }
  T& operator*() const{
    return *pointer;
  }

  //destructor
  ~SmartPointer(){
    if (rc != NULL and rc->decrease() == 0){
      delete pointer;
      delete rc;
    }
  }
};

struct cls{
  void foo(){
    cout << "hey" << endl;
  }
  ~cls(){ cout << "I'm being cleaned!" << endl; }
};

int main(){
  SmartPointer<cls> sp1(new cls());
  {
    SmartPointer<cls> sp2 = sp1;
    sp2->foo();
    SmartPointer<cls> sp3;
    sp3 = sp1;
    sp3->foo();
  }
  sp1->foo();
    
  return 0;
}
