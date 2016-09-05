//
// Created by austin on 9/3/16.
//

#ifndef COWSAY_COWSAYER_H
#define COWSAY_COWSAYER_H

#include <iostream>
#include <vector>
using namespace std;

const string animals[] =
        {
                "        \\   ^__^\n"
                "         \\  (oo)\\_______\n"
                "            (__)\\       )\\/\\\n"
                "                ||----w |\n"
                "                ||     ||",

                // oh god. This is why I shouldn't try to do ASCII art
                "        \\    ^   ^\n"
                "         \\  ( ) ( )\n"
                "           ( o  o )\n"
                "           (  <   )\n"
                "            \\ __ /\n"
                "        <==[     ]==>\n"
                "           [     ]\n"
                "          (..)(..)",

                "       \\                   __\n"
                "        \\ ____     ____   |__|\n"
                "         / __ \\   / __ \\   __\n"
                "        | |  | | | |  | | |  |\n"
                "        | |__| | | |__| | |  |\n"
                "         \\___/_|  \\____/  |__|",

                "       \\    .--.\n"
                "        \\  |o_o |\n"
                "           |:_/ |\n"
                "          //   \\ \\\n"
                "         (|     | )\n"
                "        /'\\_   _/`\\\n"
                "        \\___)=(___/"
        };

/**
 * An animal is actually just an index in the animals array, that's
 * a little known fact.
 */
enum Animal
{
    COW = 0,
    PIKACHU_THING = 1,
    AXIS_OF_INNOVATION = 2,
    TUX = 3
};

void cowSay( string text, int maxWidth = 25, Animal animal = COW );

void printLines( vector< string > wrappedText, unsigned long longest );

tuple< unsigned long, vector< string > > wrapText(string text, int maxWidth );

#endif //COWSAY_COWSAYER_H
