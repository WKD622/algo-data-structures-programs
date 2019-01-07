#include <iostream>
#include <time.h>
#include <cstdlib>
#define m 20

using namespace std;

//STRUKTURY
struct node{
    int val;
    int status;
    int number;
    node *next;
};

//FUNKCJE
node* Create(){
    node *s=new node;
    s->val=-9999;
    s->status=-9999;
    s->number=-9999;
    s->next=NULL;
    return s;
}
void Insert(node *s, int p, int k, int &num){
    node *pom=s;

    //DODAWANIE POCZATKU
    while (pom->next and pom->next->val<p) pom=pom->next;

    node *pom1=new node;
    pom1->val=p;
    pom1->status=0;
    pom1->number=num;
    pom1->next=pom->next;
    pom->next=pom1;

    //DODAWANIE KONCA
    while (pom->next and pom->next->val<=k) pom=pom->next;
    node *pom2=new node;
    pom2->val=k;
    pom2->status=1;
    pom2->number=num;
    pom2->next=pom->next;
    pom->next=pom2;

    num++;
}
void Print(node *s){
    while (s){
        cout <<" "<< s -> val;
            if (s->status==0) cout << "(S ";
                else cout << "(E ";
            cout << s->number << ") ->";
            s=s->next;
    }
}
bool czy_mozna_dodac(node *s, int p, int k){
    int l=0;
    while(s->val<p){
        if (s->status==0) l++;
            else if (s->status==1) l--;
        s=s->next;
    }

    while(s->val<=k){
        if (s->status==0) l++;
            else if (s->status==1) l--;
        s=s->next;
        if (l==3) return false;
    }
    return true;
}
//MAIN
int main(){
    node* s=Create();
    int num=0;

    //Insert(s,0,14,num);
    Insert(s,1,2,num);
    Insert(s,2,5,num);
    Insert(s,5,6,num);
    Insert(s,6,8,num);
    Insert(s,7,12,num);
    Insert(s,9,10,num);
    Insert(s,11,14,num);
    Insert(s,13,15,num);
    Insert(s,17,20,num);

    Print(s->next);

    if (czy_mozna_dodac(s,0,14)) cout << endl << "Owszem, mozna.";
        else cout << endl << "Niestety, nie mozna.";
    return 0;
}
