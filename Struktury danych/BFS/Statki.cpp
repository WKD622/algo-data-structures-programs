#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

//----------------------------------------------------------
//KOLEJKA---------------------------------------------------
//----------------------------------------------------------
struct node{
    int val;
    node *next;
};
void add(int w, node*q){
    node *pom=new node;
    pom->val=w;
    pom->next=q->next;
    q->next=pom;
}
int get(node *q){
    while (q->next->next!=NULL)
        q=q->next;
    node *pom=q;
    pom=q->next;
    q->next=NULL;
    return pom->val;
}
bool isempty(node *q){
    if (q->next==NULL)
        return true;
    return false;
}
void drukuj_kolejke(node *q){
    if(!isempty(q)){
        q=q->next;
        while (q!=NULL){
            cout << q->val << " ";
            q=q->next;
        }
    }
}
node *q=new node;
const int n=5; //kolumna
const int m=5; //wiersz
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------

struct parent{
    int x;
    int y;
};

bool port (int **A, int n, int m, int T){
// n kolumna
// m wierse
    bool visited[m][n];
    parent Tab[m][n];
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            visited[i][j]=false;

    visited[0][0]=true;

    add(0,q);               //PUNKT STARTOWY STATKU
    add(0,q);               //PUNKT STARTOWY STATKU

    while(!isempty(q)){
        int x=get(q);
        int y=get(q);

        if (x==(m-1) and y==(n-1)){
            while(x!=0 and y!=0){
            x=Tab[x][y].x;
            y=Tab[x][y].y;
            cout << " (" << x << "," << y << ") " << endl;
            }
            return true;
        }

        //PRZEJSCIE W DOL (STATEK PORUSZA SIE O JEDNO POLE W DOL)
        if (x<m-1 and A[x+1][y]>T and !visited[x+1][y]){
            add(x+1,q);
            add(y,q);
            cout << " dol ";
            visited[x+1][y]=true;
            Tab[x+1][y].x=x;
            Tab[x+1][y].y=y;
        }

        //PRZEJSCIE W LEWO
        if (y>0 and A[x][y-1]>T and !visited[x][y-1]){
            add(x,q);
            add(y-1,q);
            cout << " lewo ";
            visited[x][y-1]=true;
            Tab[x][y-1].x=x;
            Tab[x][y-1].y=y;
        }

        //PRZEJSCIE W PRAWO
        if (y<n-1 and A[x][y+1]>T and !visited[x][y+1]){
            add(x,q);
            add(y+1,q);
            cout << " prawo ";
            visited[x][y+1]=true;
            Tab[x][y+1].x=x;
            Tab[x][y+1].y=y;
        }
        //PRZEJSCIE W GORE
        if (x>0 and A[x-1][y]>T and !visited[x-1][y]){
            add(x-1,q);
            add(y,q);
            cout << " gora ";
            visited[x-1][y]=true;
            Tab[x-1][y].x=x;
            Tab[x-1][y].y=y;
        }
    }
    return false;
}

void wyp (int **A, int n, int m){

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            A[i][j]=rand()%10+1;
            cout.width(3);
            cout<<A[i][j];
        }
        cout<<endl;
    }
}

int main(){

    int** A = new int*[m];
    for(int i = 0; i < m; ++i)
        A[i] = new int[n];

    srand(time(0));
    q->next=NULL;
    wyp(A,n,m);
    if (port (A, n, m, 1)) cout << " jest ok";

    int x, y;



    return 0;
}
