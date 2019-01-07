#include <iostream>

using namespace std;

struct node{
    int val;
    node *next;
};

void add(int w, node*q){
    node *pom=new node;
    pom->val=w;
    cout << "pom->val=" << pom->val<< endl;
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

int main(){

    node *kolejka=new node;
    kolejka->next=NULL;
    add(5,kolejka);
    add(2,kolejka);
    add(3,kolejka);
    add(7,kolejka);

     drukuj_kolejke(kolejka);
     cout<< endl << get(kolejka) << endl;
     drukuj_kolejke(kolejka);

     cout<< endl << get(kolejka)<< endl;

     drukuj_kolejke(kolejka);
     cout<< endl << get(kolejka)<< endl;
     drukuj_kolejke(kolejka);
     cout<< endl << get(kolejka)<< endl;
     if (isempty(kolejka)) cout << "!!!";
    return 0;

}
