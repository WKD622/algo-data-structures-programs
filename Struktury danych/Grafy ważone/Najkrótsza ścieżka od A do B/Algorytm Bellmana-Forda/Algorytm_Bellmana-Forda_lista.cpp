#include <iostream>
#include <conio.h>
#define n 6

using namespace std;

//STRUKTURY
struct node{
    int s;
    int e;
    int weight;
    node *next;
};

//FUNKCJE
void print(int tab[n]){
    for(int i=0;i<n;i++)
        cout<<tab[i]<<"  ";
    cout<<endl;
}
void init(node *&G, int s, int e, int w){
    G = new node;
    G->next = NULL;
    G->s=s;
    G->e=e;
    G->weight=w;
}
void insert_edge(node *&G, int s, int e, int w){
    node *pom=new node;
    pom->next=G;
    pom->s=s;
    pom->e=e;
    pom->weight=w;
    G=pom;
}
void print_graph(node *G){
    cout << endl;
    int i=1;
    while (G!=NULL){
        cout << i <<") S:"<< G->s << "  E:" << G->e << "  weight:" << G->weight << endl;
        G=G->next;
        i++;
    }
}
void preparation(int d[n], int p[n], int S){
    for (int i=0; i<n; i++){
        d[i]=32767;
        p[i]=-1;
    }
    d[S]=0;
    p[S]=S;
}
void algorytm_Bellmana_Forda(node *G, int S){
    int d[n], p[n];
    preparation(d,p,S);
    //cout << endl << "PREPARATION" << endl;
    //cout << "P:  ";
    //print(p);
    //cout << "D:  ";
    //print(d);
    for (int w=0; w<n; w++){
        for(node*r=G;r!=NULL;r=r->next){
            //cout << "u=" << r->s << "  v=" << r->e << "  weight=" << r->weight << endl;
            int u=r->s;
            int v=r->e;
            if(d[u]+r->weight < d[v]){
                //cout << "d[u]+r->weight < d[v]" << endl << "P:  ";
                d[v]=d[u]+r->weight;
                p[v]=u;
                //print(p);
                //cout << "D:  ";
                //print(d);
                //getch();
            }
        }
    }

    for(node*r=G;r!=NULL;r=r->next){
        int u=r->s;
        int v=r->e;
        if(d[u]+r->weight < d[v]){
            return;
        }
    }
    cout << endl << "P:  ";
    print(p);
    cout << "D:  ";
    print(d);
}

int main(){

    node *G;
    init(G,0,2,2);
    insert_edge(G,1,0,1);
    insert_edge(G,2,1,-2);
    insert_edge(G,3,2,-1);
    insert_edge(G,3,0,-4);
    insert_edge(G,4,3,1);
    insert_edge(G,5,4,8);
    insert_edge(G,5,0,10);
    cout << "GRAF G:";
    print_graph(G);
    algorytm_Bellmana_Forda(G,5);

    return 0;

}
