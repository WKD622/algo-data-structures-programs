#include <conio.h>
#include <iostream>
#define n 6

using namespace std;

void print_G(int G[n][n]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout.width(4);
            cout << G[i][j];
        }
    cout << endl;
    }
}
void algorytm_Floyda_Warshalla(int G[n][n]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (G[i][j]==0) G[i][j]=999;
        }
    }


        for (int j=0; j<n; j++){
            if (G[j][j]==-1) G[j][j]=0;
        }


    print_G(G);

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
            }
    }
    cout << endl;
    print_G(G);
}

int main(){
    int G[n][n]={
    {-1,0,2,0,0,0},
    {1,-1,0,0,0,0},
    {0,-2,-1,0,0,0},
    {-4,0,-1,-1,1,0},
    {0,0,0,0,-1,0},
    {10,0,0,9,8,-1},
    };

    algorytm_Floyda_Warshalla(G);

    return 0;
}
