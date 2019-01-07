//ALGORYTM ZWRACA DORZEWO ROZPINAJACE O NAJMNIEJSZEJ WADZE
//GRAF - SPOJNY, WAZONY, NIESKIEROWANY
//Zlozonosc czasowa O(E * logV)
#include <conio.h>
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

//STRUKTURY
struct edge{
    int s,e,w;
};

//FUNKCJE
void preparation(int T[n]){
    for (int i=0; i<n; i++){
        T[i]=-1;
    }
}
void make_set( int T[n], int w){
    T[w]=w;
}
int find_set(int T[n], int w){
    if (T[w]==-1) return -1;
    while(T[w]!=w) {
        w=T[w];
    }
    return w;
}
void union_sets(int T[n], int x, int y){
    int z1=find_set(T,x);
    int z2=find_set(T,y);
        if (z1!=z2){
            T[z2]=z1;
        }
}
int count_edges(int G[n][n]){
    int licznik=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            G[i][j]=G[i][j];
            if (G[i][j]>0){
                licznik++;
            }
        }
    }
    return licznik/2;
}
void print_K(edge K[], int l){
    for (int i=0; i<l; i++){
        cout << "S=" <<K[i].s << ", E=" << K[i].e << ", W=" << K[i].w << endl;
    }
}
void print_T(int T[n]){
    cout << endl;
    for (int i=0; i<n; i++){
        cout.width(3);
        cout << T[i];
    }
    cout << endl;

    for (int i=0; i<n; i++){
        cout.width(3);
        cout << i;
    }
    cout << endl;
}
void G_to_K(edge K[], int G[n][n]){
    int p=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (G[i][j]>0){
                K[p].s=i;
                K[p].e=j;
                K[p].w=G[i][j];
                p++;
                while (G[i][j]>0){
                    G[i][j]--;
                    G[j][i]--;
                }
            }
        }
    }
}
void bubble_sort_by_weight(edge K[], int l){
    for (int i=0; i<l; i++){
        for (int j=0; j<l-1; j++){
            if (K[j].w>K[j+1].w){
                edge pom= K[j];
                K[j]=K[j+1];
                K[j+1]=pom;
            }
        }
    }
}
bool end_krus(int T[n]){
    for (int i=0; i<n-1; i++){
        if (find_set(T,i)==-1 or find_set(T,i+1)==-1 or find_set(T,i)!=find_set(T,i+1))
            return false;
    }
    return true;
}
void Kruskal(edge K[], int T[n], int l, node *&S){
    while(1){
        if (T[K[i].s]==-1) make_set(T, K[i].s);
        if (T[K[i].e]==-1) make_set(T, K[i].e);
        if (T[K[i].s]!=T[K[i].e]){
            push(S,K[i].s);
            push(S,K[i].e);
        }
        print_T(T);
        getch();
        union_sets(T,K[i].s, K[i].e);
        print_T(T);
        getch();
        if (end_krus(T)){
            cout << "NAJMNIEJSZE DRZEWO ROZPINAJACE - KRAWEDZIE WIERZCHOLKAMI (DWOJKAMI S-E):" << endl;
            printS(S);
            return;
        }
    }
}

int main(){
    int T[n];
    int G[n][n]={
    {-1,3,8,4,5,0},
    {3,-1,5,0,0,0},
    {8,5,-1,0,0,0},
    {4,0,0,-1,4,9},
    {5,0,0,4,-1,8},
    {0,0,0,9,8,-1},
    };

    node *S=createS(S);
    preparation(T);
    int l=count_edges(G);
    edge *K=new edge[l];
    G_to_K(K,G);
    bubble_sort_by_weight(K,l);
    Kruskal(K,T,l,S);

    return 0;

}
