#include "hello_world_impl.hpp"
#include <chrono>
#include <ctime>
#include <string>
  
namespace helloworld {
  
    std::shared_ptr<HelloWorld> HelloWorld::create() {
        return std::make_shared<HelloWorldImpl>();
    }
  
    HelloWorldImpl::HelloWorldImpl() {
  
    }
  
    std::string HelloWorldImpl::get_hello_world() {
  
        // get the current date/time using std::chrono
        std::chrono::time_point<std::chrono::system_clock> now;
        now = std::chrono::system_clock::now();
        time_t time = std::chrono::system_clock::to_time_t(now);
         
        // generate our string
        std::string myString = "Hello World! ";
        myString += std::ctime(&time);
  
        return myString;
  
    }
  
}