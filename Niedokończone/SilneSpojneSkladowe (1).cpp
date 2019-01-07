
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
void DFS_visit(int g[n][n], int v, int time[n], int state[n], int work[n], int time2, node*S){
    time2++;
    state[v]=1;

    for(int i=0;i<n;i++){
        if(g[v][i]>0 && state[i]==0)
            DFS_visit(g,i,time,state, work, time2,S);
    }
    push(S,v);
    if (time2>maks)
        maks = time2;
    state[v]=2;
    time[v]=time2;
    work[v]=maks-time[v];
}
void DFS(int g[n][n], int time[], int state[], int work[n], node*S){
    zeruj(time,state,work);
    for(int i=0;i<n;i++)
        if(state[i]==0){
            maks=-1;
            DFS_visit(g,i,time,state,work,0,S);
        }

    cout << "ZWYKLE PRZEJSCIE DFS" << endl << "STATE:";
    print(state);
    cout << "TIME:";
    print(time);
    cout << "WORK:";
    print(work);
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
void odwroc_krawedzie(int GO[n][n], int G[n][n]){
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            GO[j][i]=G[i][j];
}
void DFS_no_time(int g[n][n], int time[], int time3[2][n], int state[], int work[n], node*S){
    zeruj(time,state,work);
    for(int i=0;i<n;i++)
        if(state[time3[1][i]]==0){
            maks=-1;
            emptyS(S);
            DFS_visit(g,time3[1][i],time,state,work,0,S);
            cout<<"spojna sklad. "<<i<<": ";
            printS(S);
            cout<<endl;
        }

    cout << "DFS NO TIME" << endl << "STATE:";
    print(state);
    cout << "TIME:";
    print(time);
    cout << "WORK:";
    print(work);
}



int main(){
    int time[n],time2[2][n], state[n], work[n], GO[n][n];
    int G[n][n]={                   //TABLICA GO - G ODWROCONA
    {-1,1,0,0,0,0},
    {0,-1,1,0,0,0},
    {0,0,-1,1,0,0},
    {0,1,0,-1,1,1},
    {0,0,0,0,-1,0},
    {0,1,0,0,0,-1},
    };
    node*S=createS(S);

    DFS(G,time,state,work,S);
    odwroc_krawedzie(GO, G);
    sort_time(work,time2);
    DFS_no_time(GO,time,time2,state,work,S);

    return 0;
}

