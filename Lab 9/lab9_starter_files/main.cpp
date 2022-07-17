#include "mylist_impl.h"
int main()
{
//     List<int> a;
// a.insertBack(4); // 4(first & last)
// a.insertBack(1); // 4(first) -> 1(last)
// a.insertBack(3); // 4(first) -> 1 -> 3(last)
// a.removeFront(); // 1(first) -> 3(last)
// a.print();
List<int> a, b;
a.insertBack(5);
a.insertBack(3); // a = 35
b.insertBack(2);
b.insertBack(4); // b = 42
a.print();
b.print();
std::cout<<"here1"<<std::endl;
List<int> ab_sum = add(a, b); // ab_sum = 77
std::cout<<"here2"<<std::endl;
ab_sum.print();
}