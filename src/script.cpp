#include <iostream>
#include <functional>
#include <cstring>
#include <memory>
#include <string>

using Callback = std::function<void(const std::string&)>;

class MyClass {
 private:
  Callback callback = [](const std::string& message) {
    std::cout << "[C++]: Default Callback" << std::endl;
  };

 public:
  void setCallback(Callback callback) { this->callback = callback; }
  void runCallback() { 
    this->callback("Inside of lambda");
  }
};

extern "C" {

MyClass* myClass = nullptr;

void create() { myClass = new MyClass(); }

void setCallback(const char* (*cCallback)(const char*)) {
  myClass->setCallback([cCallback](const std::string& message) {
    const char* cMessage = message.c_str();
    const char* cResponse = cCallback(cMessage);
    if (cResponse == nullptr) {
      std::cout << "[C++]: Error! cResponse is nullptr" << std::endl;
    }
    
    std::cout << "[C++]:" << cResponse << std::endl;
  });
}

void runCallback() { myClass->runCallback(); }
}