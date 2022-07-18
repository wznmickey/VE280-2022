#include "DlistImpl.h"
#include "Instr.h"
#include <algorithm>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
const int MEMORY_SIZE = 16;
template < class T > class Stack
{
private:
    Dlist< T > list;

public:
    void push( T value )
    {
        // std::cout<<"good 19"<<endl;
        auto temp = new T( value );
        // std::cout<<"good 21"<<endl;
        list.insertFront( temp );
        return;
    }
    auto pop( ) -> T
    {
        auto ans  = list.removeFront( );
        auto temp = *ans;
        delete ans;
        return temp;
    }
    auto print( )
    {
        auto temp = list;
        while ( ! temp.isEmpty( ) )
        {
            auto tempp = temp.removeBack( );
            cout << ( *tempp ) << " ";
            delete tempp;
        }
        return;
    }
};

template < class T > class Queue
{
private:
    Dlist< T > list;

public:
    void push( T value )
    {
        auto temp = new T( value );
        list.insertBack( temp );
        return;
    }
    auto pop( ) -> T
    {
        auto ans  = list.removeFront( );
        auto temp = *ans;
        delete ans;
        return temp;
    }
    auto print( )
    {
        cout << list << endl;
    }
};
const auto print = []( Stack< int > &stack, Queue< Instr > &queue, int *memory, Instr &command, bool direct )
{
    if ( direct )
    {
        return;
    }
    cout << command << endl;
    stack.print( );
    queue.print( );
    for ( auto i = 0; i < MEMORY_SIZE; i++ )
    {
        cout << memory [ i ] << " ";
    }
    cout << endl;
    return;
};
const auto add = []( Stack< int > &stack, Queue< Instr > & /*queue*/, int * /*memory*/, Instr & /*command*/ )
{
    stack.push( stack.pop( ) + stack.pop( ) );
    return true;
};
const auto nor = []( Stack< int > &stack, Queue< Instr > & /*queue*/, int * /*memory*/, Instr & /*command*/ )
{
    stack.push( ~( stack.pop( ) | stack.pop( ) ) );
    return true;
};
const auto ifz = []( Stack< int > &stack, Queue< Instr > &queue, int * /*memory*/, Instr &command )
{
    auto flag = stack.pop( );
    if ( flag == 0 )
    {
        for ( auto i = 0; i < command.parameter; i++ )
        {
            queue.pop( );
        }
    }
    return true;
};

const auto halt = []( Stack< int > & /*stack*/, Queue< Instr > & /*queue*/, int * /*memory*/, Instr & /*command*/ )
{
    return false;
};

const auto load = []( Stack< int > &stack, Queue< Instr > & /*queue*/, int *memory, Instr & /*command*/ )
{
    auto address = stack.pop( );
    stack.push( memory [ address ] );
    return true;
};

const auto store = []( Stack< int > &stack, Queue< Instr > & /*queue*/, int *memory, Instr & /*command*/ )
{
    auto address       = stack.pop( );
    auto val           = stack.pop( );
    memory [ address ] = val;
    return true;
};
const auto pop = []( Stack< int > &stack, Queue< Instr > & /*queue*/, int * /*memory*/, Instr & /*command*/ )
{
    stack.pop( );
    return true;
};

const auto pushi = []( Stack< int > &stack, Queue< Instr > & /*queue*/, int * /*memory*/, Instr &command )
{
    stack.push( command.parameter );
    return true;
};
const auto noop = []( Stack< int > & /*stack*/, Queue< Instr > & /*queue*/, int * /*memory*/, Instr & /*command*/ )
{
    return true;
};
bool ( *const table [ 9 ] )( Stack< int > &stack, Queue< Instr > &queue, int *memory, Instr &command )
    = { add, nor, ifz, halt, load, store, pop, pushi, noop };
void run( Stack< int > &stack, Queue< Instr > &queue, int *memory, bool direct )
{
    // std::cout<<"good 139"<<endl;
    Instr command { };
    do
    {
        // std::cout<<"good 143"<<endl;
        command = queue.pop( );
        // std::cout<<"good 145"<<endl;
    } while (
        [ & ]( )
        {
            auto temp = table [ int( command.name ) ]( stack, queue, memory, command );
            print( stack, queue, memory, command, direct );
            return temp;
        }( ) );
    return;
}

void read( Stack< int > &stack, Queue< Instr > &queue, int *memory )
{
    int n = 0;
    int m = 0;
    cin >> n >> m;
    // std::cout<<"good 8"<<endl;
    for ( auto i = 0; i < n; i++ )
    {
        int temp = 0;
        cin >> temp;
        stack.push( temp );
    }
    // std::cout<<"good 9"<<endl;
    for ( auto i = 0; i < m; i++ )
    {
        Instr temp { };
        cin >> temp;
        queue.push( temp );
    }
    // std::cout<<"good 10"<<endl;
    for ( auto i = 0; i < MEMORY_SIZE; i++ )
    {
        cin >> memory [ i ];
    }
    return;
}

void write( Stack< int > &stack, Queue< Instr > & /*queue*/, int *memory, bool direct )
{
    if ( ! direct )
    {
        return;
    }
    stack.print( );
    for ( auto i = 0; i < MEMORY_SIZE; i++ )
    {
        cout << memory [ i ] << " ";
    }
    return;
}

auto main( int argc, char *argv [] ) -> int
{
    // TODO:write your code here.
    bool direct = false;
    for ( auto i = 1; i < argc; i++ )
    {
        if ( std::string( argv [ i ] ) == "-s" )
        {
            direct = true;
            break;
        }
    }
    int           *memory = new int [ MEMORY_SIZE ];
    Stack< int >   stack { };
    Queue< Instr > queue { };
    // std::cout<<"good 1"<<endl;
    read( stack, queue, memory );
    // std::cout<<"good 1"<<endl;
    run( stack, queue, memory, direct );
    // std::cout<<"good 1"<<endl;
    write( stack, queue, memory, direct );
    return 0;
}
