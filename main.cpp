#include "loger.h"
#include <thread>
#include <iostream>


void myFunction(int threadId)
{
    Loger* log = Loger::getInstance();

    for(int i = 0; i < 100; i++)
    {
        log->log("From thread " + std::to_string(threadId) + " id " + std::to_string(i));
    }
}
int main()
{
    std::vector<std::thread> threads;
    for(int i = 0; i < 3; ++i)
    {
        threads.emplace_back(myFunction, i);   
    }
    for(auto& thread : threads)
    {
        thread.join();
    }

    return 0;
}