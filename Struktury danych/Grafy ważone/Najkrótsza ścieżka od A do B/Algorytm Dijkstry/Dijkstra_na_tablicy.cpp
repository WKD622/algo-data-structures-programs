#include <iostream>
#include <conio.h>
#define n 3

using namespace std;

//STRUKTURY
struct vertex{
    int x;
    int y;
};

//FUNKCJE
void print(int D[n][n]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout.width(4);
            cout << D[i][j];
        }
        cout << endl;
    }
}
void preparation(vertex P[n][n], int D[n][n], bool V[n][n], int s1, int s2){
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++){
            D[i][j]=999;
            P[i][j].x=-1;
            P[i][j].y=-1;
            V[i][j]=false;
        }
        D[s1][s2]=0;
        P[s1][s2].x=s2;
        P[s1][s2].y=s1;
}
vertex first_unvisited(bool V[n][n]){
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (!V[i][j]){
                vertex a;
                a.x=j;
                a.y=i;
                return a;
            }
}
void cin_way(vertex P[n][n], int w, int k){
    if (P[w][k].x!=k or P[w][k].y!=w){
        cout << "("<<w<<","<<k<<")"<< endl;
        cin_way(P, P[w][k].y, P[w][k].x);
    }
}
void shortest_way(int G[n][n], int s1, int s2, int k1, int k2){
    vertex a;
    bool V[n][n];
    vertex P[n][n];
    int D[n][n];

    preparation(P,D,V,s1,s2);

    for (int b=0; b<n*n; b++){
        //getch();
        //cout << endl;
        //print(D);
        //cout << endl;
        a=first_unvisited(V);
        int a1=a.x, a2=a.y;

        for (int i=a2; i<n; i++){
            for (int j=a1; j<n; j++){
                if (!V[i][j] and D[i][j]<D[a2][a1]){
                    a1=j;
                    a2=i;
                }
            }
        }
        if (a1>0){
            if (D[a2][a1-1]>D[a2][a1]+G[a2][a1-1]){
                D[a2][a1-1]=D[a2][a1]+G[a2][a1-1];
                P[a2][a1-1].x=a1;
                P[a2][a1-1].y=a2;
            }
        }
        if (a1<n-1){
            if(D[a2][a1+1]>D[a2][a1]+G[a2][a1+1]){
                D[a2][a1+1]=D[a2][a1]+G[a2][a1+1];
                P[a2][a1+1].x=a1;
                P[a2][a1+1].y=a2;
            }
        }
        if (a2>0){
            if(D[a2-1][a1]>D[a2][a1]+G[a2-1][a1]){
                D[a2-1][a1]=D[a2][a1]+G[a2-1][a1];
                P[a2-1][a1].x=a1;
                P[a2-1][a1].y=a2;
            }
        }
        if (a2<n-1){
            if(D[a2+1][a1]>D[a2][a1]+G[a2+1][a1]){
                D[a2+1][a1]=D[a2][a1]+G[a2+1][a1];
                P[a2+1][a1].x=a1;
                P[a2+1][a1].y=a2;
            }
        }
        V[a2][a1]=true;
    }
    int k=n-1;   //a
    int w=n-1;   //b
    cout << "NAJKROTSZA DROGA:" << endl;
    cin_way(P,n-1,n-1);
    cout << "(0,0)"<< endl;

}

int main(){
    int G[n][n]={
    {1,1,7},
    {7,1,1},
    {7,7,1},
    };

    shortest_way(G,0,0,n-1,n-1);

    return 0;
}
