#include <iostream>
#include "Workers.h"

int main() {

    Workers workers(4);
    Workers event_loop(1);

    event_loop.start();
    workers.start();

    workers.post([] { std::cout << "hei1\n"; });
    workers.post([] { std::cout << "hei2\n"; });
    workers.post([] { std::cout << "hei3\n"; });
    workers.post([] { std::cout << "hei4\n"; });
    workers.post([] { std::cout << "hei5\n"; });
    workers.post([] { std::cout << "hei6\n"; });



    event_loop.post([] { std::cout << "hei8\n"; });
    event_loop.post([] { std::cout << "hei9\n"; });

    workers.stop();
    event_loop.stop();

    return 0;
}


