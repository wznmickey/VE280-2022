//
// Created by cyx on 20-5-29.
//

#ifndef INTLIST_IMPL_H
#define INTLIST_IMPL_H

#include "mylist.h"
#include <cstdio>
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
    // std::cout << "here102" << std::endl;

    while ( first != nullptr )
    {
        // std::cout << "here103" << std::endl;

        // std::cout<<"here2"<<std::endl;
        auto temp = first->next;
        // std::cout << "here104" << std::endl;

        // std::cout<<first->val<<std::endl;
        // return;
        delete first;
        // std::cout << "here105" << std::endl;

        // std::cout<<"here10"<<std::endl;

        first = temp;
    }

    last = nullptr;
    return;
}

template < class T > void List< T >::copyFrom( const List &l )
{
    removeAll( );
    first               = nullptr;
    last                = nullptr;
    auto         temp   = l.first;
    Node_t< T > *before = nullptr;
    if ( temp != nullptr )
    {
        while ( true )
        {
            auto newTemp  = new Node_t< T >;
            newTemp->val  = temp->val;
            newTemp->next = nullptr;
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
        first       = new Node_t< T >;
        first->val  = val;
        first->next = nullptr;
        last        = first;
        return;
    }
    auto temp  = last;
    last       = new Node_t< T >;
    last->val  = val;
    last->next = nullptr;
    temp->next = last;
    return;
}

template < class T > T List< T >::removeFront( )
{
    if ( first == nullptr )
    {
        throw EmptyList( );
    }
    auto ans  = first->val;
    auto temp = first;
    first     = first->next;
    // std::cout<<"here3"<<std::endl;

    delete temp;
    return ans;
}

template < class T > const Node_t< T > *List< T >::returnFront( ) const
{
    auto temp = first;
    return temp;
}

template < class T > List< T >::List( )
{
    // std::cout << "here1000" << std::endl;

    first = nullptr;
    last  = nullptr;
    // std::cout<<"init one"<<std::endl;
} // constructor
template < class T > List< T >::List( const List &l )
{
    // std::cout<<"init two"<<std::endl;
    if ( this == &l )
    {
        return;
    }
    first = nullptr;
    last  = nullptr;
    removeAll( );
    copyFrom( l );
    return;
} // copy constructor
template < class T > List< T > &List< T >::operator=( const List &l )
{

    // std::cout << ( first == nullptr ) << true << std::endl;

    // std::cout << "here100" << std::endl;

    // std::cout<<"init three"<<std::endl;
    removeAll( );
    // std::cout << "here101" << std::endl;

    if ( this == &l )
        return *this;
    this->copyFrom( l );
    return *this;
} // assignment operator
template < class T > List< T >::~List( )
{
    // std::cout<<"destory one"<<std::endl;

    // std::cout<<"here1"<<std::endl;
    removeAll( );
    return;
} // destructor
bool isLarger( const List< int > &a, const List< int > &b )
{
    int         ans = 0; // 0 - equal, -1 smaller ,1 - larger
    List< int > aC;
    List< int > bC;
    aC = a;
    bC = b;
    while ( true )
    {
        int aV = 0;
        int bV = 0;
        if ( ! aC.isEmpty( ) )
        {
            aV = aC.removeFront( );
        }
        if ( ! bC.isEmpty( ) )
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
        if ( aC.isEmpty( ) && bC.isEmpty( ) )
        {
            break;
        }
    }
    return ( ans == 1 );
}
List< int > add( const List< int > &a, const List< int > &b )
{
    // std::cout << "here3" << std::endl;

    List< int > ans;
    int         remain = 0;
    // std::cout << "here4" << std::endl;
    List< int > aC = a;
    List< int > bC = b;
    // aC = a;
    // std::cout << "here5" << std::endl;

    // bC = b;
    while ( true )
    {
        if ( ! aC.isEmpty( ) )
        {
            remain += aC.removeFront( );
        }

        if ( ! bC.isEmpty( ) )
        {
            remain += bC.removeFront( );
        }
        // std::cout << remain << " " << std::endl;
        ans.insertBack( remain % 10 );
        remain = remain / 10;
        if ( ( remain == 0 ) && ( aC.isEmpty( ) ) && ( bC.isEmpty( ) ) )
        {
            return ans;
        }
    }
}

#endif // INTLIST_IMPL_H
