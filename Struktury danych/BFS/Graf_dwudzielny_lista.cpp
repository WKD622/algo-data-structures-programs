#include <iostream>
#include <conio.h>
const int n=5;

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
void preparation(int T2[n],int D[n], int P[n], int S){
    for (int i=0; i<n; i++){
        T2[i]=0;
        D[i]=-1;
        P[i]=-1;
    }
    T2[S]=1;
    P[S] = S;
}
void print2 (int T[n]){
    cout << endl;
    for (int i=0; i<n; i++)
        cout << T[i] << " ";
    cout << endl;
}
bool BFS(node *G[n], int S){
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
        int d;
        if (T2[u]==1) d=1;
            else d=2;
        if (T2[u]==1) c=2;
            else  c=1;

        node *pom=G[u];
        while (G[u]->next!=NULL){
            G[u]=G[u]->next;
            int v=G[u]->val;
            if(T2[v]==d){
                G[u]=pom;
                return false;
            }
            if(T2[v]==0){
                T2[v]=c;
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
    return true;
}

int main(){
    node *G[n];
    init(G);


    insert_edge(G, 0, 3);
    insert_edge(G, 3, 0);
    insert_edge(G, 0, 4);
    insert_edge(G, 4, 0);
    insert_edge(G, 1, 3);
    insert_edge(G, 3, 1);
    insert_edge(G, 3, 2);
    insert_edge(G, 2, 3);

    if (BFS(G,0)) cout << endl << "!!!!  GRAF DWUDZIELNY  !!!!" << endl << endl;
        else cout << "TO NIE JEST GRAF DWUDZIELNY." << endl << endl;

    print_graph(G);

}
