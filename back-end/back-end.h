
#pragma once

#include <string>
#include <ncurses.h>

using namespace std;

class backend {

    public:

        void start_ncurses();

        void get_terminal_info();

        void create_map();

    private:

         int term_size_x;

         int term_size_y;

        string map;

};
