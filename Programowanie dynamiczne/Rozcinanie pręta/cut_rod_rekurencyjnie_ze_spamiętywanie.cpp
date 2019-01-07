#include <iostream>

using namespace std;

int cut_rod(int p[10], int r[10], int q, int l){
    if (r[l]!=-1) return r[l];
    if (l==0) return 0;

    q=0;
    for (int i=1; i<=l; i++)
        q=max(q,p[i-1]+cut_rod(p,r,q,l-i));
    r[l]=q;

    return q;
}

int main(){
    int p[10]={1,5,8,9,10,17,17,20,24,30};
    int r[10];
    for (int i=0; i<10; i++){
        r[i]=-1;
    }

    cout << "MAKSYMALNA WARTOSC: " << cut_rod(p,r,0,4);

    return 0;
}
