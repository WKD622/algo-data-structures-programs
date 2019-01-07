#include <iostream>
#define n 6

using namespace std;

int maks=-1;

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
void DFS_visit(int g[n][n], int v, int time[n], int state[n], int time2, int work[n]){
    time2++;
    //cout  << endl<< "DFS-VISIT PRZED REKURENCJA | V:"  << v << "  | TIME:" << time2 << endl << endl;
    state[v]=1;

    for(int i=0;i<n;i++){
        if(g[v][i]==1 && state[i]==0)
            DFS_visit(g,i,time,state, time2, work);
    }
    if (time2>maks)
        maks = time2;
    state[v]=2;
    time[v]=time2;
    work[v]=maks-time[v];
    //cout << "DFS-VISIT  | V:"  << v << "  | TIME:" << time2 << endl;
    //print(state);
    //print(time);

}
void DFS(int g[n][n], int time[], int state[], int work[n]){
    zeruj(time,state,work);
    for(int i=0;i<n;i++)
        if(state[i]==0)
            DFS_visit(g,i,time,state,0,work);

    cout << "KONIEC" << endl << "STATE:";
    print(state);
    cout << "TIME:";
    print(time);
    cout << "WORK:";
    print(work);
}

//PROGRAM
int main(){
    int time[n], state[n], work[n];
    int G[n][n]={
    {-1,1,0,0,0,0},
    {0,-1,1,0,0,0},
    {0,0,-1,1,0,0},
    {0,0,0,-1,1,1},
    {0,0,0,0,-1,0},
    {0,0,0,0,0,-1},
    };

    DFS(G,time,state,work);

    return 0;
}

