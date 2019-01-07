//ALGORYTM PRIMA
//Z³o¿onoœæ czasowa O(E * logV)
#include <iostream>
#define n 6

using namespace std;


//STOS
struct node {
    int val;
    node *next;
};
node* createS(node*S){
    node*W=new node;
    S=W;
    S->next=NULL;
}
node* emptyS(node*S){
S->next=NULL;
return S;
}
void printS(node*S){
    S=S->next;
    while(S){
        cout<<S->val<<" ";
        S=S->next;
    }
}
void push(node*S,int w){
    node*pom=new node;
    pom->next = S->next;
    pom->val=w;
    S->next=pom;
}
int pop(node*S){
    if(S->next){
        node*pom=S->next;
        S->next = pom->next;
        int a = pom->val;
        delete pom;
        return a;
    }
}

//FUNKCJE
void preparation (bool T[n], int S){
    for (int i=0; i<n; i++)
        T[i]=false;
    T[S]=true;
}
bool all_visited(bool T[n]){
    for (int i=0; i<n; i++)
        if (!T[i]) return false;
    return true;
}
void Prim(int V, int G[n][n]){
    bool T[n];
    preparation(T,V);
    int Min, w,k;
    node *S=createS(S);

    while (!all_visited(T)){
        Min=32000;
        for (int i=0; i<n; i++){
            if (T[i]){
                for (int j=0; j<n; j++){
                    if (G[i][j] > 0){
                        if (G[i][j]<Min and !T[j]){
                            Min=G[i][j];
                            w=i;
                            k=j;
                        }
                    }
                }
            }
        }
        T[k]=true;
        push(S,w);
        push(S,k);

        while (G[w][k]>0){
            G[w][k]--;
            G[k][w]--;
        }

    }
    cout << "NAJMNIEJSZE DRZEWO ROZPINAJACE - KRAWEDZIE WIERZCHOLKAMI (DWOJKAMI S-E):" << endl;
    printS(S);
}

int main(){

    int G[n][n]={
    {-1,3,8,4,5,0},
    {3,-1,5,0,0,0},
    {8,5,-1,0,0,0},
    {4,0,0,-1,4,9},
    {5,0,0,4,-1,8},
    {0,0,0,9,8,-1},
    };

    Prim(5,G);
    return 0;

}
