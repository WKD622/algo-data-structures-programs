#include <iostream>
#define n 5         //LICZBA WIERZCHOLKOW

using namespace std;

//STRUKTURY
struct node{
    int s;          //START
    int e;          //END
    int val;
    node *next;
};

//STOS
int count_edges(node *G){
    int i=0;
    while(G){
        i++;
        G=G->next;
    }
    return i;
}
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
node* init_graph(int S, int E, int Val, node*&G){
    G=new node;
    G->val=Val;
    G->s=S;
    G->e=E;
    G->next=NULL;
    return G;
}
void insert_edge(int S, int E, int Val, node *&G){
    node *pom=new node;
    pom->next=G;
    G=pom;
    G->val=Val;
    G->s=S;
    G->e=E;
}
void print_graph(node *G){
    while(G){
        cout << G->val << " ";
        G=G->next;
    }
}
void preparation(bool visited[n], int S){
    for (int i=0; i<n; i++){
        visited[i]=false;
    }
    visited[S]=true;
}
bool all_visited(bool visited[n]){
    for (int i=0; i<n; i++)
        if (visited[i]==false) return true;

    return false;
}
void algorytm_Prima(node* G, int S){
    node *Z=createS(Z);
    bool visited[n];
    preparation(visited,S);
    int m=count_edges(G);
    int w1,w2, Min;
    for (int d=0; d<n; d++){
        Min=32000;
        for (int i=0; i<n; i++){
            node*pom=G;
            if (visited[i]){
                while(G){
                    if (G->s==i and visited[G->e]==false){
                        if (G->val<Min){
                            w1=G->e;
                            w2=G->s;
                            Min=G->val;
                        }
                    }
                    else if (G->e==i and visited[G->s]==false){
                        if (G->val<Min){
                            w1=G->s;
                            w2=G->e;
                            Min=G->val;
                        }
                    }
                    G=G->next;
                }
            }
            G=pom;
        }
        if (visited[w1]==false){
            push(Z,w2);
            push(Z,w1);
        }
        visited[w1]=true;
    }
    printS(Z);
}

//PROGRAM
int main(){
    node *G=init_graph(0,1,1,G);
    insert_edge(1,2,1,G);
    insert_edge(2,0,1,G);
    insert_edge(2,0,2,G);

    algorytm_Prima(G,0);



    return 0;
}


