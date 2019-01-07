#include <iostream>
#include <cstdlib>
#include <time.h>
#define n 100

using namespace std;

//STRUCTURES
struct node{
    float value;
    node*next;
};

//FUNCTIONS
node*End(node*q){
    if(q==NULL) return NULL;
    while(q->next!=NULL)
        q=q->next;
    return q;
}
void Print_T2(node*T2[]){
    for (int i=0; i<n; i++){
        node *pom=T2[i];
        while (pom){
            cout << pom->value;
            if (pom->next) cout << " -> ";
            pom=pom->next;
        }
        cout << endl;
    }
}
void Preparation (float T1[], node* T2[]){
    for (int i=0; i<n; i++){
        T1[i]=rand()%1000/1000.0;
        T2[i]=new node;
        T2[i]->next=NULL;
        T2[i]->value=-999.9;
    }
}
void Add_Val(float val, node*T2[]){
    val=val*100;
    int i=(int)val;
    node*pom1=T2[i];
    while (pom1->next)
        pom1=pom1->next;
    node*pom2=new node;
    pom1->next=pom2;
    pom2->next=NULL;
    pom2->value=val/100;
}
void QuickSort(node*&pom){
    if (pom==NULL) return;
    float x=pom->value;
    node *l1=NULL;
    node *l2=NULL;
    node *l3=NULL;

    while(pom){
        node*q=pom;
        pom=pom->next;
        if (q->value<x){
            q->next=l1;
            l1=q;
        }
        else if(q->value==x){
            q->next=l2;
            l2=q;
        }else{
            q->next=l3;
            l3=q;
        }
    }
    QuickSort(l1);
    QuickSort(l3);

    pom=l2;
    if(End(l1)!=NULL){
        End(l1)->next=l2;
        pom=l1;
    }
    End(l2)->next=l3;
}

//MAIN
int main(){
    float T1[n];
    node* T2[n];
    srand(time(0));

    //PRZYGOTOWANIE T2, WYLOSOWANIE DANYCH DO T1
    Preparation(T1,T2);

    //DODAWNIE DO KUBELKOW
    for (int i=0; i<n; i++)
        Add_Val(T1[i],T2);

    //SORTOWANIE KUBELKOW QUCKSORTEM
    for (int i=0; i<n; i++)
        if (T2[i]->next!=NULL) QuickSort(T2[i]->next);

    //SCALANIE KUBELKOW W JEDN¥ LISTE
    node*l=new node;
    for (int i=0; i<n; i++){
        if (T2[i]->next){
            T2[i]=T2[i]->next;
            End(l)->next=T2[i];
        }
    }

    //WYSWIETLANIE POSORTOWANEJ LISTY
    while(l){
        cout << l->value << " ";
        l=l->next;
    }

    return 0;
}
