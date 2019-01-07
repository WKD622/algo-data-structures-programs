#include <iostream>
#define n 10

using namespace std;

//FUNKCJE
int left(int T[n], int I[n], int i){
    if (2*I[i]-1<=n) return T[2*I[i]-1];
        else return -1;
}
int right(int T[n], int I[n], int i){
    if (2*I[i]<=n) return T[2*I[i]];
        else return -1;
}
bool czy_zepsuty(int T[n], int I[n], int i){
    if (left(T,I,i)!=-1 or right(T,I,i)!=-1)
        if (left(T,I,i)>T[i] or right(T,I,i)>T[i])
            return true;
        else return false;
}
void zamien(int T[n], int i, int j){
    int pom=T[i];
    T[i]=T[j];
    T[j]=pom;
}
void print(int T[n]){
for (int j=0; j<n; j++)
        cout << T[j] << " ";
    cout << endl;
}
void max_heapify(int T[n], int I[n], int i){
    if (czy_zepsuty(T,I,i)){
        if (left(T,I,i)>right(T,I,i)){
            zamien(T,i,2*I[i]-1);
            max_heapify(T,I,2*I[i]-1);
        }else{
            zamien(T,i,2*I[i]);
            max_heapify(T,I,2*I[i]);
        }
    }
}
void build_max_heap(int T[n], int I[n]){
    for (int i=n/2; i>=0; i--){
        max_heapify(T,I,i);
    }
}
//PROGRAM
int main(){
    int Z[n]={4,1,3,2,16,9,10,14,8,7};
    int T[n]={16,4,10,14,7,9,3,2,8,1};
    int I[n]={1,2,3,4,5,6,7,8,9,10};
    cout << "START: ";
    print(Z);
    build_max_heap(Z,I);
    cout << "KONIEC: ";
    print(Z);

    return 0;
}
