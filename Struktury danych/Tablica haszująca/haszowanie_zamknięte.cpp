#include <iostream>
#include <string>
#define n 10

using namespace std;

struct node{
    string word;
    node *next;
};

int hasz(string s){
    int suma=0, i=0;
    while (s[i]!='\0'){
        suma=suma+s[i];
        i++;
    }
    return suma%n;
}

void wstaw(string s, node *t_hasz[]){
    int k=hasz(s);

    if (t_hasz[k]==NULL){
        t_hasz[k]=new node;
        t_hasz[k]->next=NULL;
        t_hasz[k]->word=s;
    }
    else{
        while(t_hasz[k]->next!=NULL)
            t_hasz[k]=t_hasz[k]->next;
        node *pom=new node;
        t_hasz[k]->next=pom;
        pom->next=NULL;
        pom->word=s;
    }
}

void nullowanie(node *t_hasz[]){
    for (int i=0; i<n; i++)
        t_hasz[i]=NULL;
}

void drukuj_tablice(node *t_hasz[]){
    for (int i=0; i<n; i++){
        if (t_hasz[i]!=NULL){
            node *pom=t_hasz[i];
            cout << " | "<< i << ". " << t_hasz[i]->word;
            while (pom->next!=NULL){
                pom=pom->next;
                cout << " -> " << pom->word;
            }
        }
        else{
            cout << " | "<< i << ". NULL";
        }
    }
}

node* szukaj(string s, node *t_hasz[]){
    int k=hasz(s);

    if (t_hasz[k]->word==s){
        node *pom=t_hasz[k];
        return pom;
    }
    else{
        while (t_hasz[k]->next->word!=s)
            t_hasz[k]=t_hasz[k]->next;
        node *pom=t_hasz[k]->next;
        return pom;
    }
}

int main(){
    node *t_hasz[n];
    node *szuk;
    nullowanie(t_hasz);

    string s="FRYDRYCH";
    string t="KOTA";
    string u="ALA";
    string w="BAR";
    string x="KUTWA";

    wstaw(u, t_hasz);
    wstaw(s, t_hasz);
    wstaw(t, t_hasz);
    wstaw(w, t_hasz);
    wstaw(x, t_hasz);

    drukuj_tablice(t_hasz);

    szuk=szukaj(t,t_hasz);
    cout << endl << endl <<" ZNALEZIONA WARTOSC: " << szuk->word << endl;
    return 0;
}
