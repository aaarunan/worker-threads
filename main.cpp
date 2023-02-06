#include <iostream>
#include "Workers.h"

int main() {

    Workers workers(4);
    workers.start();

    workers.post([] { std::cout << "mo\n"; });
    workers.post([] { std::cout << "fa\n"; });
    workers.post([] { std::cout << "hei3\n"; });
    workers.post([] { std::cout << "hei3\n"; });

    workers.stop();
    return 0;
}


