//Z³o¿onoœæ czasowa:
//O(E * logV)
//O(E + V * logV) – przy u¿yciu kopca Fibonacciego

#include <iostream>
#include <conio.h>
#define n 6

using namespace std;

void preparation(int d[n], int p[n], bool v[n], int S){
    for (int i=0; i<n; i++){
        d[i]=32767; //nieskonczonosc
        p[i]=-1;
        v[i]=false;
    }
    d[S]=0;
}
void print (int T[n]){
    cout << endl;
    for (int i=0; i<n; i++){
        cout.width(3);
        cout << T[i];
    }
}
int first_unvisted(bool v[n], int d[n]){
    for (int i=0; i<n; i++){
        if (!v[i]) return i;
    }
    return -1;
}
void algorytm_Dijkstry(int G[n][n], int S){
    bool v[n];
    int p[n], d[n],k;
    preparation(d,p,v,S);


    for (int b=0; b<n; b++){
        k=first_unvisted(v,d);
        for (int i=k+1; i<n-1; i++)
            if (!v[i+1] and d[i+1]<d[i]) k=i+1;  //NAJMNIEJSZA WAGA UNVISITED
        v[k]=true;

        for (int i=0; i<n; i++){
            if (G[k][i]>0 and d[i]>(d[k]+G[k][i])){
                p[i]=k;
                d[i]=d[k]+G[k][i];
            }
        }
    }
    cout << "TABLICA D: ";
    print(d);
    cout << endl << "TABLICA P: ";
    print(p);
}

int main(){
    int G[n][n]={
    {-1,3,0,0,3,0},
    {0,-1,1,0,0,0},
    {0,0,-1,3,0,1},
    {0,3,0,-1,0,0},
    {0,0,0,0,-1,2},
    {6,0,0,1,0,-1},
    };

    algorytm_Dijkstry(G,0);

    return 0;
}
