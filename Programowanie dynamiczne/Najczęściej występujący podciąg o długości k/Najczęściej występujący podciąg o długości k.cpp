#include <iostream>
#define n 35

using namespace std;

void longest_series(int T[], int k){
    int Max[k];
    int S[k];
    int x=1;
    int max_x=1;
    for (int i=0; i<k; i++){
        Max[i]=T[i];
    }

    for (int i=0; i<n-k+1; i++){
        int l=0;
        int x=1;
        for (int j=i; j<i+k && j<n; j++){
            S[l]=T[j];
            l++;
        }
        for (int j=i+1; j<n-k+1; j++){
            if (T[j]==S[0] and T[j+1]==S[1] and T[j+2]==S[2]) x++;
            if (x>max_x) {
                max_x=x;
                for (int i=0; i<k; i++){
                    Max[i]=S[i];
                }
            }
        }
    }
    for (int i=0; i<k; i++){
        if (i!=2) cout << Max[i] << ", ";
            else cout << Max[i];
    }
}
int main(){
    int T[]={1,2,2,2,1,2,2,1,2,1,2,2,1,2,1,2,2,1,1,2,1,2,1,2,1,1,2,2,1,2,1,2,1,1,2,2,1,2,2,1};
    longest_series(T,3);

    return 0;
}
