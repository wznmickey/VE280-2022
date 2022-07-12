//
// Created by cyx on 20-5-29.
//

#ifndef LIST_H
#define LIST_H

// an exception class
class EmptyList{};

template <class T>
struct Node_t{
    Node_t* next;
    T val;
};

// singly-linked list
template <class T>
class List{
private:

    Node_t<T>* first;
    Node_t<T>* last;

    void removeAll();
    // EFFECTS: called by destructor/operator= to remove and destroy
    //          all list elements

    void copyFrom(const List &l);
    // MODIFIES: this
    // EFFECTS: called by copy constructor/operator= to copy elements
    //          from a source list l to this list;
    //          if this list is not empty originally,
    //          removes all elements from it before copying

public:
    bool isEmpty() const;
    // EFFECTS: returns true if list is empty, false otherwise

    void insertBack(T val);
    // MODIFIES: this
    // EFFECTS: inserts val at the back of the list

    T removeFront();
    // MODIFIES: this
    // EFFECTS: removes the first element from
    //          non-empty list and returns its value
    //          throws an instance of EmptyList if empty

    const Node_t<T>* returnFront() const;
    // EFFECTS: returns first

    void print();
    // EFFECTS: print the elements in the list

    List();                                 // constructor
    List(const List &l);                    // copy constructor
    List &operator=(const List &l);         // assignment operator
    ~List();                                // destructor
};

bool isLarger(const List<int> &a, const List<int> &b);
// EFFECTS: returns true if the number represented by
//          a is larger than the number represented by b;
//          otherwise, returns false.
//          returns false if both a and b are empty

List<int> Add(const List<int> &a, const List<int> &b);
// EFFECTS: adds the numbers represented by a and b;
//          returns the result

#include "mylist_impl.h"

#endif //LIST_H
