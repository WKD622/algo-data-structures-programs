#include <iostream>
#include <conio.h>

using namespace std;

void print(int r[10]){
    for (int i=0; i<10; i++)
        cout << r[i] << " ";
    cout << endl;
}
int cut_rod(int p[10], int l){
    int r[10];
    for (int i=0; i<10; i++)
        r[i]=0;
    r[1]=p[0];

    for (int j=1; j<=l; j++){
        for (int i=1; i<j; i++){
           // getch();
            //cout << "j="<<j<< " | i="<<i<< " | j-i="<<j-i<<" | p[i]=" <<p[i] <<" | r[j-i]="<<r[j-i]<<" | r[j]="<<r[j]<<endl;
            r[j]=max(r[j],p[i]+r[j-i-1]);
            //print(r);
        }
    }
    return r[l];
}

int main(){
    int p[10]={1,5,8,9,10,17,17,20,24,30};

    cout << "MAKSYMALNA WARTOSC: " << cut_rod(p,4);

    return 0;
}
