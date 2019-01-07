#include <iostream>
#include <time.h>
#include <cstdlib>
#define n 70000

using namespace std;

//FUNCTIONS
void Bubble_Sort(int T[]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (T[j]>T[j+1]){
                int pom=T[j];
                T[j]=T[j+1];
                T[j+1]=pom;
            }
        }
    }
}
void Print(int T[]){
    for (int i=0; i<n; i++)
        cout << T[i] << " ";
}

//MAIN
int main(){
    srand(time(NULL));
    int T[n];
    for (int i=0; i<n; i++)
        T[i]=rand()%32000;
    cout << "!";
    Bubble_Sort(T);
   // Print(T);
}
