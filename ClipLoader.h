#pragma once
#ifndef LOADER_H
#define LOADER_H

#include <iostream>
#include <thread>
#include <chrono>

namespace loader {

    void start_spinner();
    void start_progress_bar();
    void start_dots();
    void start_eat_sleep_repeat();

}

#endif // LOADER_H
