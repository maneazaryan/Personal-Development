#include <atomic>
#include <string>
#include <vector>
#include <mutex>

class Loger
{
    private:
        std::mutex m_mutex;

    private:
        Loger() {};

    public:
        static Loger* getInstance();
        void log(const std::string& message);
};