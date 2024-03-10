#include "WhateverItTakes"

namespace Loader {

    void startSpinner() {
        const char spinner[4] = { '|', '/', '-', '\\' };
        const int numFrames = 4;
        const int delayMillis = 100;

        int i = 0;
        while (true) {
            std::cout << "\r" << spinner[i] << " Loading... ";
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));
            i = (i + 1) % numFrames;
        }
    }

    void startProgressBar() {
        const int numBars = 100;
        const int delayMillis = 10;

        for (int i = 0; i <= numBars; ++i) {
            std::cout << "\r|";
            for (int j = 0; j < i; ++j) {
                std::cout <<console::log::GREEN<< ">"<<console::log::RESET;
            }
            for (int j = 0; j < numBars - i; ++j) {
                std::cout << " ";
            }
            std::cout << "| " << (i ) << "%";
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));
        }
        std::cout << std::endl;
    }

    void startDots() {
        const int numDots = 10;
        const int delayMillis = 200;

        for (int i = 0; i < numDots; ++i) {
            std::cout << ".";
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));
        }
        std::cout << std::endl;
    }
    void startEatSleepRepeat() {
        int i = 1;
        while (i--) {
            std::cout << "\r^_^";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "\r-_-";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "\r*_*";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "\ro_o";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

    }

}
