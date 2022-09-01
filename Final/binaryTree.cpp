#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include "binaryTree.h"

BinaryTree *getCopy( const bool empty, const int v, const BinaryTree &left, const BinaryTree &right )
{
    if ( empty )
    {
        return new BinaryTree( );
    }
    return new BinaryTree( v, left, right );
}

BinaryTree::BinaryTree( int v, const BinaryTree &lChild, const BinaryTree &rChild )
    : empty( false )
    , v( v )
    , left( getCopy( lChild.empty, lChild.v, *lChild.left, *lChild.right ) )
    , right( getCopy( rChild.empty, rChild.v, *rChild.left, *rChild.right ) )
{
}
BinaryTree::BinaryTree( const BinaryTree &bt )
    : empty( bt.empty )
{
    if ( empty )
    {
        return;
    }
    left  = getCopy( bt.left->empty, bt.left->v, *bt.left->left, *bt.left->right );
    right = getCopy( bt.right->empty, bt.right->v, *bt.right->left, *bt.right->right );
    v     = bt.v;
}
BinaryTree &BinaryTree::operator=( const BinaryTree &bt )
{
    this->removeAll( );
    empty = bt.empty;
    if ( empty )
    {
        return *this;
    }
    left  = getCopy( bt.left->empty, bt.left->v, *bt.left->left, *bt.left->right );
    right = getCopy( bt.right->empty, bt.right->v, *bt.right->left, *bt.right->right );
    v     = bt.v;
    return *this;
}
bool BinaryTree::isSorted( ) const
{ // I know it is wrong but I do not know how to write a helper function to get private member recursively for 15 line limit
    if ( empty )
    {
        return true;
    }
    if ( ! ( ( ( left->empty ) || ( ( ! ( left->empty ) ) && ( v >= left->v ) ) )
             && ( ( right->empty ) || ( ( ! ( right->empty ) ) && ( v <= right->v ) ) ) ) )
    {
        return false;
    }
    return ( left->isSorted( ) ) && ( right->isSorted( ) );
}
int BinaryTree::count( ) const
{
    if ( empty )
    {
        return 0;
    }
    return 1 + left->count( ) + right->count( );
}
#endif