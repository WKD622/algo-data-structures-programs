#include <iostream>
#define n 8

using namespace std;

//FUNKCJE
int wayHome(int P[], int R[]){
    int T[n];
    for (int i=0; i<n; i++)
        T[i]=999;
    T[0]=0;
    //for (int i=1; i<=R[0]; i++)
      //  T[i]=R[0];
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (R[j]+j>=i){
                T[i]=min(T[i],T[j]+P[j]);
            }
        }
    }
    return T[n-1];
}

//MAIN
int main(){

    int P[]={2,1,1,7,1,2,7,7};
    int R[]={3,3,4,2,4,3,2,2};
    cout << wayHome(P,R);

    return 0;

}
