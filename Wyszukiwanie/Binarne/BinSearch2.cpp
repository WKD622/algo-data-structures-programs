#include <iostream>
#define n 10

using namespace std;

//FUNKCJE
void wypelnij(int T[]){
    for (int i=0; i<n; i++) T[i]=i*2;
}
int BinSearch(int T[], int p, int k, int w){
    int srodek=((k-p)/2)+p;

    if (T[srodek]==w or (w>T[srodek-1] and w<T[srodek+1])){
            return srodek;
    }
    if(p!=k){
        if (w<T[srodek])  BinSearch(T, p,srodek-1,w);
            else   BinSearch(T,srodek+1,k, w);
    }
}

//PROGRAM
int main(){

    int p[n];
    wypelnij(p);
    cout << BinSearch(p, 0, n-1, 5);

    return 0;
}
