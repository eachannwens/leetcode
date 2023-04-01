
#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork() {

    while (!s_Finished) {
        /*
            199711L: C++98/03
            201103L: C++11
            201402L: C++14
            201703L: C++17
            202002L: C++20
        */
        std::cout << __cplusplus << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {

    std::thread worker(DoWork);

    std::cin.get();
    s_Finished = true;

    worker.join();
    std::cout << "Finished." << std::endl;
    
    std::cin.get();
}
