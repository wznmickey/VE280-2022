#include "binaryTree.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

/* ================================== Node =================================== */
Node::Node( const std::string &str, int num, Node *left, Node *right )
    : str( str )
    , num( num )
    , left( left )
    , right( right )
{
    // TODO: implement this function.
}

Node *Node::leftSubtree( ) const
{
    // TODO: implement this function.
    return left;
}

void Node::setleft( Node *n )
{
    // TODO: implement this function.
    left = n;
    // UNSURE delete?
    return;
}

Node *Node::rightSubtree( ) const
{
    // TODO: implement this function.
    return right;
}

void Node::setright( Node *n )
{
    // TODO: implement this function.
    right = n;
    // UNSURE delete?
    return;
}

string Node::getstr( ) const
{
    // TODO: implement this function.
    return str;
}

int Node::getnum( ) const
{
    // TODO: implement this function.
    return num;
}

void Node::incnum( )
{
    // TODO: implement this function.
    ++num;
    return;
}

Node *Node::mergeNodes( Node *leftNode, Node *rightNode )
{
    // TODO: implement this function.
    return new Node( leftNode->str + rightNode->str, leftNode->num + rightNode->num, leftNode, rightNode );
}

/* =============================== Binary Tree =============================== */

BinaryTree::BinaryTree( Node *rootNode )
    : root( rootNode )
{
    // TODO: implement this function.
}

BinaryTree::~BinaryTree( )
{
    if ( root == nullptr )
    {
        return;
    }
    // TODO: implement this function.
    BinaryTree( root->leftSubtree( ) );
    BinaryTree( root->rightSubtree( ) );
    delete root;
    return;
}

string findPathNode( const Node *node, const string &s );

bool findPathDown( const Node *node, const string &s, const char p, string &ans )
{
    if ( ( node ) != nullptr )
    {
        auto temp = findPathNode( node, s );
        if ( temp != "-1" )
        {
            ans = p + temp;
            return true;
        }
    }
    return false;
}

string findPathNode( const Node *node, const string &s )
{
    if ( ( node->getstr( ) ) == s )
    {
        return "";
    }
    string st;

    // Use short cut here.

    if ( findPathDown( node->leftSubtree( ), s, '0', st ) || findPathDown( node->rightSubtree( ), s, '1', st ) )
    {
        return st;
    }

    // if ( findPathDown( node->leftSubtree( ), s, '0', st ) )
    // {
    //     return st;
    // }
    // if ( findPathDown( node->rightSubtree( ), s, '1', st ) )
    // {
    //     return st;
    // }
    return "-1";
}

string BinaryTree::findPath( const string &s ) const
{
    // TODO: implement this function.
    return findPathNode( this->root, s );
}

int sumNode( const Node *node )
{
    if ( node == nullptr )
    {
        return 0;
    }
    return sumNode( node->leftSubtree( ) ) + sumNode( node->rightSubtree( ) ) + node->getnum( );
}

int BinaryTree::sum( ) const
{
    // TODO: implement this function.
    return sumNode( this->root );
}

int depthNode( const Node *node )
{
    if ( node == nullptr )
    {
        return 0;
    }
    return std::max( depthNode( node->leftSubtree( ) ), depthNode( node->rightSubtree( ) ) ) + 1;
}

int BinaryTree::depth( ) const
{
    // TODO: implement this function.
    return depthNode( this->root );
}

void preorder_numNode( const Node *node )
{
    if ( node == nullptr )
    {
        return;
    }
    std::cout << node->getnum( ) << " ";
    preorder_numNode( node->leftSubtree( ) );
    preorder_numNode( node->rightSubtree( ) );
    return;
}

void BinaryTree::preorder_num( ) const
{
    // TODO: implement this function.
    preorder_numNode( this->root );
}

void inorder_strNode( const Node *node )
{
    if ( node == nullptr )
    {
        return;
    }
    inorder_strNode( node->leftSubtree( ) );
    std::cout << node->getstr( ) << " ";
    inorder_strNode( node->rightSubtree( ) );
    return;
}

void BinaryTree::inorder_str( ) const
{
    // TODO: implement this function.
    inorder_strNode( this->root );
}

void postorder_numNode( const Node *node )
{
    if ( node == nullptr )
    {
        return;
    }
    postorder_numNode( node->leftSubtree( ) );
    postorder_numNode( node->rightSubtree( ) );
    std::cout << node->getnum( ) << " ";
    return;
}

void BinaryTree::postorder_num( ) const
{
    // TODO: implement this function.
    postorder_numNode( this->root );
}

int allPathSumGreaterNode( const Node *node )
{
    if ( node == nullptr )
    {
        return 0;
    }
    return std::min( allPathSumGreaterNode( node->leftSubtree( ) ), allPathSumGreaterNode( node->rightSubtree( ) ) ) + node->getnum( );
}

bool BinaryTree::allPathSumGreater( int sum ) const
{
    // TODO: implement this function.
    return sum < allPathSumGreaterNode( this->root );
}

bool covered_byNode( const Node *node1, const Node *node2 )
{
    return (
        ( node1 == nullptr )
        || ( ( ! ( node2 == nullptr ) )
             && ( (
                 ( node1->getnum( ) == node2->getnum( ) ) && ( covered_byNode( node1->leftSubtree( ), node2->leftSubtree( ) ) )
                 && ( covered_byNode( node1->rightSubtree( ), node2->rightSubtree( ) ) ) ) ) ) );
    // if ( node1 == nullptr )
    // {
    //     return true;
    // }
    // if ( node2 == nullptr )
    // {
    //     return false;
    // }
    // return (
    //     ( node1->getnum( ) == node2->getnum( ) ) && ( covered_byNode( node1->leftSubtree( ), node2->leftSubtree( ) ) )
    //     && ( covered_byNode( node1->rightSubtree( ), node2->rightSubtree( ) ) ) );
}

bool BinaryTree::covered_by( const BinaryTree &tree ) const
{
    // TODO: implement this function.
    return covered_byNode( this->root, tree.root );
}

bool covered_bySub( const Node *node1, const Node *node2 )
{
    return ( covered_byNode( node1, node2 ) || covered_byNode( node1, node2->leftSubtree( ) ) || covered_byNode( node1, node2->rightSubtree( ) ) );
}

bool BinaryTree::contained_by( const BinaryTree &tree ) const
{
    // TODO: implement this function.
    return ( ( this->covered_by( tree ) ) || ( covered_bySub( this->root, tree.root ) ) );
}

Node *copyNode( const Node *node )
{
    if ( node == nullptr )
    {
        return nullptr;
    }
    return new Node( node->getstr( ), node->getnum( ), copyNode( node->leftSubtree( ) ), copyNode( node->rightSubtree( ) ) );
}

BinaryTree BinaryTree::copy( ) const
{
    // TODO: implement this function.
    return { copyNode( this->root ) };
}
