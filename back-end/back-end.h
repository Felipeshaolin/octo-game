
#pragma once

#include <string>
#include <ncurses.h>

using namespace std;

class backend {

    public:

        void start_ncurses();// a function to start the ncurses system

        void get_terminal_info();// initates the term_size_x and term_size_y variables

        void create_map();// main algorithm to create the map


    private:

         int term_size_x;

         int term_size_y;

        string map;

};
