#include <iostream>
#define n 4
using namespace std;

void print(int T[n][n]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout.width(5);
            cout << T[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void torcik(int T[n][n],int k[n]){

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            T[i][j]=0;
        }
    }
    T[0][1]=3;
    T[1][2]=3;
    T[2][3]=1;

    for (int i=2; i<n; i++){
        int g=0;
        while(i+g<n){

            T[g][i+g]=max(k[g]-T[g][i+g-1],k[i+g]-T[g+1][i+g]);


            g++;
        }
    }

}

int main(){

    int t[]={5,8,5,4};
    int P[n][n];
    torcik(P,t);
    print(P);
}
