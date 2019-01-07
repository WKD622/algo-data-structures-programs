#include <iostream>

using namespace std;

//STRUCTURES
struct node{
    int value;
    node*next;
};

//FUNCTIONS
void Insert(node *&l,int val){
    node *pom=new node;
    pom->value=val;
    pom->next=l;
    l=pom;
}
void Print(node *l){
    while(l){
        cout << l->value << " ";
        l=l->next;
    }
    cout << endl;
}
node*Create_List(int val){
    node *l=new node;
    l->next=NULL;
    l->value=val;
    return l;
}
int count_elements(node*l){
    int s=0;
    while (l->next){
        l=l->next;
        s++;
    }
    s++;
    return s;
}
void Bubble_Sort(node *&l){
    int n=count_elements(l);
    for (int i=0; i<n; i++){
        node *pom1=l;
        node *pom2=l->next;
        node *pom3=l->next->next;
        //ODWRACANIE DWOCH PIERWSZYCH ELEMENTOW
        if (pom1->value>pom2->value){
            node*pom=pom1;
            pom1->next=pom2->next;
            pom2->next=pom1;
            l=pom2;
            pom1=pom2;
            pom2=pom;
        }
        //ODWRACANIE ELEMENTOW W SRODKU
        while (pom3->next){
            if (pom2->value>pom3->value){
                pom1->next=pom3;
                pom2->next=pom3->next;
                pom3->next=pom2;
            }
            pom1=pom1->next;
            pom2=pom1->next;
            pom3=pom2->next;
        }
        //ODWRACANIE ELEMENTOW NA KONCU
        if (pom2->value>pom3->value){
            pom1->next=pom3;
            pom3->next=pom2;
            pom2->next=NULL;
        }
    }
}

//MAIN
int main(){

    node *l=Create_List(1);
    Insert(l,2);
    Insert(l,5);
    Insert(l,10);
    Insert(l,4);
    Insert(l,9);
    Insert(l,7);
    Insert(l,3);
    Insert(l,6);
    Insert(l,8);

    Print(l);
    Bubble_Sort(l);
    Print(l);

    return 0;
}
