#include<iostream>
#include<thread>
#include<mutex>
void hello(){
    int c;
    std::cout << "hello word!" << std::endl;
}
int main(){
    std::thread t(hello);
    t.join();
    return 0;
}