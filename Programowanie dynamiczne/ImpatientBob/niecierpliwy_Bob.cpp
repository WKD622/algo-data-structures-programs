#include <iostream>
#include "stdafx.h"
#define n 5
#define k 3
using namespace std;

//STRUKTURY
struct Job{
    int start;
    int ends;
};


//FUNKCJE
void print(int T[n][k+1]){
    for (int i=0; i<n; i++){
        for (int j=0; j<k+1; j++){
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
}
int Bob(Job J[]){
    int T[n][k+1];
    for (int i=0; i<n; i++){
        for (int j=0; j<k+1; j++){
            if (j==0 or j==1) T[i][j]=0;
                else T[i][j]=999;
        }
    }

    for (int j=2; j<=k; j++){
        for (int i=0; i<n; i++){
            for (int l=0; l<i; l++){
                if (J[i].start>=J[l].ends)
                    T[i][j]=min(T[i][j],T[l][j-1]+J[i].start-J[l].ends);
            }
        }
    }
    if (T[n-1][k]==999) return -1;
        else return T[n-1][k];
}

int main(){
    Job J[n];
    J[0].start=1;
    J[0].ends=3;
    J[1].start=2;
    J[1].ends=5;
    J[2].start=4;
    J[2].ends=7;
    J[3].start=6;
    J[3].ends=9;
    J[4].start=8;
    J[4].ends=10;

    cout << Bob(J);

    return 0;
}
