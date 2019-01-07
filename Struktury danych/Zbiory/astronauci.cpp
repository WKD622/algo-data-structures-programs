#include <iostream>
#include <conio.h>
#define n 10

using namespace std;

//STRUKTURY
struct node{
    node *next;
    int a1;
    int a2;
};

//FUNKCJE
node *create(int x, int y){
    node *pom = new node;
    pom->a1=x;
    pom->a2=y;
    pom->next=NULL;
    return pom;
}
void insert_pair(int x, int y, node *&as){
    node *pom=new node;
    pom->next=as;
    as=pom;
    as->a1=x;
    as->a2=y;
}
makeset(int ast[n], int a){
    if(ast[a]==-1) ast[a]=a;
}
int findset(int ast[n], int a){
    if (ast[a]!=a)
        return findset(ast,ast[a]);
}
void print_node(node *ast){
    while(ast){
        cout << "("<<ast->a1<<","<<ast->a2<<")"<<endl;
        ast=ast->next;
    }
}
void print_sets(int sets[]){
    for (int i=0; i<n; i++)
        cout << sets[i] << " ";
}
unionsets(int ast[n], int a1, int a2){
    int z1=findset(ast,a1);
    int z2=findset(ast,a2);

    if (z1!=z2)
        ast[a2]=a1;
}
void astro_sets(node *ast,int sets[]){
    while (ast){
        if (sets[ast->a1]==-1) makeset(sets,ast->a1);
        if (sets[ast->a2]==-1) makeset(sets,ast->a2);

        unionsets(sets, ast->a1, ast->a2);

        ast=ast->next;
    }
}
void licznosc_zbiorow(int sets[], bool ast1[]){
    for (int i=0; i<n; i++){
        if (ast1[i]==false){
            int z=findset(sets,sets[i]);
            ast1[i]=true;
            int licznik=0;
            for (int j=i+1; j<n; j++){
                if (z==findset(sets,sets[j]) and ast1[j]==false){
                    ast1[j]=true;
                    licznik++;
                }
            }
            cout << licznik+1 << endl;
        }
    }
}

//PROGRAM
int main(){
    int ast[n];
    bool ast1[n];

    for (int i=0; i<n; i++){
        ast[i]=-1;
        ast1[i]=false;
    }

    node *astronauts=create(0,1);
    insert_pair(0,2,astronauts);
    insert_pair(0,3,astronauts);
    insert_pair(3,4,astronauts);
    insert_pair(5,7,astronauts);
    insert_pair(7,6,astronauts);
    insert_pair(8,9,astronauts);

    //print_node(astronauts);
    astro_sets(astronauts, ast);
    //cout << endl;
    //print_sets(ast);
    licznosc_zbiorow(ast,ast1);

    return 0;
}

