#include <iostream>
#define n 6

using namespace std;

int maks=-1;

//STOS
struct node{
    int val;
    node*next;
};
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
void DFS_visit(int g[n][n], int v, int time[n], int state[n], int work[n], int time2,node*S ){
    time2++;
    state[v]=1;
    for(int i=0;i<n;i++){
        if(g[v][i]>0 && state[i]==0)
            DFS_visit(g,i,time,state, work, time2,S);
    }
    push(S,v);   //TOPOLOGIA GRAFU
    if (time2>maks)
        maks = time2;
    state[v]=2;
    time[v]=time2;
    work[v]=maks-time[v];
}
void DFS(int g[n][n], int time[], int state[], int work[n],node*S){
    zeruj(time,state,work);
    for(int i=0;i<n;i++)
        if(state[i]==0)
            DFS_visit(g,i,time,state,work,0,S);

    cout << "KONIEC" << endl << "STATE:";
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
    int time[n], state[n], work[n];
    int G[n][n]={
    {-1,1,0,0,0,0},
    {0,-1,0,1,0,1},
    {0,0,-1,0,0,0},
    {0,0,0,-1,1,0},
    {0,0,0,0,-1,0},
    {0,0,1,0,0,-1},
    };

    node*S=createS(S);

    DFS(G,time,state,work,S);

    return 0;
}

