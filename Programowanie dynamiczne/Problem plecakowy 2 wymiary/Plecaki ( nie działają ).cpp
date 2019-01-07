#include <iostream>
#define n 6

using namespace std;

int knapsack (int P[], int w[], int T){
    int F[n+1][T+1];
    for (int i=0; i<=n; i++)
        F[i][0]=0;
    for (int t=0; t<=T; t++)
        F[0][t]=0;

    for (int i=1; i<=n; i++)
        for (int t=1; t<=T; t++){
            if (w[i]>t) F[i][t]=F[i-1][t];
                else F[i][t]=max(F[i-1][t], F[i-1][t-w[i]] + P[i]);
    }
    return F[n][T];
}

int main(){
    int P[]={1,1,1,100,1,15};
    int w[]={9,9,9,9,9,9};
    int T=18;
    cout << knapsack(P,w,T);



    return 0;
}
