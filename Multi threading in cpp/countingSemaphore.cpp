// to run the code:
// g++ -std=c++20 -pthread countingSemaphore.cpp -o countingSemaphore
// .\countingSemaphore

#include <iostream>
#include <thread>
#include <vector>
#include <semaphore>   // C++20 feature
using namespace std;
int buffer = 0;   // single slot buffer
const int MAX_SIZE = 3;

// Counting semaphore to track empty slots
counting_semaphore<MAX_SIZE+1> empty_slot(MAX_SIZE);

void producer_with_semaphore(int id) {
    for (int i = 0; i < 5; i++) {
        empty_slot.acquire();   // wait(empty) → blocks if no slot available
        buffer++;
        std::cout << "Producer " << id << " produced, buffer=" << buffer << "\n";
        empty_slot.release();   // signal(empty) → release slot back
    }
}

int main() {
    std::thread p1(producer_with_semaphore, 1);
    std::thread p2(producer_with_semaphore, 2);

    p1.join();
    p2.join();

    std::cout << "Final buffer=" << buffer << "\n";
}
