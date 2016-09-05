//
// Created by austin on 9/3/16.
//

#include <sstream>
#include <tuple>
#include "cowsayer.h"

void cowSay( string text, int maxWidth, Animal animal )
{
    auto textAndLength = wrapText( text, maxWidth );

    // get the data from the formatter
    unsigned long longest = get< 0 >( textAndLength );
    vector< string > wrappedText = get< 1 >( textAndLength );

    // draw the top
    cout << " _";
    for ( int i = 0; i < longest; ++i ) cout << "_";
    cout << "_" << endl;

    // draw the words
    printLines(wrappedText, longest );

    // draw the bottom
    cout << " ‾";
    for ( int i = 0; i < longest; ++i ) cout << "‾";
    cout << "‾" << endl;

    // draw the animal
    cout << animals[ animal ] << endl;
}

void printLines( vector< string > wrappedText, unsigned long longest )
{
    // build the formatting string
    stringstream ss;
    ss << "< %-" << longest << "s >\n";
    const char* formattingString = ss.str().c_str();

    // print all the lines
    for ( auto const &line : wrappedText )
    {
        printf( formattingString, line.c_str() );
    }
}

tuple< unsigned long, vector< string > > wrapText( string text, int maxWidth )
{
    vector< string > result;

    unsigned long longest = 0;

    // iterate over the entire text
    for ( int pos = 0; pos < text.length(); )
    {
        // the last space in the string (used if word goes over length)
        // this uses the active positioning
        int lastSpace = -1;

        int length = 0;

        for ( ; pos + length < text.length() && length < maxWidth; ++length )
        {
            char c = text[ pos + length ];

            // if it's a space, update the last space index
            if ( c == ' ' )
            {
                lastSpace = length;
            }
            // if it's a new line character, we're done, we need to move onto the next line
            else if ( c == '\r' || c == '\n' )
            {
                break;
            }
        }

        string line;

        // the line contains too few characters to be wrapped
        if ( length < maxWidth )
        {
            line += text.substr( ( unsigned long ) pos, ( unsigned long ) length );
            pos += length + 1; // skip ahead to the current position
        }
        // the line must be wrapped as it hit the max width, and there is a space in the line
        else if ( lastSpace != -1 )
        {
            line += text.substr( ( unsigned long ) pos, ( unsigned long ) lastSpace );
            pos += lastSpace + 1; // move ahead to the character after the space for the next loop
        }
        // the line must be wrapped as it hit the max width, and there is no space in the line
        else
        {
            line += text.substr( ( unsigned long ) pos, ( unsigned long ) length );
            pos += length + 1; // move ahead past all of these characters
        }

        result.push_back( line );
        longest = max( longest, line.length() );
    }

    return make_tuple( longest, result );
}