#include <iostream>
#include <time.h>
#include <cstdlib>
#define m 20

using namespace std;

//STRUKTURY
struct SLNode{
    int val;
    int status;
    int works;
    SLNode *next[20];
};
struct Skiplist{
    SLNode *first;
    SLNode *last;
    int lvl;
};

//FUNKCJE
int level(float l){
    int lvl=0;
    while(rand()%2<l and lvl<20) lvl++;
    return lvl;
}
Skiplist Create_Skiplist(){
    Skiplist s;
    s.first=new SLNode;
    s.last=new SLNode;
    s.first->val=-9999;
    s.first->works=0;
    s.first->status=0;
    s.last->works=0;
    s.last->val=9999;
    for (int i=0; i<m; i++)
        s.first->next[i]=s.last;
    s.lvl=0;
    return s;
}
void Insert(Skiplist &s, int p, int k){
    SLNode*pom=s.first;
    SLNode*prev[m];

    //DODAWANIE POCZATKU
    for (int i=m-1; i>=0; i--)
        prev[i]=s.first;
    for (int i=s.lvl; i>=0; i--){
        while (pom->next[i]->val<p)
            pom=pom->next[i];
        prev[i]=pom;
    }
    if (pom->next[0]->status==0 and pom->next[0]->val==p) {
        while (pom->next[0]->val<=k){
            pom=pom->next[0];
            pom->works++;
        }
    }else{
        int lvl=level(0.5);
        SLNode *pom1=new SLNode;
        pom1->val=p;
        pom1->status=0;
        if (pom->status==1 and pom->val<p) pom1->works=pom->works;
            else if (pom->status==0 and pom->val<p) pom1->works=pom->works+1;

        if (lvl>s.lvl) s.lvl=lvl;
        for (int i=lvl; i>=0; i--){
            pom1->next[i]=prev[i]->next[i];
            prev[i]->next[i]=pom1;
        }
        pom=pom->next[0];
        while (pom->next[0]->val<=k){
            pom=pom->next[0];
            pom->works++;
        }
    }


    //DODAWANIE KONCA
    if (pom->val!=k){

        pom=s.first;
        for (int i=m-1; i>=0; i--)
            prev[i]=s.first;
        for (int i=s.lvl; i>=0; i--){
            while (pom->next[i]->val<=k)
                pom=pom->next[i];
            prev[i]=pom;
        }

        int lvl=level(0.5);
        SLNode *pom2=new SLNode;
        pom2->val=k;
        pom2->status=1;
        if (pom->status==1 and pom->val < pom2->val) pom2->works = pom->works-1;
            else if (pom->status==1 and pom->val == pom2->val) pom2->works = pom->works;
                else if (pom->status==0 and pom->val < pom2->val) pom2->works = pom->works;
                    else if (pom->status==0 and pom->val == pom2->val) pom2->works = pom->works;
        if (lvl>s.lvl) s.lvl=lvl;
        for (int i=lvl; i>=0; i--){
            pom2->next[i]=prev[i]->next[i];
            prev[i]->next[i]=pom2;
        }
    }
}
void PrintList(Skiplist s){
    cout << endl;
    for (int i=s.lvl; i>=0; i--){
        cout << "LVL "<< i << " |";
        SLNode *pom=s.first->next[i];
        while(pom!=s.last){
            cout <<" "<< pom -> val;
            if (pom->status==0) cout << "(S ";
                else cout << "(E ";
            cout << pom->works << ")";
            pom=pom->next[i];
        }
        cout << endl;
    }
    cout << endl;
}
bool czy_mozna(Skiplist s, int p, int k){
    SLNode*pom=s.first;
    for (int i=s.lvl; i>=0; i--){
        while(pom->next[i]->val<p)
            pom=pom->next[i];
    }
    pom=pom->next[0];
    while(pom->val<=k and pom->works<=2){
        pom=pom->next[0];
    }
    if (pom->val<k) return false;
    return true;
}

//MAIN
int main(){

    srand(time(0));
    int p,k;
    Skiplist s=Create_Skiplist();
    Insert(s,-1,0);
    Insert(s,1,2);
    Insert(s,2,5);
    Insert(s,5,6);
    Insert(s,6,8);
    Insert(s,7,12);
    Insert(s,9,10);
    Insert(s,11,14);
    Insert(s,13,15);
    Insert(s,-2,16);
    Insert(s,17,20);

    cout << "Podaj poczatek przedzialu: " << endl;
    cin>>p;
    cout << "Podaj koniec przedzialu: " << endl;
    cin>>k;
    if (czy_mozna(s,p,k)) cout << "Owszem, mozna.";
        else cout << "Niestety, nie mozna.";

    return 0;
}
