#include "loger.h"
#include <thread>
#include <vector>
#include <iostream>
#include <mutex>

std::mutex inputMutex;

void myFunction(int threadId)
{
    inputMutex.lock();
    std::string text;
    Loger* log = Loger::getInstance();
    for(int i = 0; i < 2; ++i)
    {
        std::cin >> text;
        log->log(text +" from thread " + std::to_string(threadId));
    }
    inputMutex.unlock();
}
int main()
{
    Loger* log = Loger::getInstance();
    std::vector<std::thread> threads;
    for(int i = 0; i < 3; ++i)
    {
        threads.emplace_back(myFunction, i);   
    }
    for(auto& thread : threads)
    {
        thread.join();
    }
    log->printLogs();

    return 0;
}