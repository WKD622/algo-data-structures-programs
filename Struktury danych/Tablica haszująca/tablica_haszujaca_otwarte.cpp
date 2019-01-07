#include <iostream>
#include <string>
#define n 10

using namespace std;

int hasz(string s){
    int suma=0, i=0;
    while (s[i]!='\0'){
        suma=suma+s[i];
        i++;
    }
    return suma%n;
}

void wstaw(string s, string t_hasz[]){
    int k=hasz(s), i=k;
        while(1){
            if (t_hasz[i]==""){
                t_hasz[i]=s;
                break;
            }
            if (i==n-1) i=-1;
            i++;

            if (i==k){
                cout << "nie ma wolnego miejsca";
                break;
            }
        }
}

int szukaj(string s, string t_hasz[]){
    int k=hasz(s), i=k;
    if (t_hasz[k]==s) return k;
    else {
        while(1){
            i++;
            if (i==n) i=0;
            if (i==k) return -1;
            if (t_hasz[i]=="") return -1;
            if (t_hasz[i]==s) return i;
        }
    }
}

void usun_element(string s, string t_hasz[]){
    if (szukaj(s,t_hasz)==-1) cout << "Nie ma takiego elementu" << endl;
        else t_hasz[szukaj(s,t_hasz)]="";
}

void drukuj_hasz(string t_hasz[]){
    int i=0;
    for (int i=0; i<n; i++){
        if (t_hasz[i]=="") cout << i << ". " << "pusty" << endl;
        else cout << i << ". " << t_hasz[i] << endl;
    }
}

int main(){

    int k;
    string t_hasz[n];
    string s="MA";
    string t="KOTA";
    string u="ALA";
    string w="BAR";

    wstaw(u, t_hasz);
    wstaw(s, t_hasz);
    wstaw(t, t_hasz);
    wstaw(w, t_hasz);

    drukuj_hasz(t_hasz);

    cout << endl << "Wprowadz szukany wyraz: ";
    cin >> w;
    k = szukaj(w, t_hasz);
    if (k!=-1) cout << endl << "Numer szukanego wyrazu wynosi: " << k;
        else cout << "Nie ma takiego wyrazu";

    cout << endl << "Wprowadz element, ktory chcesz usunac: ";
    cin >> w;
    usun_element(w, t_hasz);
    drukuj_hasz(t_hasz);

    return 0;
}
