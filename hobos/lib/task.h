#ifndef __TASK_H
#define __TASK_H

#include <stdint.h>

//We want simple thread implementation
//
//1: A task is created and added to workqueue
//2: When the requested core is available, create a
//thread and send it over to be executed

struct task {
};

void queue_task(void);

#endif
