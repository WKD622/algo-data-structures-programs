#include <iostream>
#define n 1000

using namespace std;

//FUNKCJE
void wypelnij(int T[]){
    for (int i=0; i<n; i++) T[i]=i;
}
void BinSearch(int T[], int p, int k, int w, bool &znalazlem){
    int srodek=((k-p)/2)+p;

    if (T[srodek]==w){
            znalazlem=true;
            return;
    }
    if(p!=k){
        if (w<T[srodek])  BinSearch(T, p,srodek-1,w,znalazlem);
            else   BinSearch(T,srodek+1,k, w, znalazlem);
    }
}

//PROGRAM
int main(){
    bool wyszukaj=false;
    int p[n];
    wypelnij(p);
    BinSearch(p, 0, n-1, 768 , wyszukaj);
    if (wyszukaj) cout << "znalazlem";
        else cout << "nie znalazlem";

    return 0;
}
