#ifndef LOG_H
#define LOG_H

#include <memory>
#include <spdlog/spdlog.h>

#include <nixalis/Core/Core.h>

//==================LOGGING MACROS==================//
#define INFO(...)  Nixalis::Log::returnEngineLogger()->info(__VA_ARGS__)
#define TRACE(...)  Nixalis::Log::returnEngineLogger()->trace(__VA_ARGS__)
#define DEBUG(...)  Nixalis::Log::returnEngineLogger()->debug(__VA_ARGS__)
#define WARN(...)  Nixalis::Log::returnEngineLogger()->warn(__VA_ARGS__)
#define ERROR(...)  Nixalis::Log::returnEngineLogger()->error(__VA_ARGS__)
#define CRITICAL(...)  Nixalis::Log::returnEngineLogger()->critical(__VA_ARGS__)

#define APP_INFO(...)  Nixalis::Log::returnApplicationLogger()->info(__VA_ARGS__)
#define APP_TRACE(...)  Nixalis::Log::returnApplicationLogger()->trace(__VA_ARGS__)
#define APP_DEBUG(...)  Nixalis::Log::returnApplicationLogger()->debug(__VA_ARGS__)
#define APP_WARN(...)  Nixalis::Log::returnApplicationLogger()->warn(__VA_ARGS__)
#define APP_ERROR(...)  Nixalis::Log::returnApplicationLogger()->error(__VA_ARGS__)
#define APP_CRITICAL(...)  Nixalis::Log::returnApplicationLogger()->critical(__VA_ARGS__)

namespace Nixalis
{
    class Log
    {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger> returnEngineLogger() { return s_Engine; }
        static std::shared_ptr<spdlog::logger> returnApplicationLogger() { return s_Application; }
    private:
        static std::shared_ptr<spdlog::logger> s_Engine;
        static std::shared_ptr<spdlog::logger> s_Application;
    };
}



#endif //LOG_H
