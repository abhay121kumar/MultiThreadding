// // to run the code:
// // g++ -std=c++20 -pthread countingSemaphore.cpp -o countingSemaphore
// // .\countingSemaphore

// #include <iostream>
// #include <thread>
// #include <vector>
// #include <semaphore>   // C++20 feature
// using namespace std;
// int buffer = 0;   // single slot buffer
// const int MAX_SIZE = 3;

// // Counting semaphore to track empty slots
// counting_semaphore<MAX_SIZE+1> empty_slot(MAX_SIZE);

// void producer_with_semaphore(int id) {
//     for (int i = 0; i < 5; i++) {
//         if(buffer >= MAX_SIZE) {
//             std::cout << "Buffer full, Producer " << id << " waiting...\n";
//             break;
//         }
//         empty_slot.acquire();   // wait(empty) → blocks if no slot available
//         buffer++;
//         std::cout << "Producer " << id << " produced, buffer=" << buffer << "\n";
//         empty_slot.release();   // signal(empty) → release slot back
//     }
// }

// int main() {
//     std::thread p1(producer_with_semaphore, 1);
//     std::thread p2(producer_with_semaphore, 2);

//     p1.join();
//     p2.join();

//     std::cout << "Final buffer=" << buffer << "\n";
// }



#include <iostream>
#include <thread>
#include <semaphore>   // C++20
#include <mutex>
#include <chrono>

const int MAX_SIZE = 3;
int buffer = 0;  // shared resource

// Synchronization tools
std::counting_semaphore<MAX_SIZE> empty(MAX_SIZE); // slots free
std::counting_semaphore<MAX_SIZE> full(0);         // no items yet
std::mutex mtx;  // protects buffer

void producer(int id) {
    for (int i = 0; i < 5; i++) {
        empty.acquire();       // wait if buffer is full
        mtx.lock();            // enter critical section

        buffer++;              // produce item
        std::cout << "p-i: "<< i <<" Producer " << id << " produced, buffer=" << buffer << "\n";

        mtx.unlock();          // leave critical section
        full.release();        // signal that one item is ready

        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void consumer(int id) {
    for (int i = 0; i < 5; i++) {
        full.acquire();        // wait if buffer empty
        mtx.lock();            // enter critical section

        buffer--;              // consume item
        std::cout << "c-i: "<< i <<" Consumer " << id << " consumed, buffer=" << buffer << "\n";

        mtx.unlock();          // leave critical section
        empty.release();       // signal slot free

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    std::thread p1(producer, 1);
    // std::thread p2(producer, 2);
    // std::thread c1(consumer, 1);
    // std::thread c2(consumer, 2);

    p1.join();
    // p2.join();
    // c1.join();
    // c2.join();

    return 0;
}
