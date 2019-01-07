#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;
const int n=6;
int A[n]={9,8,3,7,9,6};
int indeks[n];
int q=999;
int i=-20,j=-20;
int x=-20;
int p,r=n-1;

void drukuj(){
    cout.width(3);
    for (int m=0; m<n; m++)
        cout << A[m] << "  ";
    cout << endl;

    for (int m=0; m<n; m++){
            cout.width(3);
        if ( indeks[m]==i ) cout << "i";
            else if ( indeks[m]==j ) cout << "j";
                else if (indeks[m]==r) cout << "x";
                    else cout << m;

    }
    cout << endl;
}


int Partition (int A[], int p, int r){
    x=A[r];

    i=p-1;
    cout << "    FOR" << endl;
    for(j=p; j<r; j++){
        getch();
        cout <<"pivot=" << q << "  i=" <<i<< "  j="<<j <<" l="<<p << "  A[j]="<< A[j]<< "  x=" << x << "     A[j]<=x ?"<<endl;
        if (i==j) cout << "i=j" << endl;
        drukuj();
        if(A[j]<=x){
            i++;
            cout << endl << "WCHODZE DO IF -> i++"<< endl;
            drukuj();
            int pom1=A[j];
            A[j]=A[i];
            A[i]=pom1;
            getch();
            cout << "swap a[i]<->a[j] i="<< i<< endl;
            drukuj();
            cout << "WYCHODZE Z IF"<< endl << endl;
        }
    }
        cout << "PO WYJSCIU Z FORA - ZAMIANA A[r]<->A[i+1]   r="<< r<< endl;
        int pom2=A[r];
        A[r]=A[i+1];
        A[i+1]=pom2;

        getch();
        cout << "PO FORZE:" << endl;
        drukuj();
        cout << endl;

        return i+1;
}

void QuickSort (int A[], int p, int r){
    cout << "QuickSort na przedziale: l="<<p<<"   r="<<r << endl;
    if (p<r){
        q=Partition(A,p,r);
        cout << endl << "------------------------" << endl;
        cout << "QUICKSOR (l,q-1);" << endl;
        QuickSort(A,p,q-1);
        cout << endl << "------------------------" << endl;
        cout << "QUICKSOR (q+1,r)" << endl;
        QuickSort(A,q+1,r);
    }
}

void wypelnij(){
    srand(time(NULL));
    for (int m=0; m<n; m++)
        A[m]=rand()%9+1;

    for (int m=0; m<n; m++){
        indeks[m]=m;
    }
}




int main(){
cout << "START" << endl;
//wypelnij();
drukuj();
cout << endl;
QuickSort(A,0,n-1);
cout << "KONIEC" << endl;
drukuj();







    return 0;
}
