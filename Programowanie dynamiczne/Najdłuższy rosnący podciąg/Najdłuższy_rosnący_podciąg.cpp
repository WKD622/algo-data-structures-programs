#include <iostream>
#include <stack>
#include <conio.h>
#define n 6
using namespace std;

void print(int A[n]){
    for(int i=0;i<n;i++){
        cout.width(3);
        cout<<A[i];
    }
    cout<<endl;
}
void print_list(int A[], int P[], int i){
    if(P[i]>=0)print_list(A,P,P[i]);
    cout<<A[i]<<" ";
}
int lis(int A[]){
    int F[n];
    int P[n];
    int M=1;
    int M_ind=0;

    for(int i=0; i<n; i++)
        F[i]=-1;

    for(int i=0;i<n;i++){
        F[i]=1;
        P[i]=-1;
        for(int j=0;j<i;j++){
            if(A[j]<A[i]){
                if(F[j]+1>F[i]){
                    P[i]=j;
                    F[i]=F[j]+1;
                }
            }
        }
        if(F[i]>M){
            M=F[i];
            M_ind = i;
        }
        M = max(M,F[i]);
    }
print_list(A,P,M_ind);
return M;
}

int lis1(int A[]){
    int F[n];
    int P[n];
    int M=1;
    int M_ind=0;

    for(int i=0; i<n; i++)
        F[i]=-1;
    cout << "START:"<<endl << "F:   ";
    print(F);
    getch();
    for(int i=0;i<n;i++){
        cout <<endl<< "!!!!! i="<<i<<" |  F["<<i<<"]=1 !!!!!"<<endl;
        F[i]=1;
        P[i]=-1;
        getch();
        cout << "F:   ";
        print(F);
        for(int j=0;j<i;j++){
            cout << "   j="<< j << endl;
            if(A[j]<A[i]){
                cout << "A["<<j<<"]("<<A[j]<<")<A["<<i<<"]("<< A[i] << ")"<< endl << "A:    ";
                print(A);
                getch();
                if(F[j]+1>F[i]){
                    cout << "F["<<j<<"]+1>F["<<i<<"]"<< "  ---> " << "F["<<i<<"]=F["<<j<<"]+1" << endl;
                    P[i]=j;
                    F[i]=F[j]+1;
                    //print(P);
                    cout << "F:  ";
                    print(F);
                }
            }
            cout << "!! A["<<j<<"]("<<A[j]<<")>A["<<i<<"]("<< A[i] << ")"<< endl << "A:    ";
            print(A);
        }
        if(F[i]>M){
            cout << "F["<<i<<"]("<<i<<")>M="<<M<<endl;
            M=F[i];
            M_ind = i;
        }
        M = max(M,F[i]);
        cout << "F[i]="<<F[i] << "  M="<<M<<endl;
    }
print_list(A,P,M_ind);
return M;
}

int main(){
    int C[]={9,1,6,3,8,7};
    cout<<endl<<lis1(C);

return 0;
}
