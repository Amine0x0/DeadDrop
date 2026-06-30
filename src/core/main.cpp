#include <Core.hpp>

namespace tooling{
    void ping();
}

void tooling::ping(){
    std::cout << "pong!" << std::endl;
}

int main(){
    {
        tooling::ping();
        return (0);
    }
}