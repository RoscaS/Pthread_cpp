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


