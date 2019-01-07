#include <iostream>
#define n 6

using namespace std;

int maks=-1;

//STRUKTURY
struct node {
    int val;
    node *next;
};

//STOS
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
    cout << endl;
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
    cout << endl;
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
void odwroc_krawedzie(node *G[n], node *GO[n]){
    node *pom[n];
    for (int i=0; i<n; i++)
        pom[i]=G[i];

    for (int i=0; i<n; i++){
        G[i]=G[i]->next;
        while(G[i]!=NULL){
            insert_edge(GO,G[i]->val,i);
            G[i]=G[i]->next;
        }
    }
    for (int i=0; i<n; i++)
        G[i]=pom[i];
}
void sort_time(int time[], int time2[][n]){
    for (int i=0; i<n; i++){
        time2[1][i]=i;
        time2[0][i]=time[i];
    }

    for (int i=0; i<n; i++)
        for (int j=0; j<n-1; j++)
            if (time2[0][j]<time2[0][j+1]){
                int pom=time2[0][j];
                time2[0][j]=time2[0][j+1];
                time2[0][j+1]=pom;

                pom=time2[1][j];
                time2[1][j]=time2[1][j+1];
                time2[1][j+1]=pom;
            }
}
void DFS_visit(node *G[n], int v, int time[n], int state[n], int time2, int work[n],node *S){
    time2++;
    //cout  << endl<< "DFS-VISIT PRZED REKURENCJA | V:"  << v << "  | TIME:" << time2 << endl << endl;
    state[v]=1;
    //cout << endl << "!!!!!!!!G[v]->val=" << G[v]->val << endl;
    //cout << endl << "!!!!!!!!state[G[v]->val]=" << state[G[v]->val] << endl;
    while(G[v]->next!=NULL){
        G[v]=G[v]->next;
        if(state[G[v]->val]==0){
            //cout << endl<< "G[v]->val=" <<G[v]->val << endl;
            DFS_visit(G,G[v]->val,time,state, time2, work,S);
        }

    }
    push(S,v);
    if (time2>maks)
        maks = time2;
    state[v]=2;
    time[v]=time2;
    work[v]=maks-time[v];
    //cout << "DFS-VISIT  | V:"  << v << "  | TIME:" << time2 << endl;
    //print(state);
    //print(time);

}
void DFS(node *G[n], int time[], int state[], int work[n], node *S){
    zeruj(time,state,work);
    for(int i=0;i<n;i++)
        if (state[G[i]->val]==0){
            //cout << endl << "???????DFSSSSSSSS????????????????" << endl;
            DFS_visit(G,G[i]->val,time,state,0,work,S);
        }
    cout << endl << "!!! KONIEC !!!" << endl << "STATE:";
    print(state);
    cout << "TIME:";
    print(time);
    cout << "WORK:";
    print(work);
}
void DFS_no_time(node *G[n], int time[], int time3[2][n], int state[], int work[n], node*S){
    zeruj(time,state,work);
    for(int i=0;i<n;i++)
        if (state[G[i]->val]==0){
            maks=-1;
            emptyS(S);
            DFS_visit(G,G[i]->val,time,state,0,work,S);
            cout<<"spojna sklad. "<<i<<": ";
            printS(S);
            cout<<endl;
        }

    cout << endl << "!!! KONIEC !!!" << endl << "STATE:";
    print(state);
    cout << "TIME:";
    print(time);
    cout << "WORK:";
    print(work);
}

//PROGRAM
int main(){
    node *G[n], *GO[n]; //GO- graf z odwroconymi krawedziami
    init(G);
    init(GO);
    int time[n],time2[2][n], state[n], work[n];
    node*S=createS(S);

    insert_edge(G, 0, 1);
    insert_edge(G, 1, 2);
    insert_edge(G, 2, 3);
    insert_edge(G, 3, 4);
    insert_edge(G, 3, 5);
    insert_edge(G, 5, 1);
    insert_edge(G, 3, 1);


    odwroc_krawedzie(G,GO);
    cout << "GRAF G:";
    print_graph(G);
    cout << "GRAF G Z ODWROCONYMI KRAWEDZIAMI:";
    print_graph(GO);
    DFS(G,time,state,work,S);
    sort_time(work,time2);
    DFS_no_time(GO,time,time2,state,work,S);

    return 0;
}


