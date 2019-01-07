#include <iostream>
#include <cstdlib>
#include <ctime>
const int P=10;
const int W=5;
using namespace std;

struct item{
    int price;
    int weight;
};
int knapsack(item*Items,int n,int T){
    int F[n+1][T+1];
    // F[i][t] - maksymalna suma wartosci przedmiodow od 1..i, ktorych waga nie przekracza t,
    int P[n];
    for(int i=0;i<=n;i++){
        F[i][0]=0;
        P[i]=-1;
    }
    for(int t=1;t<=T;t++){
        F[0][t]=0;
    }
    for(int i=1;i<=n;i++)
        for(int t=1;t<=T;t++)
            if(Items[i].weight > t){
                F[i][t]=F[i-1][t];
            }else
                if(F[i-1][t]>F[i-1][t-Items[i].weight]+Items[i].price){
                    F[i][t]=F[i-1][t];
                }else
                    F[i][t]=F[i-1][t-Items[i].weight]+Items[i].price;

    cout << "Przedmioty ktore powinien zabrac zlodziej: ";
    int i=n,t=T;
    while(i!=0 and t!=0){
        if(F[i][t]>F[i-1][t]){
            cout << i << ", ";
            t-=Items[i].weight;
        }
        i--;
    }
    return F[n][T];
}
item* GenItems(int n){
    item*Items=new item[n];
    cout << "Przedmioty: " << endl;
    for(int i=1;i<n;i++){
        Items[i].price=rand()%P+1;
        Items[i].weight=rand()%W+1;
        cout << i << " cena: " << Items[i].price << " waga: " << Items[i].weight << endl;
    }
    return Items;
}

int Max(int a,int b){
    if(a>=b)
        return a;
    return b;
}

int main(){
    srand(time(0));
    int n=5;
    item*Items=GenItems(n);
    int T;
    cout << "Podaj ile uniesie zlodziej: ";
    cin >> T;
    cout << endl << "Ich cena to: " << knapsack(Items,n,T) << endl;
    return 0;
}

