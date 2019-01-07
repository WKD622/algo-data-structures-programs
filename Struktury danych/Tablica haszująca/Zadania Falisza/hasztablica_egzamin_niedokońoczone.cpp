#include <iostream>

using namespace std;

//STRUKTURY
struct HT{
    string *key;
    int *data;
    bool *free;
    int Size;
};

//FUNKCJE
int hasz(string key, int Size){
    int i=0;
    int suma=0;
    while(key[i]!='\0'){
        suma=suma+key[i];
        i++;
    }
    return suma%Size;
}
int wartosc(string key){
    int i=0;
    int suma=0;
    while(key[i]!='\0'){
        suma=suma+key[i];
        i++;
    }
    return suma;
}
void dodaj_wartosc(string key, int val, int Size, int L[], bool V[], string S[]){
    int h=hasz(key,Size);
    int j=h+1;
    if (V[h]==false){
        V[h]=true;
        L[h]=val;
        S[h]=key;
    }else{
        while (V[j]!=false and j!=h){
            j++;
            if (j==Size-1) j=0;
        }
        if (j!=h){
            V[j]=true;
            L[j]=val;
            S[j]=key;
        }
    }
}
void wypisywanie_tablicy(int L[], bool V[], string S[], int Size){
    for (int i=0; i<Size; i++){
        if (V[i]==false) cout << i+1 << ". puste " << endl;
        else cout <<i+1 << ". W: "<< L[i] << " | S: " <<S[i] << endl;
    }
}
int checkHT(HT *ht){
    for (int i=0; i<Size; i++){
        if (V[i]==true){

        }

    }
}
preparation(bool V[], int Size){
    for (int i=0; i<Size; i++)
        V[i]=false;
}

//PROGRAM
int main(){
    int Size=10;
    bool V[Size];
    string S[Size];
    int L[Size];
    preparation(V,Size);
    dodaj_wartosc("kupa",4,Size,L,V,S);
    dodaj_wartosc("siku",7,Size,L,V,S);
    dodaj_wartosc("fiku",2,Size,L,V,S);
    dodaj_wartosc("miku",9,Size,L,V,S);
    dodaj_wartosc("nana",4,Size,L,V,S);
    wypisywanie_tablicy(L,V,S,Size);

    return 0;
}
