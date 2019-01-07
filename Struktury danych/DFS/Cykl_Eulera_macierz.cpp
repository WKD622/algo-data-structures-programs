#include <iostream>
#include <stack>

using namespace std;

const int n=6;
stack <int> S;

void DFSEuler(int g[n][n], int v, int n) {
	for (int i = 0; i < n; i++)
		while (g[v][i] > 0) {
			g[v][i]--;
			g[i][v]--;
			DFSEuler(g, i, n);
		}
	S.push(v);
}
bool eulerCycle(int g[n][n], int n) {
	/*while (!S.empty()) S.pop();
	for (int i = 0; i < n; i++) {
		int c = 0;
		for (int j = 0; j < n; j++)
			if (g[i][j]) c++;
		if (c % 2 != 0) return false;
	}*/

	DFSEuler(g, 0, n);

	while (!S.empty()) {
		cout << S.top() << endl;
		S.pop();
	}
	return true;
}


int main(){
    int G[n][n]={
    {0,1,0,1,0,1},
    {1,0,1,0,0,0},
    {0,1,0,1,1,1},
    {1,0,1,0,0,0},
    {0,0,1,0,0,1},
    {0,0,1,0,1,0},
    };


    if (eulerCycle(G, n)) cout << "MA CYKL EULERA";
        else cout << "NIE MA CYKLU EULERA";


    return 0;
}
