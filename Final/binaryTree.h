#ifndef BINARYTREE_H
#define BINARYTREE_H

// DON'T MODIFY THIS HEADER FILE

class BinaryTree{
   bool empty; // Flag indicating if tree is empty or not
   int v; // value stored in root node if non-empty tree
   BinaryTree *left; // Dynamically allocated
   BinaryTree *right; // Dynamically allocated

public:
   BinaryTree();
   // EFFECTS: builds an empty binary tree
   BinaryTree(int v, const BinaryTree &lChild,
         const BinaryTree &rChild); // TODO
   // EFFECTS: builds a new tree whose root contains
   //          value v, its left subtree is a deep copy of
   //          lChild, its right subtree is a deep copy of
   //          rChild
   BinaryTree(const BinaryTree &bt); // TODO
   // EFFECTS: deep copy constructor from binary tree bt
   BinaryTree &operator=(const BinaryTree &bt); // TODO
   // MODIFIES: this
   // EFFECTS: deep copies from binary tree bt
   ~BinaryTree();

   void removeAll();
   // MODIFIES: this
   // EFFECTS: deallocates all the subtrees and makes tree empty

   bool isSorted() const; // TODO
   // EFFECTS: returns true if the binary tree is such
   //          that v in the root node is larger or equal
   //          to any values in the nodes of the left
   //          subtree, and it is smaller or equal to
   //          any values in the nodes of the right
   //          subtree.
   //          This ordering property applies recursively
   //          to the left and right subtrees.

   int count() const; // TODO
   // EFFECTS: returns the number of elements in the tree
};

#endif
