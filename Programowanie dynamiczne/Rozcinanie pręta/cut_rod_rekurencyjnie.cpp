#include <iostream>

using namespace std;

int cut_rod(int p[10], int q, int l){
    if (l==0) return 0;
    q=0;
    for (int i=1; i<=l; i++)
        q=max(q,p[i-1]+cut_rod(p,q,l-i));

    return q;
}

int main(){
    int p[10]={1,5,8,9,10,17,17,20,24,30};

    cout << "MAKSYMALNA WARTOSC: " << cut_rod(p,0,9);

    return 0;
}
