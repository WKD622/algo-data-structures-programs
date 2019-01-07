#include <iostream>
#define n 5

using namespace std;

//STRUKTURY
struct field{
    int value;
    int long_j;
    int short_j;
};
struct node{
    int value;
    node *next;
};

//FUNKCJE
void add(node *&l,int val){
    node *pom=l;
    while (pom->next)
        pom=pom->next;
    node *pom2=new node;
    pom->next=pom2;
    pom2->value=val;
    pom2->next=NULL;
}
bool check(node *l, int val){
    while(l){
        if (l->value==val) return true;
        l=l->next;
    }
    return false;
}
void print(int T[]){
    for (int i=0; i<n; i++)
        cout << T[i] << " ";
    cout << endl;
}
int max_val(field F[]){
    node *l=new node;
    l->next=NULL;
    l->value=-999;

    int T[n];
    for (int i=0; i<n; i++)
        T[i]=0;
    T[0]=F[0].value;

    add(l,0);

    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if ((j+F[j].long_j==i or j+F[j].short_j==i) and check(l->next,j)){
                T[i]=max(T[i],F[i].value+T[j]);
                add(l,i);
            }
        }
    }

    return T[n-1];
}

//MAIN
int main(){
    field F[n];
    F[0].value=10;
    F[0].long_j=1;
    F[0].short_j=3;
    F[1].value=100;
    F[1].long_j=3;
    F[1].short_j=3;
    F[2].value=0;
    F[2].long_j=0;
    F[2].short_j=0;
    F[3].value=10;
    F[3].long_j=0;
    F[3].short_j=1;
    F[4].value=0;
    F[4].long_j=0;
    F[4].short_j=0;

    cout << max_val(F);

    return 0;
}
