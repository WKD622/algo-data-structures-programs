#include <iostream>

using namespace std;

//STRUKTURY
struct node{
    int wartosc;
    node *next;
};
node*l=NULL;
const int n=10;
const int k=10;

//FUNKCJE
int wartosc_itego_elementu (node *l, int i){
    int a=0;
    while (a<i){
        l=l->next;
        a++;
    }
    return l->wartosc;
}
void zrob_liste(node *&l, int T[]){
    node *q = NULL;
    node *p = NULL;
    for (int i=n-1; i>=0; i--){
        q=new node;
        q->wartosc=T[i];
        q->next=p;
        p=q;
    }
    l=q;
}
void drukujT(int A[]){
    for (int i=0; i<n; i++)
        cout << A[i] <<"   ";
        cout << endl;
}
void CountingSort( node *&l, int n, int k){
    int B[n], C[k];

    for (int i=0; i<k; i++) C[i]=0;
    for (int i=0; i<n; i++) C[wartosc_itego_elementu(l,i)]++;

    for (int i=1; i<k; i++) C[i]=C[i]+C[i-1];

    for (int i=n-1; i>=0; i--){
        int pom=wartosc_itego_elementu(l,i);
        B[C[pom]-1]=pom;
        C[pom]--;
    }
    zrob_liste(l,B);
}
void drukujL(node *l){
    while(l!=NULL){
        cout << l->wartosc << "  ";
        l=l->next;
    }
    cout << endl;
}

//PROGRAM
int main(){
    int T[n]={9,8,7,3,1,1,4,5,6,0};
    zrob_liste(l,T);
    drukujL(l);
    CountingSort(l,n,k);
    drukujL(l);

    return 0;
}

