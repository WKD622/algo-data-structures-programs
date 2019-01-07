#include <iostream>
#define n 10

using namespace std;

//FUNKCJE
void print (int A[]){
    for (int i=0; i<n; i++)
        cout << A[i] << " ";
    cout << endl;
}
void goodThieft(int A[]){
    int T[n];
    for (int i=0; i<n; i++)
        T[i]=0;
    T[0]=A[0];
    if (A[0]>A[1]) T[1]=A[0];
        else T[1]=A[1];

    for (int i=2; i<n; i++)
        T[i]=max(T[i-2]+A[i],T[i-1]);

    int i=n-1;
    while (i>0){
        while (T[i]==T[i-1]){
            i--;
        }
        if (i>0) cout << A[i] << " ";
        if (i==0 and T[i]!=0) cout << A[i] << " ";
        i=i-2;
    }
}

//MAIN
int main(){
    int A[]={192,44,2,122,75,3,111,8,6,14};
    goodThieft(A);

    return 0;
}
