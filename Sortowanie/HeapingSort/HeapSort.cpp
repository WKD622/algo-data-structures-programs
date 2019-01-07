#include <iostream>
#define n 10

using namespace std;

struct heap{
    int heapsize;
    int H[n];
};

//FUNKCJE
int indeks(int w, heap &K){ //ZWRACA INDEKS WARTOSCI w
    int i=0;
    while (K.H[i]!=w){
        i++;
        if (i==n) return -1;
    }
    return i;
}
int left(int i , heap &K){ //ZWRACA WARTOSC LEWEGO SYNA WÊZ£A O INDEKSIE i
    i++;
    i=2*i;
    i--;
    if (i<K.heapsize) return K.H[i];
        else return -1;
}
int right(int i, heap &K){ //ZWRACA WARTOSC PRAWEGO SYNA WÊZ£A O INDEKSIE i
    i++;
    i=2*i;
    if (i<K.heapsize) return K.H[i];
        else return -1;
}
int parent(int i, heap &K){ //ZWRACA WARTOSC RODZICA WÊZ£A O INDEKSIE i
    i++;
    i=i/2;
    i--;
    return K.H[i];
}
void zamien(int i, int j, heap &K){  //ZAMIENIA MIEJSCAMI WARTOSCI O INDEKSACH i ORAZ j W TABLICY K
    int pom=K.H[i];
    K.H[i]=K.H[j];
    K.H[j]=pom;
}
void heapify(int i, heap &K){ //NAPRAWIA WEZEL O INDEKSIE i
    int r=right(i,K);
    int ri=indeks(r,K);
    int l=left(indeks(K.H[i],K),K);
    int li=indeks(l,K);

    if (ri!=-1 or li!=-1){
        if (K.H[i]<r or K.H[i]<l){
            if (K.H[i]<r and r>l){
                zamien(ri,i,K);
                heapify(ri,K);
            }
            else{
                zamien(li,i,K);
                heapify(li,K);
            }
        }
    }
}
void build_heap(int K[], int r){  //ROBI Z TABLICY KOPIEC
    heap L;
    L.heapsize=r;
    for (int i=0; i<r; i++)
        L.H[i]=K[i];
    for (int i=r/2; i>=0; i--)
        heapify(i,L);
    for (int i=0; i<r; i++)
        K[i]=L.H[i];
}
void heap_sort(int K[], int r, int i, int A[]){ //SORTUJE TABLICE WYKORZYSTUJAC BUDOWE KOPCA
    if (r>0){
        build_heap(K,r);
        A[i]=K[0];
        heap_sort(K+1,r-1,i+1,A);
    }
}

//MAIN
int main(){

    int L[]={4,1,3,2,16,9,10,14,8,7};
    int L_rozmiar=10;
    int posortowana[n];
    heap_sort(L,L_rozmiar,0,posortowana);

    for (int i=0; i<n; i++)
        cout << posortowana[i] << " ";

    return 0;

}
