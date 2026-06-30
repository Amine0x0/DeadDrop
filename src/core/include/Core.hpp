#ifndef CORE_HPP
#define CORE_HPP

#include <string>
#include <iostream>

//group free function here :3
// ----------------------------------- //
namespace tooling {
    void ping();
    void log(LOG_MODE mode, std::string message);
}

// ------------------------------------- //
enum class LOG_MODE {
    ERR,
    STDOUT,
    FILE
};



#endif