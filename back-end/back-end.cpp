
// this is the main file of teh back end of octo
// octo is a simple minecraft like TUI game
#include <string>
#include <ncurses.h>
#include "back-end.h"
using namespace std;


void backend::start_ncurses(){initscr();} // a function to start the ncurses system

void backend::get_terminal_info(){ // initates the term_size_x and term_size_y variables

    getmaxyx(stdscr, term_size_y , term_size_x );

}

void backend::create_map(){ // main algorithm to create the map

    map = "";
}
