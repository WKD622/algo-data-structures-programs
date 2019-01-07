#include <iostream>
#include <string>

using namespace std;

const int n=5;
const int N=20;
struct wyraz{
    string slowo;
    int dl;
};

int dlugosc(string s){
    int dlugosc_stringa=0;
    char b=s[0];
    int i=1;
    while(b!='\0'){
        dlugosc_stringa++;
        b=s[i];
        i++;
    }
    return dlugosc_stringa;
}

void wypelnij_tablice_stringami(wyraz A[]){
    for (int i=0; i<n; i++){
        string s;
        cout << "Podaj "<<i+1<<" string:"<< endl;
        cin >> s;
        A[i].slowo=s;
        A[i].dl=dlugosc(A[i].slowo);
    }
}

void wypisz(wyraz A[]){
    for (int i=0; i<n; i++){
        cout << A[i].slowo << "  " << A[i].dl << endl;
    }
}

void CountigSort_dlugosci(wyraz A[]){
    wyraz B[n];
    int C[N];
    for (int i=0;i<N;i++) C[i]=0;
    for (int i=0;i<n;i++) C[A[i].dl]++;
    for (int i=1;i<N;i++) C[i]=C[i]+C[i-1];

    for (int i=n-1; i>=0; i--){
        B[C[A[i].dl]-1]=A[i];
        C[A[i].dl]--;
    }
    for (int i=0; i<n; i++) A[i]=B[i];
}

void CountingSort_pozycje(wyraz A[],int pozycja){
    wyraz B[n];
    int C[26];
    int licznik=0;
    for (int i=0; i<n; i++){
        if (A[i].dl>=pozycja) licznik++;
    }
    for (int i=0; i<licznik; i++) B[i]=A[i];

    for (int i=0; i<26; i++) C[i]=0;
    for (int i=0; i<n; i++) if (A[i].dl>=pozycja) C[A[i].slowo[pozycja]-'a']++;
    for (int i=1; i<26; i++) C[i]=C[i]+C[i-1];

    for (int i=n-1; i>=0; i--){
        if (A[i].dl>=pozycja) {
            B[C[A[i].slowo[pozycja]-'a']-1+2]=A[i];
            C[A[i].slowo[pozycja]-'a']--;
        }
    }
    for (int i=0; i<n; i++) {
        A[i]=B[i];
    }
}

int main(){
    wyraz A[n];
    wypelnij_tablice_stringami(A);
    CountigSort_dlugosci(A);
    CountingSort_pozycje(A,7);

    wypisz(A);

    return 0;
}
