#include <iostream>
using namespace std;
const int N=10;

struct node{
    int w;
    node*next;
};

void PrintList(node*l);
void QuickSort(node*&l);

int main(){
    node*q,*p=NULL;

    int t[N]={7,2,17,13,23,19,3,17,5,11};

    for(int i=N-1;i>=0;i--){
        q=new node;
        q->w=t[i];
        q->next=p;
        p=q;
    }

    node*l=p;
    PrintList(l);
    QuickSort(l);
    PrintList(l);
    return 0;}



void PrintList(node*l){
    while(l!=NULL){
        cout << l->w << ' ';
        l=l->next;
    }
    cout << endl;
}

node*koniec(node*q){
    if(q==NULL) return NULL;
    while(q->next!=NULL)
        q=q->next;
    return q;
}

void QuickSort(node*&l){
    if(l==NULL) return;
    node*l1=NULL,*l2=NULL,*l3=NULL;
    int x=l->w;

    while(l!=NULL){
        node*q=l;
        l=l->next;
        if(q->w<x){
            q->next=l1;
            l1=q;
        }
        else if(q->w==x){
            q->next=l2;
            l2=q;
        }else{
            q->next=l3;
            l3=q;
        }
    }

    QuickSort(l1);
    QuickSort(l3);

    l=l2;
    if(koniec(l1)!=NULL) {
        koniec(l1)->next=l2;
        l=l1;
    }
    koniec(l2)->next=l3;
}
