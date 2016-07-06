#include "worker.h"
#include "menu.h"

Worker::Worker()
{
    std::unique_ptr<Logging> log(new Logging());
    log->loggingIntoTextFile("==> constructor of class 'Worker' <== \n");
}

void Worker::start()
{
    std::unique_ptr<Menu> menu(new Menu());
    menu->start();
}

Worker::~Worker()
{
    std::unique_ptr<Logging> log(new Logging());
    log->loggingIntoTextFile("==> destructor of class 'Worker' <== \n");
}
