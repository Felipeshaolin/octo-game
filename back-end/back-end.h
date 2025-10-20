
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

        // map 

            void set_concentration_of_obstacles(); // sets the maximum value of rocks/grass/water bodies

            void create_grass_plane(); // creates a map full of grass and initialises map size variable

            void create_rock_formations(); // creates the rocks on the map

            void create_mountains(); //creates mountain in the map

            void create_map();// main algorithm to create the map

            void create_water_formation();// places water on the map

            string get_map(); //returns the map string

            void change_map( char type , int x , int y );// changes a block in a certain coordinate

        //input

            int get_input();// returns a number based on the input that is being pressed

    private:

        int term_size_x; //size of terminal x,y
        int term_size_y;

        int term_max_lenght_x = 150; // maximum size of terminal in x,y
        int term_max_lenght_y = 150;

        int screen_percentage_x; // 1% of the terminal size in x,y
        int screen_percentage_y;


        string map; //the map string
        int map_size; //lenght of map string

        int number_of_rocks; // number of rocks per map
        int number_of_water; // number of waters per map
        int number_of_grass; // number of grasses per map


};
