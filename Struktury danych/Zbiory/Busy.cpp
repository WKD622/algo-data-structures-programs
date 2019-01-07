#include <iostream>
#define n 5

using namespace std;


//OPERACJE NA ZBIORACH
struct node{
    node*parent;
    int val;
    int ranks;
};
struct border{
    int a;      //KRAWEDZ Z PUNKTU A DO B
    int b;
    int p;      //PRZEPUSTOWOSC
};
node *MakeSet(int v){
    node *sets=new node;
    sets->parent=sets;
    sets->val=v;
    sets->ranks=0;
    return sets;
}
node *FindSet(node *x){
    if (x->parent!=x)
        x->parent=FindSet(x->parent);
    return x->parent;
}
node *Union( node *x, node *y){
    x=FindSet(x);
    y=FindSet(y);

        y->parent =x;
        if(y->ranks==x->ranks)
            x->ranks++;

}


//QUICKSORT
int Partition (border A[], int p, int r){
    int x=A[r].p;
    int i,j;
    i=p-1;
    for(j=p; j<r; j++){
        if(A[j].p<=x){
            i++;
            border pom1=A[j];
            A[j]=A[i];
            A[i]=pom1;
        }
    }
    border pom2=A[r];
    A[r]=A[i+1];
    A[i+1]=pom2;

    return i+1;
}
void QuickSort (border A[], int p, int r){
    if (p<r){
        int q=Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}


//WYCIECZKA
void szukaj(int l, T[]){
    for (int i=0; i<100; i++)
        if (T[i]==l) return i;
}
void preparation(bool V[n][n]){
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            V[i][j]=false;
}
void wycieczka(int start, int ends, border K[],int k){
    int T1[100];
    for (int i=0; i<100; i++){
        T1[i]=-1;
    }
    int j=0;
    bool koniec1=false;
    bool koniec2=false;
    bool iloczyn=false;
    int pom=k-1;
    node *A = MakeSet(K[pom].a);
    node *B = MakeSet(K[pom].b);
    node *C = MakeSet(-1);
    while(FindSet(A)!=FindSet(B) and !iloczyn){
        node*a = MakeSet(K[pom].a);
        node*b = MakeSet(K[pom].b);

        cout << endl <<"a->val:" << a->val << " |  b->val:" << b->val<< endl;
        if (a->val==start) koniec1=true;
        if (b->val==ends) koniec2=true;
        if (koniec1 and koniec2) iloczyn=true;
        T[j]=K[pom].a;
        j++;
        T[j]=K[pom].b;
        j++;

        cout << K[pom].a << "  " << K[pom].b << endl;
        if(FindSet(a)!=C)
            Union(C,a);
        if(FindSet(b)!=C)
            Union(C,b);

        pom--;
    }
    bool wypisz_droge=true;
    int l=-10;
    while (l!=ends){
        l=szukaj()

    }
}
void fillborder(border K[],int G[n][n] ){
    int pom=0;      //WYPELNIANIE TABLICY KRAWEDZI
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++){
            if(G[i][j]!=0){
                K[pom].a=i;
                K[pom].b=j;
                K[pom].p=G[i][j];
                pom++;
            }
        }
}
void print(border K[], int k){
    for(int i=0;i<k;i++){
        cout<<" A:"<<K[i].a<<" B:"<<K[i].b<<" p:"<<K[i].p << " | ";
        cout<<endl;
    }

}


int main(){

    int G[n][n]={
    {0,2,5,3,0},
    {0,0,0,6,3},
    {0,7,0,0,0},
    {0,8,0,0,0},
    {0,0,0,2,0},
    };
    int k=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++){
            if(G[i][j]!=0)
                k++;
        }

    bool V[n][n];
    border K[k];
    fillborder(K,G);
    QuickSort(K,0,k);
    print(K,k);
    wycieczka(0,1,K,k);
    return 0;
}
