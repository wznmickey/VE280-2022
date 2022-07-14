//
// Created by cyx on 20-5-29.
//

#ifndef INTLIST_IMPL_H
#define INTLIST_IMPL_H

#include "mylist.h"
#include <iostream>

template < class T > void List< T >::print( )
{
    Node_t< T > *itr = first;
    while ( itr )
    {
        std::cout << itr->val;
        itr = itr->next;
    }
    std::cout << "\n";
}
template < class T > void List< T >::removeAll( )
{
    if ( first != nullptr )
    {
        while ( true )
        {
            auto temp = first->next;
            delete first;
            first = temp;
            if ( temp == nullptr )
            {
                last = nullptr;
                return;
            }
        }
    }
    return;
}

template < class T > void List< T >::copyFrom( const List &l )
{
    removeAll( );
    auto         temp   = l.first;
    Node_t< T > *before = nullptr;
    if ( temp != nullptr )
    {
        while ( true )
        {
            auto newTemp = new Node_t< T >( temp->val, nullptr );
            if ( before != nullptr )
            {
                before->next = newTemp;
                before       = newTemp;
            }
            else
            {
                first  = newTemp;
                before = newTemp;
            }
            temp = temp->next;
            if ( temp == nullptr )
            {
                last = newTemp;
                return;
            }
        }
    }
    else
    {
        first = nullptr;
        last  = nullptr;
        return;
    }
    return;
}

template < class T > bool List< T >::isEmpty( ) const
{
    return ( first == nullptr );
}

template < class T > void List< T >::insertBack( T val )
{
    if ( first == nullptr )
    {
        first = new Node_t< T >( val, nullptr );
        last  = first;
        return;
    }
    auto temp  = last;
    last       = new Node_t< T >( val, nullptr );
    temp->next = last;
    return;
}

template < class T > T List< T >::removeFront( )
{
    if ( first == nullptr )
    {
        throw EmptyList( );
    }
    auto ans = first->val;
    first    = first->next;
    return ans;
}

template < class T > const Node_t< T > *List< T >::returnFront( ) const
{
    auto temp = first;
    return temp;
}

template < class T > List< T >::List( )
{
    first = nullptr;
    last  = nullptr;
} // constructor
template < class T > List< T >::List( const List &l )
{
    copyFrom( l );
    return;
} // copy constructor
template < class T > List< T > &List< T >::operator=( const List &l )
{
    this.copyFrom( l );
    return *this;
} // assignment operator
template < class T > List< T >::~List( )
{
    removeAll( );
    return;
} // destructor
bool isLarger( const List< int > &a, const List< int > &b )
{
    int  ans = 0; // 0 - equal, -1 smaller ,1 - larger
    auto aC  = a;
    auto bC  = b;
    while ( true )
    {
        int aV = 0;
        int bV = 0;
        if ( ! a.isEmpty( ) )
        {
            aV = aC.removeFront( );
        }
        if ( ! b.isEmpty( ) )
        {
            bV = bC.removeFront( );
        }
        if ( aV < bV )
        {
            ans = -1;
        }
        if ( aV > bV )
        {
            ans = 1;
        }
        if ( a.isEmpty( ) && b.isEmpty( ) )
        {
            break;
        }
    }
    return ( ans == 1 );
}
List< int > Add( const List< int > &a, const List< int > &b )
{
    List< int > ans;
    int         remain = 0;
    auto        aC     = a;
    auto        bC     = b;
    while ( true )
    {
        if ( ! a.isEmpty( ) )
        {
            remain += aC.removeFront( );
        }

        if ( ! b.isEmpty( ) )
        {
            remain += bC.removeFront( );
        }
        ans.insertBack( remain % 10 );
        remain = remain / 10;
        if ( ( remain == 0 ) && ( a.isEmpty( ) ) && ( b.isEmpty( ) ) )
        {
            return ans;
        }
    }
}

#endif // INTLIST_IMPL_H
