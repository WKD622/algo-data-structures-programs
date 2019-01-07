#include <iostream>
#define n 5  //LICZBA WIERZCHOLKOW
#define m 7  //LICZBA KRAWEDZI

using namespace std;

//STRUKTURY
struct node {
    int val;
    int weight;
    node *next;
};

//STOS
node* createS(node*S){
    node*W=new node;
    S=W;
    S->next=NULL;
}
void printS(node*S){
    //cout << endl;
    S=S->next;
    while(S){
        cout<<S->val<<" ";
        S=S->next;
    }
}
void push(node*S,int w){
    node*pom=new node;
    pom->next = S->next;
    pom->val=w;
    S->next=pom;
}
int pop(node*S){
    if(S->next){
        node*pom=S->next;
        S->next = pom->next;
        int a = pom->val;
        delete pom;
        return a;
    }
}

//FUNKCJE
void init(node *G[n]){
    for (int i=0; i<n; i++){
        G[i]=new node;
        G[i]->next=NULL;
        G[i]->val=i;
        G[i]->weight=-1;
    }
}
void insert_edge(node *G[n], int s, int e, int w){
    node *pom1=G[s];
    while (G[s]->next!=NULL)
        G[s]=G[s]->next;
    node *pom=new node;
    G[s]->next=pom;
    pom->val=e;
    pom->weight=w;
    pom->next=NULL;
    G[s]=pom1;
}
void print_graph(node *G[n]){
    node *pom[n];
    for (int i=0; i<n; i++)
        pom[i]=G[i];
    for (int i=0; i<n; i++){
        cout << G[i]->val<< "(" << G[i]->weight << ") -> ";
        if (G[i]->next==NULL) cout << "NULL";
        while(G[i]->next!=NULL){
            G[i]=G[i]->next;
            cout << G[i]->val << "("<< G[i]->weight<< ") -> ";
            if (G[i]->next==NULL) cout << "NULL";
        }
        cout << endl;
    }
    for (int i=0; i<n; i++)
        G[i]=pom[i];
}
void preparation(int p[n], int d[n], bool visited[n], int start){
    for (int i=0; i<n; i++){
        p[i]=-1;
        d[i]=32676;
        visited=false;
    }
    d[start]=0;
}
void print(int T[]){
    for (int i=0; i<n; i++)
        cout << T[i] << " ";
    cout << endl;
}
void algorytm_Bellmana_Forda(node *G[], int start){
    int p[n], d[n];
    bool visited[n];
    preparation(p,d,visited,start);
    node *S=createS(S);

    for (int i=0; i<n; i++){
        if (visited[i]==false){
            node *pom=G[i];
            G[i]=G[i]->next;
            while (G[i]){
                if (d[G[i]->val]>d[i]+G[i]->weight){
                    p[G[i]->val]=i;
                    d[G[i]->val]=d[i]+G[i]->weight;
                }
                G[i]=G[i]->next;
            }
            visited[i]=true;
            G[i]=pom;
        }
    }
    cout << endl << "ODETKAC TRZEBA MINIMUM " << d[n-1]<< " WEZLOW" << endl;
    int h=n-1;
    int licznik=0;
    while(p[h]!=-1){
        push(S,h);
        h=p[h];
        licznik++;
    }
    licznik++;
    push(S,h);
    cout << "SCIEZKA: ";
    printS(S);
    cout << endl << "LICZBA WEZLOW W SCIEZCE WYNOSI " << licznik << endl;

}

//PROGRAM
int main(){
    node *G[n];
    init(G);

    insert_edge(G, 0, 2, 1);
    insert_edge(G, 0, 1, 0);
    insert_edge(G, 1, 2, 0);
    insert_edge(G, 1, 3, 1);
    insert_edge(G, 2, 3, 1);
    insert_edge(G, 2, 4, 1);
    insert_edge(G, 3, 4, 1);
    print_graph(G);

    algorytm_Bellmana_Forda(G,0);

}
