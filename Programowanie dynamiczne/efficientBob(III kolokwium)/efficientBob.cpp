#include <iostream>
#define k 3
#define n 5

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
void efficientBob(Job J[]){
    int T[n][k+1], P[n][k+1];
    for (int i=0; i<n; i++){
        for (int j=0; j<k+1; j++){
            if (j==0){
                    T[i][j]=0;
                    P[i][j]=999;
                }
                else if (j==1) {
                        T[i][j]=J[i].ends-J[i].start;
                        P[i][j]=999;
                }
                    else T[i][j]=P[i][j]=999;
        }
    }
    for (int j=2; j<=k; j++){
        for (int i=0; i<n; i++){
            for (int l=0; l<i; l++){
                if (J[i].start>=J[l].ends && T[i][j]>T[l][j-1]+J[i].ends-J[l].ends){
                    T[i][j]=T[l][j-1]+J[i].ends-J[l].ends;
                    P[i][j]=l;
                }
            }
        }
    }
    print(T);
    int i=n-1, j=k;
    for(int l=0; l<n; l++)
        if(T[l][k]<T[i][k])
            i=l;
    while(i!=999){
        cout << i <<endl;
        i=P[i][j];
        j--;
    }
}

//MAIN
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

    efficientBob(J);

    return 0;
}
