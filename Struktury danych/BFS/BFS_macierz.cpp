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
void preparation(bool T2[n],int D[n], int P[n], int S){
    for (int i=0; i<n; i++){
        T2[i]=false;
        D[i]=-1;
        P[i]=-1;
    }
    T2[S]=true;
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
void BFS (int G[n][n], int S){
    node *Q=new node;
    Q->next=NULL;
    bool T2[n];
    int D[n];
    int P[n];
    preparation(T2,D,P,S);

    add(S,Q);
    while(!isempty(Q)){
        int u=get(Q);
        for (int i=0; i<n; i++){
            if (G[u][i]==1){
                int v=i;
                if(!T2[v]){
                    T2[v]=true;
                    D[v]=D[u]+1;
                    P[v]=u;
                    add(v,Q);
                }
            }
        }
    }
    cout << endl << "Tablica D: ";
    print2(D);
    cout << endl <<"Tablica P";
    print2(P);
    cout << endl;
}

int main(){

    int G[n][n]={
    {-1,1,0,0,0,0},
    {0,-1,1,1,1,0},
    {1,0,-1,0,0,0},
    {0,0,0,-1,0,0},
    {0,0,0,0,-1,1},
    {0,0,0,0,0,-1},
    };

    BFS(G,0);

    print(G);

    return 0;
}
