#include <iostream>
#define n 6
using namespace std;

//KOLEJKA
struct node {
    int val;
    node *next;
};
void add (int w, node*q){
    node *pom=new node;
    pom->val=w;
    //cout << "pom->val=" << pom->val<< endl;
    pom->next=q->next;
    q->next=pom;
}
int get (node *q){
    while (q->next->next!=NULL)
        q=q->next;
    node *pom=q;
    pom=q->next;
    q->next=NULL;
    return pom->val;
}
bool isempty (node *q){
    if (q->next==NULL)
        return true;
    return false;
}

//FUNKCJE
void preparation(int T2[n],int D[n], int P[n], int S){
    for (int i=0; i<n; i++){
        T2[i]=0;
        D[i]=-1;
        P[i]=-1;
    }
    T2[S]=1;
    P[S] = S;
}
void print (int G[n][n]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << G[i][j] << " ";
        }
    cout << endl;
    }
}
void print2 (int T[n]){
    cout << endl;
    for (int i=0; i<n; i++)
        cout << T[i] << " ";
    cout << endl;
}
bool BFS (int G[n][n], int S){
    node *Q=new node;
    Q->next=NULL;
    int T2[n];
    int D[n];
    int P[n];
    int c=1;
    preparation(T2,D,P,S);

    add(S,Q);
    while(!isempty(Q)){
        int u=get(Q);
        int d=c;
        if (T2[u]==1) d=1;
            else d=2;
        if (T2[u]==1) c=2;
            else  c=1;
        for (int i=0; i<n; i++){
            if (G[u][i]==1){
                G[i][u]=2;
                if(T2[i]==d)
                    return false;
                int v=i;
                if(T2[v]==0){
                    T2[v]=c;
                    D[v]=D[u]+1;
                    P[v]=u;
                    add(v,Q);
                }
            }
        }
    }
    cout << endl << "TABLICA ODLEGLOSCI: ";
    print2(D);
    cout << endl <<"TABLICA PARENTOW:";
    print2(P);
    cout << endl << "TABLICA KOLORKOW:";
    print2(T2);
    return true;
}


int main(){

    int G[n][n]={
    {-1,0,0,1,0,1},
    {0,-1,1,0,0,0},
    {0,1,-1,1,0,0},
    {1,0,1,-1,1,0},
    {0,0,0,1,-1,0},
    {1,0,0,0,0,-1},
    };

    cout << "GRAF" << endl;
    print(G);


    if (BFS(G,0)) cout << endl << "!!!!  GRAF DWUDZIELNY  !!!!";
        else cout << "TO NIE JEST GRAF DWUDZIELNY.";



    return 0;

}

