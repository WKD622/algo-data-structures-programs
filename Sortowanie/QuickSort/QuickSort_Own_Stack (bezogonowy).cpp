#include <iostream>
#include <stack>
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

void QuickSort (int A[], int l, int r){
    stack <int> s;
    s.push(l);
    s.push(r);
    while ( !s.empty() ){
        r=s.top();
        s.pop();
        l=s.top();
        s.pop();
        if (l<r){
            int q=Partition(A,l,r);
            if (q-1-l < r-(q+1)){
                s.push(q+1);
                s.push(r);
                s.push(l);
                s.push(q-1);
            }else{
                s.push(l);
                s.push(q-1);
                s.push(q+1);
                s.push(r);
            }
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
    QuickSort(A, 0, n-1);
    drukuj(A);
    return 0;
}
