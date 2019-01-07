#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

const int n=6;
int A[n];
int Partition(int A[], int p, int r)
{
	int x=A[r];
	int i, j;
	i=p-1;
	for(j=p;j<r;j++)
	{
		if(A[j]<=x)
		{
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


void QuickSort(int A[], int p, int r){
	while(p<r){
        int q=Partition(A,p,r);
        if (q-p<=r-q){
            QuickSort(A, p, q-1);
            p=q+1;
        }else{
            QuickSort (A,q,r);
            r=q-1;
        }
	}
}

void wypelnij(){
    srand(time(NULL));
    for (int k=0; k<n; k++){
        A[k]=rand()%9+1;
    }
}

void drukuj(int t[]){
    for(int i=0;i<n;i++)
        cout<<t[i]<<" ";
cout << endl << endl;
}


int main(){

wypelnij();
drukuj(A);
QuickSort(A,0,n-1);
drukuj(A);



    return 0;
}
