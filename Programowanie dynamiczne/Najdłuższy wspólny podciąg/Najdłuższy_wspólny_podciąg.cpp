#include <iostream>
#include <conio.h>
#define n 4
#define m 5

using namespace std;

//FUNKCJE
void print (int T[], int l){
    for (int i=0; i<l; i++)
        cout << T[i] << " ";
    cout << endl;
}
void print_2(int T[n+1][m+1]){
    for (int i=0; i<=n; i++){
        for (int j=0; j<=m; j++){
            cout.width(3);
            cout << T[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
int LCS (int c1[], int c2[]){
    int T[n+1][m+1];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            T[i][j]=-1;
        }
    }
    for (int i=0; i<=n; i++) T[i][0]=0;
    for (int j=0; j<=m; j++) T[0][j]=0;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (c1[i]==c2[j]){
                    T[i][j]=T[i-1][j-1]+1;
            }
                else{
                    T[i][j]=max(T[i-1][j],T[i][j-1]);
                }
        }
    }
    return T[n][m];
}
int LCS1 (int c1[], int c2[]){
    int T[n+1][m+1];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            T[i][j]=-1;
        }
    }
    for (int i=0; i<=n; i++) T[i][0]=0;
    for (int j=0; j<=m; j++) T[0][j]=0;
    print_2(T);
    cout << "C1 (i):";
    print(c1,n);
    cout << "C2 (j):";
    print(c2,m);
    for (int i=1; i<=n; i++){
        cout << "i=" << i << endl;
        for (int j=1; j<=m; j++){
            getch();
            cout << "   j=" << j << endl;
            cout << "   czy c1["<<i << "]("<<c1[i]<<")=c2[" <<j <<"]("<<c2[j]<<")"<<endl;
            if (c1[i]==c2[j]){
                    cout << "       TAK"<< endl;
                    getch();
                    cout << "       C1 (i):";
                    print(c1,n);
                    cout << "       C2 (j):";
                    print(c2,m);
                    cout << "       c1["<<i << "]=c2[" <<j <<"]"<<endl;
                    T[i][j]=T[i-1][j-1]+1;
                    print_2(T);
                    cout << "       T["<<i<<"]["<<j<<"]=T["<<i-1<<"]["<<j-1<<"]+1"<<endl <<"-------"<< endl;
            }
                else {
                    cout << "       NIE" <<endl;
                    cout << "       T["<<i<<"]["<<j<<"]=max(T["<<i-1<<"]["<<j<<"],T["<<i<<"]["<<j-1<<"])" <<endl<<"       -------"<< endl;
                    T[i][j]=max(T[i-1][j],T[i][j-1]);
                    print_2(T);
                    cout << endl<<endl;
                }
        }
    }
    return T[n][m];
}

//MAIN
int main(){

int c1[n]={1,2,4,5};
int c2[m]={4,2,5,2,7};

cout << LCS (c1, c2);
}
