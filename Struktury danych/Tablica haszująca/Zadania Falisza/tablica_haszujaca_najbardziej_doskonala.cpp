#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

//STOS
struct node{
    int val;
    node*next;
};
node* createS(node*S){
    node*W=new node;
    S=W;
    S->next=NULL;
}
node* emptyS(node*S){
S->next=NULL;
return S;
}
void printS(node*S){
    S=S->next;
    while(S){
        cout<<S->val<<" ";
        S=S->next;
    }
}
void push(node*S,int w){
    node*pom=new node;
    pom->next = S->next;
    pom->val=w;
    S->next=pom;
}
int pop(node*S){
    if(S->next){
        node*pom=S->next;
        S->next = pom->next;
        int a = pom->val;
        delete pom;
        return a;
    }
}
bool isempty(node*S){
    if(!S->next) return true;
        else return false;
}

//STRUKTURY
struct HT{
    int *Table;
    int Size;
};

//FUNKCJE
int hashuj(int l, int n){
    return l%n;
}
void init(HT &hashtab, int n){
    hashtab.Table=new int[n];

    for(int i=0; i<n; i++){
        hashtab.Table[i]=-1;
    }
}
void print_hashtab(HT hashtab, int n){
    cout << endl;
    for (int i=0; i<n; i++){
        cout.width(3);
        cout << hashtab.Table[i] << " ";
    }
    //cout << endl;
   // for (int i=0; i<n; i++){
   //     cout.width(3);
   //     cout << i << " ";
   // }
    cout << endl;
}
void hashuj_val(HT &hashtab, int val, int Hash, int n){
    int i=Hash;
    i++;
    while(i!=Hash and hashtab.Table[i]!=-1){
        i++;
        if (i==n-1) i=0;
    }
    if (i!=Hash and hashtab.Table[i]==-1) hashtab.Table[i]=val;
}
void wypelnij(HT &hashtab, int n){
    for(int i=0; i<n-5; i++){
        int w=rand()%99+1;
        int p=hashuj(w,n);
        if (hashtab.Table[p]==-1)
            hashtab.Table[p]=w;
        else{
            hashuj_val(hashtab,w,p,n);
        }
    }
}
int licz(HT hashtab, int n){
    int licznik=0;
    for(int i=0; i<n; i++)
        if (hashtab.Table[i]!=-1) licznik++;
    return licznik;
}
void enlarge(HT hashtab_1, HT &hashtab_2, int n){
    node*S=createS(S);
    for (int i=0; i<n; i++){
        if (hashtab_1.Table[i]!=-1){
            int new_p=hashuj(hashtab_1.Table[i],2*n);
            if (hashtab_2.Table[new_p]==-1) {
                hashtab_2.Table[new_p]=hashtab_1.Table[i];
            }
                else{
                    push(S,hashtab_1.Table[i]);
                }
        }
    }
    while(!isempty(S)){
        int p1=pop(S);
        int p2=hashuj(p1,2*n);
        hashuj_val(hashtab_2,p1,p2,n*2);
    }
}
int sprawdz_doskonalosc(HT hashtab, int n){
    int licznik=0;
    for (int i=0; i<n; i++){
        if (hashuj(hashtab.Table[i],n)==i) licznik++;
    }
    return licznik;
}
void przehashuj_normalnie(HT hashtab_1, HT &hashtab_2, int n){
    int k=2*n;
    for (int i=0; i<n; i++){
        if (hashtab_1.Table[i]!=-1){
            int p=hashuj(hashtab_1.Table[i],k);
            hashuj_val(hashtab_2,hashtab_1.Table[i],p,k);
        }
    }
}

//PROGRAM
int main(){
    int n=15;
    int k=2*n;
    srand(time(0));
    HT hashtab_1, hashtab_2, hashtab_3;
    init(hashtab_1,n);
    init(hashtab_2,k);
    init(hashtab_3,k);

    wypelnij(hashtab_1,n);
    cout << "HASHTAB 1:";
    print_hashtab(hashtab_1,n);

    //enlarge(hashtab_1, hashtab_2, n);
    przehashuj_normalnie(hashtab_1, hashtab_3,n);
    print_hashtab(hashtab_2,k);
    print_hashtab(hashtab_3,k);

    cout << endl << "DOSKONALOSC PO ENLARGE: " <<  sprawdz_doskonalosc(hashtab_2,k);
    cout << endl << "DOSKONALOSC PO ZWYKLYM HASHOWANIU: " << sprawdz_doskonalosc(hashtab_3,k);
    return 0;

}
