#include <iostream>
#define n 5// liczba korytarzy
#define m 4 //liczba wierzcho³ków

using namespace std;

//STRUKTURY
struct korytarz{
    int a;
    int b;
    int czas;
};

//FUNKCJE
void dodaj_korytarz(int s,int e, int time, korytarz T[], int l){
    T[l].a=s;
    T[l].b=e;
    T[l].czas=time;
}
void preparation(int d[], int p[], bool visited[], int start){
    for (int i=0; i<m; i++){
        p[i]=-1;
        d[i]=32676;
        visited[i]=false;
    }
    d[start]=0;
}
int first_unvisited(bool visited[]){
    for (int i=0; i<m; i++)
        if (visited[i]==false) return i;
}
void print (int T[]){
    for (int i=0; i<m; i++)
        cout << T[i] << " ";
    cout << endl;
}
void algorytm_Dijkstry(korytarz T[], int start){
    bool visited[m];
    int p[m];
    int d[m];
    int u;
    preparation(d,p,visited,start);

    for (int b=0; b<n; b++){
        int k=first_unvisited(visited);
        u=k;
        for (int i=k+1; i<m-1; i++){
            if (visited[i+1]==false and d[i+1]<d[i]){
                u=i+1;
            }
        }
        visited[u]=true;
        for (int i=0; i<n; i++){
            if (T[i].a==u){
                if (d[T[i].a]+T[i].czas<d[T[i].b]){
                    d[T[i].b]=d[T[i].a]+T[i].czas;
                    p[T[i].b]=T[i].a;
                }
            }
        }
    }
    cout << d[m-1];
}

//PROGRAM
int main(){
    korytarz T[n];
    dodaj_korytarz(0,1,4,T,0);
    dodaj_korytarz(0,2,7,T,1);
    dodaj_korytarz(1,2,2,T,2);
    dodaj_korytarz(1,3,8,T,3);
    dodaj_korytarz(2,3,5,T,4);
    algorytm_Dijkstry(T,0);

    return 0;
}
