#include "loger.h"
#include <iostream>

Loger* Loger::getInstance()
{
    static Loger instance;
    return &instance;
}

void Loger::log(const std::string& message)
{
   std::lock_guard<std::mutex> lock(m_mutex);
   std::cout << message << std::endl;
}
