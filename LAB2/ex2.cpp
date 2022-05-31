#include <cmath>
#include <iostream>

using namespace std;

int const MAX_LEN=1024;

int square[MAX_LEN][MAX_LEN];

const int MAP[]={
    1,2,4,8,16,32,64,128,256,512,1024,2048,4096,2*4096,4*4096,8*4096,16*4096
};

void initSquare(int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            square[i][j] = 1;
        }
    }
}

// REQUIRES: the square with left-upper corner at (x,y)
//           and length len is within square[MAX_LEN][MAX_LEN]
// MODIFIES: square[][]
// EFFECTS: fully update the specified square
void updateSquare(int xl, int yl, int xr,int yr ) {
    if (xr-xl==0){
        return;
    }
    int xm = (xl+xr)/2;
    int ym = (yl+yr)/2;
    // updateSquare(xm+1,yl,xr,ym);
    for (int i=xm+1;i<=xr;i++)
    {
        for (int j=yl;j<=ym;j++)
        {
            square[i][j]=0;
        }
    }
    updateSquare(xl, yl, xm, ym);
    updateSquare(xl,ym+1,xm ,yr);
    updateSquare(xm+1, ym+1, xr,yr);
    return;
}

void printSquare(int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            cout << square[j][i] << " ";
        }
        cout << endl;
    }
}

auto main() -> int {
    // TODO: read input
    int n=0;
    cin>>n;
    int len = MAP[n];
    initSquare(len);
    // TODO: init, update, and print square
    updateSquare(0,0,len-1,len-1);
    printSquare(len);
    return 0;
}
