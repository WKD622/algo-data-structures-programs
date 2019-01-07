#include <iostream>

using namespace std;
const int n=10;
const int k=10;

void CountingSort( int A[], int n, int k){
    int B[n], C[k];
    for (int i=0; i<k; i++) C[i]=0;
    for (int i=0; i<n; i++) C[A[i]]++;
    for (int i=1; i<k; i++) C[i]=C[i]+C[i-1];

    for (int i=n-1; i>=0; i--){
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }
    for (int i=0; i<n; i++) A[i]=B[i];
}

void drukuj(int A[]){
    for (int i=0; i<n; i++)
        cout << A[i] <<"   ";
        cout << endl;
}


int main(){
    int T[n]={9,8,7,3,2,1,4,5,6,0};
    drukuj(T);
    CountingSort(T, n, k);
    drukuj(T);


    return 0;
}
