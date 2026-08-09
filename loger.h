#include <atomic>
#include <string>
#include <vector>
#include <mutex>

class Loger
{
    private:
        std::atomic_int m_logCount = 0;
        std::vector<std::string> m_logMessages;
        std::mutex m_mutex;

    private:
        Loger() {};

    public:
        static Loger* getInstance();
        void log(const std::string& message);
        void printLogs();
};