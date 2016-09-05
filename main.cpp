#include <memory.h>
#include "cowsayer.h"

#define strIs(a,b) (strcmp(a,b)==0)

void noText()
{
    cowSay( "No arguments??\nYou do know the purpose of this program, right?" );
}

int main( int argCount, char *args[] )
{
    if ( argCount <= 1 && !cin )
    {
        noText();
        return -1;
    }

    Animal animal = COW;
    int width = 25;

    int currentArg = 1;

    // parse just the arguments
    for ( ; currentArg < argCount; ++currentArg )
    {
        char* arg = args[ currentArg ];

        if ( strIs( arg, "-c" ) ) animal = COW;
        else if ( strIs( arg, "-p" ) ) animal = PIKACHU_THING;
        else if ( strIs( arg, "-aoi" ) ) animal = AXIS_OF_INNOVATION;
        else if ( strIs( arg, "-t" ) ) animal = TUX;
        // set the width
        else if ( strIs( arg, "--width" ) || strIs( arg, "-w" ) )
        {
            width = atoi( args[ ++currentArg ] ); // parse the next argument as an int (also skips it the next loop)
        }
        // invalid flag signals the beginning of the text
        else
        {
            break;
        }
    }

    // concatenate all that stuff into one sexual transmitted disease string
    std::string result;
    for ( ; currentArg < argCount; ++currentArg )
    {
        // add a leading space if there was something added before this
        if ( !result.empty() ) result += " ";

        // add the argument
        result += args[ currentArg ];
    }

    if ( result.empty() )
    {
        // if there's something in the input (i.e. input was piped) read from it
        if ( cin )
        {
            // keep reading until it's over
            for ( int i = 0; cin; ++i )
            {
                string input;
                getline( cin, input );

                if ( i ) result += "\n"; // prepend a new line for all but the first line
                result += input;
            }
        }
        else
        {
            noText();
            return -1;
        }
    }

    // say that sexually transmitted disease string
    cowSay( result, width, animal );

    return 0;
}