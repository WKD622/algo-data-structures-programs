#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

//FUNKCJE
void mergeTab(int tab[], int l1, int m, int r2, int N) {    //l1,r1 krance lewej czeci tablicy, l2,r2, krance prawej tablicy
	int p = l1;
	int *T2 = new int[N];
	int r1 = m;
	int l2 = m + 1;
	int  i = l1;
	while (l1 <= r1 && l2 <= r2) {
		if (tab[l1] < tab[l2])
			T2[i] = tab[l1++];
		else
			T2[i] = tab[l2++];
		i++;
	}

    //doczepianie koncow
	while (l1 <= r1)
		T2[i++] = tab[l1++];
	while (l2 <= r2)
		T2[i++] = tab[l2++];

	for (i = p; i <= r2; i++)   //przepisywanie T2(pomocicza) do tablicy tab
		tab[i] = T2[i];
}
void msortTab(int tab[], int l, int r, int n) {
	if (l < r) {
		int m = (l + r) / 2;
		msortTab(tab, l, m, n);
		msortTab(tab, m + 1, r, n);
		mergeTab(tab, l, m, r, n);
	}
}

//PROGRAM
int main(){

    const long int N=200000;
    int d[N];
    for (long int i=0; i<N; i++)
        d[i]=rand()%32000;
    int p[N];
    msortTab(d,0,9,10);

    return 0;
}
