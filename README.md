# C++ Pthread

Simple wrapper around **Pthread** library.

## Example:

 ```cpp
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
 ```

```cpp
#pragma once
#include "workerbase.h"


class TestThread : public WorkerBase {

    void internalThread() override {
        std::cout << stringId("start");
        for (int i = 0; i < iterations; i++) {

            TestThread::mutex.wait();
            global++;
            TestThread::mutex.post();
        }
        std::cout << stringId("end");
    }

public:
    static int iterations;
    static int global;
    static Sem mutex;
};

Sem TestThread::mutex{1};
int TestThread::iterations = 10000;
int TestThread::global = 0;
```
