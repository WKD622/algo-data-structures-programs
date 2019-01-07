#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>

using namespace std;
const int n=6;
int A[n];
int indeks[n];

void drukuj(){
    cout.width(3);
    for (int m=0; m<n; m++)
        cout << A[m] << "  ";
    cout << endl;
}


int Partition (int A[], int p, int r){
    int x=A[r];
    int i,j;
    i=p-1;
    for(j=p; j<r; j++){
        if(A[j]<=x){
            i++;
            int pom1=A[j];
            A[j]=A[i];
            A[i]=pom1;
        }
    }
    int pom2=A[r];
    A[r]=A[i+1];
    A[i+1]=pom2;

    return i+1;
}

void QuickSort (int A[], int p, int r){
    if (p<r){
        int q=Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

void wypelnij(){
    srand(time(NULL));
    for (int m=0; m<n; m++){
        A[m]=rand()%9+1;
    }
}

int main(){

	cout << "START" << endl;
	wypelnij();
	drukuj();
	cout << endl;
	QuickSort(A,0,n-1);
	cout << "KONIEC" << endl;
	drukuj();

    return 0;

}
