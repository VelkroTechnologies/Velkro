#pragma once

#include <ctime>
#include <sstream>

#include <cstdarg>

namespace Velkro
{
    class Log
    {
    public:
        static void Trace(const char* format, ...)
        {
            std::string level = "[trace] ";

            va_list arg;
            int done;

            va_start(arg, format);
            done = vfprintf(stdout, std::string(GetTimeStamp() + " " + level + " " + format + '\n').c_str(), arg);
            va_end(arg);
        }
        static void Debug(const char* format, ...)
        {
            std::string level = "\033[0m[\033[1;34mdebug\033[0m] ";

            va_list arg;
            int done;

            va_start(arg, format);
            done = vfprintf(stdout, std::string(GetTimeStamp() + " " + level + " " + format + '\n').c_str(), arg);
            va_end(arg);
        }
        static void Info(const char* format, ...)
        {
            std::string level = "\033[0m[\033[1;32minfo\033[0m] ";

            va_list arg;
            int done;

            va_start(arg, format);
            done = vfprintf(stdout, std::string(GetTimeStamp() + " " + level + " " + format + '\n').c_str(), arg);
            va_end(arg);
        }
        static void Warn(const char* format, ...)
        {
            std::string level = "\033[0m[\033[1;33mwarn\033[0m] ";

            va_list arg;
            int done;

            va_start(arg, format);
            done = vfprintf(stdout, std::string(GetTimeStamp() + " " + level + " " + format + '\n').c_str(), arg);
            va_end(arg);
        }
        static void Error(const char* format, ...)
        {
            std::string level = "\033[0m[\033[1;31merror\033[0m] ";

            va_list arg;
            int done;

            va_start(arg, format);
            done = vfprintf(stdout, std::string(GetTimeStamp() + " " + level + " " + format + '\n').c_str(), arg);
            va_end(arg);
        }
        static void Fatal(const char* format, ...)
        {
            std::string level = "\033[0m[\033[1;41mfatal\033[0m] ";

            va_list arg;
            int done;

            va_start(arg, format);
            done = vfprintf(stdout, std::string(GetTimeStamp() + " " + level + " " + format + '\n').c_str(), arg);
            va_end(arg);

            exit(1);
        }

    private:
        static std::string GetTimeStamp()
        {
            time_t now = time(0);

            tm *ltm = localtime(&now);

            std::stringstream time;
            
            time << ltm->tm_hour << ":";
            time << ltm->tm_min << ":";
            time << ltm->tm_sec;

            return "[" + time.str() + "]";
        }
    };
}

#define VLK_TRACE(...)  Log::Trace(__VA_ARGS__)
#define VLK_DEBUG(...)  Log::Debug(__VA_ARGS__)
#define VLK_INFO(...)   Log::Info(__VA_ARGS__)
#define VLK_WARN(...)   Log::Warn(__VA_ARGS__)
#define VLK_ERROR(...)  Log::Error(__VA_ARGS__)
#define VLK_FATAL(...)  Log::Fatal(__VA_ARGS__)