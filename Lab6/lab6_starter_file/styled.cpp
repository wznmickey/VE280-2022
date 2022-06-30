//
// Created by Second Lobster on 2021/6/21.
//
#include "plugin.h"
#include <iostream>
#include <regex>
#include <sstream>

const string styledKeyWord1 = "WhosYourDaddy";

class Styled : public Plugin
{
public:
    Styled( )
        : Plugin( )
    {
        this->name        = "styled";
        this->author      = "Second Lobster";
        this->description = "wznmickey";
        this->help = "Ni han po hou long ye bu hui you ren "
                     "jiu ni de !";
    }

    string response( const string &str ) const override
    {
        return "You are not playing Warcraft 3, guys...";
    }

    int matchRule( const string &str ) const override
    {
        return ( str == styledKeyWord1 );
    }

    string toString( ) const override
    {
        return "Second Lobster writes styled because he "
               "thinks it is fun";
    }
};

extern "C" Plugin *create( )
{
    return new Styled;
}

extern "C" int *destroy( Plugin *p )
{
    delete p;
    return 0;
}
