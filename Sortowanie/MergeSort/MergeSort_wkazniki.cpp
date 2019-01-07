#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int n=10;

//STRUKTURY
struct node{
    int wartosc;
    node*next;
};
struct para{
    node*p1=NULL;
    node*p2=NULL;
};

//FUNKCJE
void tworz(node* &poczatek, int dlugosc){
    int element;
    node *aktualny = NULL;
    node *nastepny = NULL;
    for (int i=0; i<dlugosc; i++){
        aktualny = new node;
        cin >> element;
        aktualny->wartosc=element; /*(*aktualny).wartosc=element;*/
        aktualny->next=nastepny;
        nastepny=aktualny;

    }
    poczatek=aktualny;
}
void drukuj(node *kopia){
    while (kopia!=NULL){
        cout << kopia->wartosc << " ";
        kopia=kopia->next;
    }
    cout << endl;
}
int dlugosc(node*l){
    int i=0;
    while(l){
        i++;
        l=l->next;
    }
    return i;
}
para dziel_lancuchy(node *l){
    node *pom=l;
    node *l2;
    int m=dlugosc(l)/2;

    for(int i=0;i<m-1;i++)
        pom=pom->next;
    l2=pom->next;
    pom->next=NULL;
    para lancuch;
    lancuch.p1=l;
    lancuch.p2=l2;
    return lancuch;
}
node* mergeLan(para lancuchy){
    node *scalony = new node;
    node *pom=scalony;

    while (lancuchy.p1!=NULL and lancuchy.p2!=NULL){
        if (lancuchy.p1->wartosc > lancuchy.p2->wartosc) {
            scalony->next = lancuchy.p2;
            lancuchy.p2=lancuchy.p2->next;
        }else{
            scalony -> next = lancuchy.p1;
            lancuchy.p1=lancuchy.p1->next;
        }
        scalony=scalony->next;
    }

    if(lancuchy.p1==NULL){
        scalony->next=lancuchy.p2;
    }
    if(lancuchy.p2==NULL)
        scalony->next=lancuchy.p1;
    pom=pom->next;
    return pom;
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
void msortLan(node* &l) {
    para lancuchy;
    if(dlugosc(l)>1){
        lancuchy=dziel_lancuchy(l);
        msortLan(lancuchy.p1);
        msortLan(lancuchy.p2);
        l=mergeLan(lancuchy);
    }
}

//PROGRAM
int main(){
    node *l;
    int p[n]={3,9,2,7,9,8,2,4,2,8};
    zrob_liste(l,p);
    drukuj(l);
    msortLan(l);

    cout << "posortowany:" << endl;
    drukuj(l);

    return 0;
}
