
#pragma once

#include <string>
#include <ncurses.h>

using namespace std;

class backend {

    public:

        // ncurses

        void start_ncurses();// a function to start the ncurses system

        void end_ncurses();// a function to stop the ncurses system

        void get_terminal_info();// initates the term_size_x and term_size_y variables

        // map creation

        void create_grass_plane(); // creates a map full of grass and initialises map size variable

        void create_rock_formations(); // creates the rocks on the map

        void create_map();// main algorithm to create the map

        //input

        int get_input();// returns a number based on the input that is being pressed

    private:

        int term_size_x;

        int term_size_y;

        string map;

        int map_size;

        int number_of_rocks = 10;

        int term_max_lenght_x = 100;

        int term_max_lenght_y = 100;

};
