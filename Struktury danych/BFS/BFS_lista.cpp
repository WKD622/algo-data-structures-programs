#include <iostream>
#include <conio.h>
const int n=6;

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
void init(node *G[n]){
    for (int i=0; i<n; i++){
        G[i]=new node;
        G[i]->next=NULL;
        G[i]->val=i;
    }
}
void insert_edge(node *G[n], int s, int e){
    node *pom1=G[s];
    while (G[s]->next!=NULL)
        G[s]=G[s]->next;
    node *pom=new node;
    G[s]->next=pom;
    pom->val=e;
    pom->next=NULL;
    G[s]=pom1;
}
void print_graph(node *G[n]){
    node *pom[n];
    for (int i=0; i<n; i++)
        pom[i]=G[i];
    for (int i=0; i<n; i++){
        cout << G[i]->val<< " -> ";
        if (G[i]->next==NULL) cout << "NULL";
        while(G[i]->next!=NULL){
            G[i]=G[i]->next;
            cout << G[i]->val<< " -> ";
            if (G[i]->next==NULL) cout << "NULL";
        }
        cout << endl;
    }
    for (int i=0; i<n; i++)
        G[i]=pom[i];
}
void preparation(bool T2[n],int D[n], int P[n], int S){
    for (int i=0; i<n; i++){
        T2[i]=false;
        D[i]=-1;
        P[i]=-1;
    }
    T2[S]=true;
}
void print2 (int T[n]){
    cout << endl;
    for (int i=0; i<n; i++)
        cout << T[i] << " ";
    cout << endl;
}
void BFS(node *G[n], int S){
    node *Q=new node;
    Q->next=NULL;
    bool T2[n];
    int D[n];
    int P[n];
    preparation(T2,D,P,S);

    add(S,Q);
    while(!isempty(Q)){
        int u=get(Q);
        node *pom=G[u];
        while (G[u]!=NULL){
            int v=G[u]->val;
            G[u]=G[u]->next;
            if(!T2[v]){
                T2[v]=true;
                D[v]=D[u]+1;
                P[v]=u;
                add(v,Q);
            }
        }
        G[u]=pom;
    }

    cout << endl << "Tablica D: ";
    print2(D);
    cout << endl <<"Tablica P";
    print2(P);
    cout << endl;
}

int main(){
    node *G[n];
    init(G);

    insert_edge(G, 0, 1);
    insert_edge(G, 1, 3);
    insert_edge(G, 1, 2);
    insert_edge(G, 1, 4);
    insert_edge(G, 2, 0);
    insert_edge(G, 4, 5);

    BFS(G,0);

    print_graph(G);
    return 0;
}
