#include <iostream>
#define n 11

using namespace std;

//STRUKTURY
struct Job{
    int start;
    int ends;
};

//FUNKCJE
void print(int T[n][n+1]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n+1; j++)
            cout << T[i][j] << " ";
        cout << endl;
    }
}
int maks_zad(Job J[]){
    int T[n][n+1];
    for (int i=0; i<n; i++){
        for (int j=0; j<n+1; j++)
            if (j==1) T[i][j]=1;
                else T[i][j]=0;
    }
    int maks=1;
    for (int i=2; i<n; i++){
        for (int j=i; j<n+1; j++){
            for (int l=0; l<j; l++){
                if (J[l].ends<J[j].start){
                    T[i][j]=max(T[i][j],T[i-1][l]+1);
                    if (T[i][j]>maks) maks = T[i][j];
                }
            }
        }
    }
    print(T);
    return maks;
}

int main(){
    Job J[n];
    J[0].start=1;
    J[0].ends=4;
    J[1].start=3;
    J[1].ends=5;
    J[2].start=0;
    J[2].ends=6;
    J[3].start=5;
    J[3].ends=7;
    J[4].start=3;
    J[4].ends=9;
    J[5].start=5;
    J[5].ends=9;
    J[6].start=6;
    J[6].ends=10;
    J[7].start=8;
    J[7].ends=11;
    J[8].start=8;
    J[8].ends=12;
    J[9].start=2;
    J[9].ends=14;
    J[10].start=12;
    J[10].ends=16;

    cout << maks_zad(J);


    return 0;
}
