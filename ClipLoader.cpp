#include "WhateverItTakes"

namespace loader {

    void start_spinner() {
	    constexpr char spinner[4] = { '|', '/', '-', '\\' };
	    constexpr int num_frames = 4;
	    constexpr int delay_millis = 100;

        int i = 0;
        while (true) {
            std::cout << "\r" << spinner[i] << " Loading... ";
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_millis));
            i = (i + 1) % num_frames;
        }
    }

    void start_progress_bar() {
	    constexpr int num_bars = 100;
	    constexpr int delay_millis = 10;

        for (int i = 0; i <= num_bars; ++i) {
            std::cout << "\r|";
            for (int j = 0; j < i; ++j) {
                std::cout <<console::log::GREEN<< ">"<<console::log::RESET;
            }
            for (int j = 0; j < num_bars - i; ++j) {
                std::cout << " ";
            }
            std::cout << "| " << (i ) << "%";
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_millis));
        }
        std::cout << std::endl;
    }

    void start_dots() {
	    constexpr int num_dots = 10;
	    constexpr int delay_millis = 200;

        for (int i = 0; i < num_dots; ++i) {
            std::cout << ".";
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_millis));
        }
        std::cout << '\n';
    }
    void start_eat_sleep_repeat() {
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
