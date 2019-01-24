#include <iostream>
#include <memory>
#include "testthread.h"


int main(int argc, char *argv[]) {

    std::unique_ptr<TestThread> t1(new TestThread);
    std::unique_ptr<TestThread> t2(new TestThread);

    t1->start();
    t2->start();

    t1->join();
    t2->join();

    std::cout << "Fin des threads. Global = " << TestThread::global
              << " (" << 2 * TestThread::iterations << ")\n";

    return 0;
}
