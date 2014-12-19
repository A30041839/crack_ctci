#include <iostream>
#include <mutex>

class singleton{
private:
  static singleton* _instance;
  static std::mutex mtx;
  singleton() {}

public:
  static singleton* get_instance(){
    if (_instance == NULL){
      mtx.lock();
      if (_instance == NULL){
        _instance = new singleton();
      }
      mtx.unlock();
    }
    return _instance;
  }
};

singleton* singleton::_instance = NULL;
std::mutex singleton::mtx;

int main(){
  singleton* a = singleton::get_instance();
  singleton* b = singleton::get_instance();
  std::cout << a << "," << b << std::endl;
  return 0;
}

    

