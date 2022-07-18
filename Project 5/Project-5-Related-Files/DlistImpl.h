#ifndef __DLIST_IMPL_H__
#define __DLIST_IMPL_H__
#include <iostream>

#include "Dlist.h"

template < class T > auto Dlist< T >::isEmpty( ) const -> bool
{
    return ( first == nullptr );
}
template < class T > void Dlist< T >::insertFront( T *op )
{
    auto temp  = new node;
    temp->prev = nullptr;
    temp->next = first;
    if ( first != nullptr )
    {
        first->prev = temp;
    }
    temp->op = op;
    first    = temp;
    if ( last == nullptr )
    {
        last = temp;
    }
    return;
}
template < class T > void Dlist< T >::insertBack( T *op )
{
    auto temp  = new node;
    temp->prev = last;
    if ( last != nullptr )
    {
        last->next = temp;
    }
    temp->next = nullptr;
    temp->op   = op;
    last       = temp;
    if ( first == nullptr )
    {
        first = temp;
    }
    return;
}

template < class T > auto Dlist< T >::removeFront( ) -> T *
{
    if ( isEmpty( ) )
    {
        throw EmptyList( );
    }
    auto temp = first;
    first     = first->next;
    if ( first == nullptr )
    {
        last = nullptr;
    }
    else
    {
        first->prev = nullptr;
    }
    auto ans = temp->op;
    delete temp;
    return ans;
}

template < class T > auto Dlist< T >::removeBack( ) -> T *
{
    if ( isEmpty( ) )
    {
        throw EmptyList( );
    }
    auto temp = last;
    last      = last->prev;
    if ( last == nullptr )
    {
        first = nullptr;
    }
    else
    {
        last->next = nullptr;
    }
    auto ans = temp->op;
    delete temp;
    return ans;
}

template < class T > void Dlist< T >::removeAll( )
{
    while ( first != nullptr )
    {
        auto temp = first;
        first     = first->next;
        delete ( temp->op );
        delete ( temp );
    }
    last = nullptr;
}

template < class T > void Dlist< T >::copyAll( const Dlist &l )
{
    // std::cout<<"here"<<std::endl;
    removeAll( );
    // std::cout<<"here3"<<std::endl;

    auto             temp   = l.first;
    decltype( temp ) before = nullptr;
    while ( temp != nullptr )
    {
        auto newNode  = new node( );
        newNode->op   = new T( *( temp->op ) );
        newNode->prev = before;
        newNode->next = nullptr;
        // [[likely]]
        if ( before != nullptr )
        {
            before->next = newNode;
        }
        else
        {
            first = newNode;
        }
        before = newNode;
        temp   = temp->next;
    }
    last = before;
    // std::cout<<"here2"<<std::endl;
}

template < class T > Dlist< T >::Dlist( )
{
    first = nullptr;
    last  = nullptr;
    return;
}
template < class T >
Dlist< T >::Dlist( const Dlist &l )
    : first( nullptr )
    , last( nullptr )
{

    copyAll( l );
}
template < class T > auto Dlist< T >::operator=( const Dlist &l ) -> Dlist< T > &
{
    if ( this == &l )
    {
        return *this;
    }
    removeAll( );
    copyAll( l );
    return *this;
}
template < class T > Dlist< T >::~Dlist( )
{
    removeAll( );
}

#endif