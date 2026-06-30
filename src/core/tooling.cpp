#include <Core.hpp>


#define CLI_MODE 1 //for now

//implementation
void tooling::ping(){
    std::cout << "pong!" << std::endl;
}

#include <fstream>
void log(LOG_MODE mode, std::string message) {
    switch(mode) {
        case LOG_MODE::STDOUT:
            std::cout << "[INFO] " << message << std::endl;
            break;
        case LOG_MODE::ERR:
            std::cerr << "[ERROR] " << message << std::endl;
            break;
        case LOG_MODE::FILE: {
            std::ofstream logFile("deaddrop.log", std::ios::app);
            if (logFile.is_open()) {
                logFile << "[LOG] " << message << std::endl;
                logFile.close();
            }
            break;
        }
    }
}