#ifndef LAB5_EX1_H
#define LAB5_EX1_H

#include "recursive.h"

int dot(list_t v1, list_t v2);
// REQUIRES: Both "v1" and "v2" are non-empty
//
// EFFECTS: Treats both lists as vectors. Returns the dot
//          product of the two vectors. If one list is longer
//          than the other, ignore the longer part of the vector.


list_t filter(list_t list, bool (*fn)(int));
// EFFECTS: Returns a list containing precisely the elements of "list"
//          for which the predicate fn() evaluates to true, in the
//          order in which they appeared in list.
//
//          For example, if predicate bool odd(int a) returns true
//          if a is odd, then with input ( 3 4 1 5 6 ) and bool odd(int a),
//          you would get the list ( 3 1 5 ).

bool is_palindrome_list(list_t list);
// EFFECTS: Returns if the list is a palindrome list, which means the list
//          reads the same both ways. An empty list and a list containing only 
//          one element is still considered as a palindrome list.
//
//          For example, ( 32 32 4 1 4 32 32 ) is a palindrome list, while 
//          ( 23 4 1 4 32 ) is not a palindrome list.
#endif