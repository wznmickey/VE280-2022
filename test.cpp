#include<bits/stdc++.h>
using namespace std;
struct t{
    int i;
    // string st;
    char a[10];
};

int main()
{
    std::cout << std::boolalpha;
    cout<<std::is_trivially_copyable<t>::value<<endl;
    return 0;
}