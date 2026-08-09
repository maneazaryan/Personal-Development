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
    m_logCount++;
    m_logMessages.emplace_back(std::to_string(m_logCount) + ": " + message);
}

void Loger::printLogs()
{
    for (const auto& msg : m_logMessages)
    {
        std::cout << msg << std::endl;
    }
}