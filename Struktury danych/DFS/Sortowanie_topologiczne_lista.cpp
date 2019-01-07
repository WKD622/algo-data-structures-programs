#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#define n 6

using namespace std;

int maks=-1;

//STRUKTURY
struct node{
    int val;
    node *next;
};

//STOS
node* createS(node*S){
    node*W=new node;
    S=W;
    S->next=NULL;
}
void printS(node*S){
    cout << endl;
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
void print(int t[]){
    cout << endl;
    for(int i=0;i<n;i++)
        cout<<" "<<t[i];
    cout<<endl;
}
void zeruj(int time[], int state[], int work[]){
    for (int i=0; i<n; i++){
        state[i]=0;
        time[i]=0;
        work[i]=0;
    }
}
void DFS_visit(node *G[n], int v, int time[n], int state[n], int time2, int work[n],node *S){
    time2++;
    state[v]=1;
    while(G[v]->next!=NULL){
        G[v]=G[v]->next;
        if(state[G[v]->val]==0){
            DFS_visit(G,G[v]->val,time,state, time2, work,S);
        }

    }
    push(S,v);
    if (time2>maks)
        maks = time2;
    state[v]=2;
    time[v]=time2;
    work[v]=maks-time[v];
}
void DFS(node *G[n], int time[], int state[], int work[n], node* S){
    zeruj(time,state,work);
    for(int i=0;i<n;i++)
        if (state[G[i]->val]==0){
            DFS_visit(G,G[i]->val,time,state,0,work,S);
        }

    cout << endl << "!!! KONIEC !!!" << endl << "STATE:";
    print(state);
    cout << "TIME:";
    print(time);
    cout << "WORK:";
    print(work);
    cout << "POSROTOWANY TOPOLOGICZNIE:";
    printS(S);
}

//PROGRAM
int main(){
    node *G[n];
    init(G);
    int time[n], state[n], work[n];
    node*S=createS(S);

    insert_edge(G, 0, 1);
    insert_edge(G, 1, 3);
    insert_edge(G, 1, 5);
    insert_edge(G, 5, 2);
    insert_edge(G, 3, 4);

    print_graph(G);
    DFS(G,time,state,work,S);
return 0;
}


