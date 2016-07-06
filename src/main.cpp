#include "worker.h"

int main()
{

    std::shared_ptr<Worker> worker(new Worker());
    worker->start();

    return 0;
}
