
// this is the main file of teh back end of octo
// octo is a simple minecraft like TUI game
#include <string>
#include <ncurses.h>
#include <cstdlib>
#include "back-end.h"

using namespace std;
                                                                                 
//███    ██  ██████ ██    ██ ██████  ███████ ███████ ███████ 
//████   ██ ██      ██    ██ ██   ██ ██      ██      ██      
//██ ██  ██ ██      ██    ██ ██████  ███████ █████   ███████ 
//██  ██ ██ ██      ██    ██ ██   ██      ██ ██           ██ 
//██   ████  ██████  ██████  ██   ██ ███████ ███████ ███████                                                                                                                              

    void backend::start_ncurses(){ // a function to start the ncurses system
        initscr();
        cbreak();   // Disable line buffering
        noecho();   // Disable automatic echoing of typed characters
        curs_set(0); // Hide cursor

    } 

    void backend::end_ncurses(){ // a function to stop the ncurses system

        curs_set(0); // Hide cursor
        endwin();

    }

    void backend::get_terminal_info(){ // initates the term_size_x and term_size_y variables

        getmaxyx(stdscr, this->term_size_y , this->term_size_x );

        // check if your terminal is small enough
        if (this->term_size_y > this->term_max_lenght_y | this->term_size_y == 0){ 

            this->term_size_y = this->term_max_lenght_y;
        }

        if (this->term_size_x > this->term_max_lenght_x | this->term_size_x == 0){

            this->term_size_x = this->term_max_lenght_x;
        }


    }


//███    ███  █████  ██████  
//████  ████ ██   ██ ██   ██ 
//██ ████ ██ ███████ ██████  
//██  ██  ██ ██   ██ ██      
//██      ██ ██   ██ ██                                                                 

    void backend::set_concentration_of_obstacles(){// sets the maximum value of rocks/grass/water bodies
        
        int percentage = (this->map_size/100)* 5;

        this->number_of_water = percentage;
        this->number_of_grass = percentage;
        this->number_of_rocks = percentage;

    } 

    void backend::create_grass_plane(){ // creates a map full of grass and initialises map size variable

        this->map_size = this->term_size_x * this->term_size_y  ;

        this->map = string(this->map_size, 'g');

    }

    void backend::create_rock_formations(){ // creates the rocks on the map

        for (int numb = 0; numb < this->number_of_rocks; numb++ ){ // repeat this for the number of rocks needed

            int random_coord_x = rand() % ( this->term_size_x + 1 ) ;// get random x and y coordinates for the rock formation
            int random_coord_y = rand() % ( this->term_size_y + 1 ) ; 

            int rock_coordinates = random_coord_y * this->term_size_x  + random_coord_x ; // convert the 2d coordinate into a 1d coordinate

            this->map[rock_coordinates] = 'R' ; // big rock is placed

        }

    }

    void backend::create_water_formation(){// places water on the map

        // NOTE: THIS IS PLACEHOLDER CODE, I WILL CHANGE THE WATER CREATION AFTER
        // TODO: change this code

        for (int numb = 0; numb < this->number_of_water; numb++ ){ // repeat this for the number of water needed

            int random_coord_x = rand() % ( this->term_size_x + 1 ) ;// get random x and y coordinates for the water formation
            int random_coord_y = rand() % ( this->term_size_y + 1 ) ; 

            int water_coordinates = random_coord_y * this->term_size_x  + random_coord_x ; // convert the 2d coordinate into a 1d coordinate

            if (this->map[water_coordinates] != 'R'){

                this->map[water_coordinates] = 'w' ; // big water is placed if rock not in the way

            }

        }

    }

    void backend::create_mountains(){// places water on the map

        for (int numb = 0; numb < this->number_of_grass; numb++ ){ // repeat this for the number of rocks needed

            int random_coord_x = rand() % ( this->term_size_x + 1 ) ;// get random x and y coordinates for the rock formation
            int random_coord_y = rand() % ( this->term_size_y + 1 ) ; 

            int grass_coordinates = random_coord_y * this->term_size_x  + random_coord_x ; // convert the 2d coordinate into a 1d coordinate

            if ( (this->map[grass_coordinates] != 'R') | (this->map[grass_coordinates] != 'w') ){

                this->map[grass_coordinates] = 'G' ; // big grass is placed if rock or water not in the way

            }

        }

    }

    void backend::create_map(){ // main algorithm to create the map


        this->get_terminal_info();//get terminal info

        
        this->create_grass_plane();//create a map full of grass

        this->set_concentration_of_obstacles(); //set the right amount of stuff

        this->create_rock_formations();//create the rocks

        this->create_water_formation();//create the water

        this-> create_mountains();

        printw( this->map.c_str() );

        refresh();  // Refresh the screen to show the map
    }

    string backend::get_map(){ //returns the map string

        return this->map ;

    }

//██ ███    ██ ██████  ██    ██ ████████ 
//██ ████   ██ ██   ██ ██    ██    ██    
//██ ██ ██  ██ ██████  ██    ██    ██    
//██ ██  ██ ██ ██      ██    ██    ██    
//██ ██   ████ ██       ██████     ██                                                                                       

int backend::get_input(){

    return getch();

}


//test
int main(){

    backend object;

    object.start_ncurses();

    object.get_terminal_info();

    object.create_map();

    object.get_input();

    object.end_ncurses();

    return 0;

}