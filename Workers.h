//
// Created by arunang on 1/26/23.
//
#include <mutex>
#include <thread>
#include <vector>
#include <condition_variable>
#include <queue>
#include <functional>
#include <list>


#ifndef OVING3_WORKERS_H
#define OVING3_WORKERS_H

using namespace std;

class Workers {
public:
    void start();
    void post(const function<void()> &task);
    void stop();
    explicit Workers(int);

private:
    int thread_count;
    bool loop{false};
    queue<function<void()>> tasks{};
    mutex mtx{};
    condition_variable threads_cv{};
    vector<thread> threads{};


};


#endif //OVING3_WORKERS_H
