#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

const int n=6;
int A[n];
int Partition(int A[], int p, int r){
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

int Select(int A[], int n, int k){
	if (n==1) return A[0];
	int q=Partition(A,0,n-1);
	if (q==k) return A[q];
	else if (k<q) return Select(A,q,k);
	else return Select(A+q+1,n-(q+1),k-(q+1));
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
cout << endl << Select(A,n,2) << endl;
drukuj(A);




    return 0;
}
