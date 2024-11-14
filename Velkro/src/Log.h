#pragma once

#include <iostream>
#include <vector>
#include <any>
#include <stdexcept>
#include <typeinfo>

#ifdef VLK_DEVELOPMENT
    #undef VLK_DEVELOPMENT
    #define VLK_DEVELOPMENT true
#else
    #undef VLK_DEVELOPMENT
    #define VLK_DEVELOPMENT false
#endif

namespace Velkro::Log
{
    enum Level
    {
        DEBUG, INFO, WARN, ERROR, FATAL
    };

    template<typename... Args>
    void Print(bool core, Level lvl, std::string str)
    {
        if ((lvl == DEBUG && VLK_DEVELOPMENT) || lvl != DEBUG)
        {
            switch (lvl)
            {
            case DEBUG:
                std::cout << "[\x1b[36mdebug\033[0m] ";
                break;
            case INFO:
                std::cout << "[\x1b[32minfo\033[0m] ";
                break;
            case WARN:
                std::cout << "[\x1b[33mwarn\033[0m] ";
                break;
            case ERROR:
                std::cout << "[\x1b[31merror\033[0m] ";
                break;
            case FATAL:
                std::cout << "[\x1b[41mfatal\033[0m] ";
                break;
            }

            if (core)
            {
                std::cout << "CORE: ";
            }
            else
            {
                std::cout << "CLIENT: ";
            }

            std::cout << str << '\n';
        }
    }
}

#define VLK_DEBUG(...)     Velkro::Log::Print(false, Velkro::Log::DEBUG, __VA_ARGS__)
#define VLK_INFO(...)      Velkro::Log::Print(false, Velkro::Log::INFO, __VA_ARGS__)
#define VLK_WARN(...)      Velkro::Log::Print(false, Velkro::Log::WARN, __VA_ARGS__)
#define VLK_ERROR(...)     Velkro::Log::Print(false, Velkro::Log::ERROR, __VA_ARGS__)
#define VLK_FATAL(...)     Velkro::Log::Print(false, Velkro::Log::FATAL, __VA_ARGS__)

#define VLK_CORE_DEBUG(...)     Velkro::Log::Print(true, Velkro::Log::DEBUG, __VA_ARGS__)
#define VLK_CORE_INFO(...)      Velkro::Log::Print(true, Velkro::Log::INFO, __VA_ARGS__)
#define VLK_CORE_WARN(...)      Velkro::Log::Print(true, Velkro::Log::WARN, __VA_ARGS__)
#define VLK_CORE_ERROR(...)     Velkro::Log::Print(true, Velkro::Log::ERROR, __VA_ARGS__)
#define VLK_CORE_FATAL(...)     Velkro::Log::Print(true, Velkro::Log::FATAL, __VA_ARGS__)