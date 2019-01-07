#include <iostream>
#include <conio.h>
#define n 3

using namespace std;


void print(int T[], int l){
    for (int i=0; i<l; i++){
        cout << T[i] << " ";
    }
    cout << endl;
}
void change(int T, int Coin[], int Count[]){
    Count[0]=0;
    for (int i=1; i<=T; i++){
        int Min = 1000;
        for (int j=0; j<n; j++){
            if (Coin[j]<=i){
                if (Count[i-Coin[j]]+1<Min){
                    Min=Count[i-Coin[j]]+1;
                }
            }
        }
        Count[i]=Min;
    }
}

void change1(int T, int Coin[], int Count[]){
    cout <<"START" << endl<< "COUNT[T+1]:  ";
    print(Count,T+1);
    Count[0]=0;
    for (int i=1; i<=T; i++){
        getch();
        cout << "GORNY FOR i= " << i << endl << "Min=1000" << endl << endl;
        int Min = 1000;
        for (int j=0; j<n; j++){
            cout << "DOLNY FOR j= " << j << endl;
            if (Coin[j]<=i){
                getch();
                cout << "Coin[" <<j << "](=" <<Coin [j] << ")<=" << i << " (i)"<< endl << "Coin[n]:  ";
                print(Coin,n);
                if (Count[i-Coin[j]]+1<Min){
                    getch();
                    cout << "COUNT[T+1]:  ";
                    print(Count,T+1);
                    cout << "Count[i-Coin[j]]+1 < Min | Count[i-Coin[j]]+1=" << Count[i-Coin[j]]+1 << "  | i-Coin[j]=" << i-Coin[j] << "  | Min="<< Min << endl;
                    Min=Count[i-Coin[j]]+1;
                    getch();
                    cout << "Min=Count[i-Coin[j]]+1" << endl;
                }
            }
        }
        Count[i]=Min;
        getch();
        cout <<"Count[i]=Min" << endl;
        getch();
        cout <<"COUNT[T+1]:  ";
        print(Count,T+1);
        cout << endl;
    }
}

int main(){
    int T=5;
    int Coin[n]={1,2,4};
    int Count[T+1];

    for (int i=0; i<=T; i++)
        Count[i]=0;
    change(T,Coin,Count);
    cout << endl << "STOP" << endl<< "COUNT[T+1]:  ";
    print (Count,T+1);



    return 0;
}
