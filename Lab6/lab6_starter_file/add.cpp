//
// Created by Meual on 2021/6/21.
//
#include "plugin.h"
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

const string addKeyWord1 = "add";

class Add : public Plugin
{
public:
    Add( )
        : Plugin( )
    {
        this->name        = "add";
        this->author      = "Meual";
        this->description = "add two integers";
        this->help = "Usage: add <integer> <integer>";
    }

    string response( const string &str ) const override
    {
        stringstream ss( str );
        string       i;
        int          a, b;
        ss >> i >> a >> b;
        return to_string( a + b );
    }

    int matchRule( const string &str ) const override
    {
        stringstream ss( str );
        string       i;
        int          a, b;
        ss >> i >> a >> b;
        return ( i == addKeyWord1 );
    }

    string toString( ) const override
    {
        return "Add operations is great --Meual";
    }
};

extern "C" Plugin *create( )
{
    return new Add;
}

extern "C" int *destroy( Plugin *p )
{
    delete p;
    return 0;
}
