#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Nixalis
{
    std::shared_ptr<spdlog::logger> Log::s_Engine;
    std::shared_ptr<spdlog::logger> Log::s_Application;

    void Log::Init()
    {
        std::vector<spdlog::sink_ptr> sinks{
            std::make_shared<spdlog::sinks::stdout_color_sink_mt>(),
            std::make_shared<spdlog::sinks::basic_file_sink_mt>("Log.txt"),
        };
        s_Engine = std::make_shared<spdlog::logger>("Nixalis Engine", begin(sinks), end(sinks));
        s_Engine->set_pattern("[%Y-%m-%d %X %n(Log) threadid_%t] [%^%l%$] : %v");
        s_Application = std::make_shared<spdlog::logger>("Application", begin(sinks), end(sinks));
        s_Application->set_pattern("[%Y-%m-%d %X %n(Log) threadid_%t] [%^%l%$] : %v");

        INFO("{} Logger Initialized", s_Engine->name());
        INFO("{} Logger Initialized", s_Application->name());
    }
}
