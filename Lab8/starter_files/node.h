#ifndef LAB8_NODE_H
#define LAB8_NODE_H

#include <iostream>
class tooManyChildren
{
};
class invalidIndex
{
};
class Node
{
    // OVERVIEW: a node in the n-Ary tree, can also represent a n-ary tree rooted at 'this'
private:
    int    value;     // the integer value of this
    int    child_num; // the number of child of this
    int    n;         // n for this n-Ary tree
    Node  *parent;    // parent node of this, for root node, parent = NULL
    Node **children;
    // children is an array of pointer to Node. Therefore, children is a pointer of pointer
    int height; // height of this node

    void addChild( Node *child )
    // REQUIRES: n of the child node is the same with n of this
    // EFFECTS: add the node child to the children array
    //          throw an exception tooManyChildren when child_num exceed n
    {
        updateHeight( );
        if ( child_num + 1 > n )
        {
            // this->~Node( );
            delete child;
            throw tooManyChildren( );
        }
        children [ child_num ] = child;
        child_num++;
    }
    Node( int _value, int _n, Node *_parent )
        : value( _value )
        , child_num( 0 )
        , n( _n )
        , parent( _parent )
        , children( new Node *[ _n ] )
        , height( 0 )
    {
    }
    void updateHeight( )
    {
        height = getHeight( );
        if ( parent != nullptr )
        {
            parent->getHeight( );
        }
    }
    bool equal( Node *sub )
    {
        if ( ( this->child_num != sub->child_num ) )
        {
            return false;
        }
        bool temp = true;
        for ( auto i = 0; i < child_num; i++ )
        {
            temp = temp && ( this->children [ i ]->contain( sub->children [ i ] ) );
        }
        temp = temp && ( this->value == sub->value );
        return temp;
    }

public:
    Node( int _value, int _n = 2 )
        : value( _value )
        , child_num( 0 )
        , n( _n )
        , parent( nullptr )
        , children( new Node *[ _n ] )
        , height( 0 )
    // EFFECTS: create a root node with value and n
    {
    }

    ~Node( )
    // EFFECTS: destroy the whole tree rooted at sub
    {
        if ( parent != nullptr )
        {
            for ( auto i = 0; i < parent->child_num; i++ )
            {
                if ( parent->children [ i ] == this )
                {
                    if ( i != ( parent->child_num ) - 1 )
                        std::swap( parent->children [ i ], parent->children [ parent->child_num - 1 ] );
                    break;
                }
            }
            parent->children [ parent->child_num - 1 ] = nullptr;
            parent->child_num--;
        }
        // for ( auto i = 0; i < child_num; i++ )
        // {
        //     delete ( children [ i ] );
        // }
        while ( child_num != 0 )
        {
            delete ( children [ 0 ] );
        }
        delete [] children;
    }

    void addChild( int _value )
    // EFFECTS: create a child node with value and add it to the children array
    //			throw an exception tooManyChildren when child_num exceed n
    {
        if ( child_num + 1 > n )
        {
            throw tooManyChildren( );
        }
        auto *temp = new Node( _value, n, this );
        addChild( temp );
    }

    void traverse( )
    // EFFECTS: print the value of the nodes using a pre-order traversal,
    //          separated by a space.
    //          A pre-order traversal print the value of the node
    //          and then traverse its child nodes
    //          according to the sequence in children array.
    //          For example, the output of the tree above is
    //          1 2 4 5 6 8 9 3 7
    //          And the output of the tree below is
    //          1 3 5 6 2 4
    {
        std::cout << value << " ";
        for ( auto i = 0; i < child_num; i++ )
        {
            children [ i ]->traverse( );
        }
        return;
    }

    bool contain( Node *sub )
    // EFFECTS: return whether the tree rooted at sub is a subtree of this
    {
        if ( equal( sub ) )
        {
            return true;
        }

        for ( auto i = 0; i < child_num; i++ )
        {
            if ( children [ i ]->contain( sub ) )
            {
                return true;
            }
        }
        return false;
    }

    int getHeight( )
    // EFFECTS: return height of this
    {
        int maxx = -1;
        for ( auto i = 0; i < child_num; i++ )
        {
            maxx = std::max( maxx, children [ i ]->getHeight( ) );
        }
        return maxx + 1;
    }

    Node &operator[]( int i )
    // EFFECTS: return a reference of (i+1) th child node of this,
    //          e.g. node1[0] returns a reference of the first child node of node1
    //          if i is invalid, throw an invalidIndex
    {
        if ( i >= child_num )
        {
            // this->~Node( );
            throw invalidIndex( );
        }
        if ( i < 0 )
        {
            // this->~Node( );
            throw invalidIndex( );
        }

        return *( children [ i ] );
    }
};

#endif // LAB8_NODE_H
