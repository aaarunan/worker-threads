//
// Created by arunang on 1/26/23.
//

#include <iostream>
#include "Workers.h"


Workers::Workers(int thread_count) {
    this->thread_count = thread_count;
}

void Workers::post(const function<void()> &task) {
    mtx.lock();
    tasks.push(task);
    mtx.unlock();
    threads_cv.notify_one();
}

void Workers::start() {
    loop = true;
    for (int i = 0; i < thread_count; i++) {
        threads.emplace_back([this] {
            while (true) {
                unique_lock<mutex> lock(mtx);

                while (tasks.empty()) {
                    if (!loop) {
                        return;
                    }
                    threads_cv.wait(lock);
                }

                function<void()> task = tasks.front();
                tasks.pop();

                lock.unlock();

                threads_cv.notify_one();

                task();
            }
        });
    }
}

void Workers::stop() {
    loop = false;
    for (auto &thread: threads) {
        thread.join();
    }
}


