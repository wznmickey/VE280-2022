#include <bits/stdc++.h>
#include "dict.h"
using namespace std;

int main()
{
    Dict<string,int> a;
    a.insert("1",1);
    a.insert("2", 2);
    a.insert("1", 3);
    std::cout<<a.size();
    std::cout<<*(a.find("1"));
    a.remove("1");
}
