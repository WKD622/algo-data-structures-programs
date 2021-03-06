#include <iostream>
#include <conio.h>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node *parent;
};

//WYPISYWANIE DRZEWA METODA PREORDER
void PreOrder(node *&BST){
    if (BST != NULL){
        cout << BST->data << " ";
        PreOrder(BST->left);
        PreOrder(BST->right);
    }
}

//WYPISYWANIE DRZEWA METODA INORDER
void InOrder(node *&BST){
    if (BST != NULL){
        PreOrder(BST->left);
        cout << BST->data << " ";
        PreOrder(BST->right);
    }
}

//TWORZENIE WEZLA
node* Create(int a){
    node*tree=new node;
    tree->data=a;
    tree->parent=NULL;
    tree->left=NULL;
    tree->right=NULL;
    return tree;
}

//DODAWANIE WARTOSCI DO DRZEWA
void Insert(node*&tree, int a){
    if(tree==NULL){
        tree=Create(a);
        tree->parent=NULL;
    }
    else{
        if(a<tree->data and tree->left==NULL){
                tree->left=Create(a);
                tree->left->parent=tree;
        }else if(a>=tree->data and tree->right==NULL){
                tree->right=Create(a);
                tree->right->parent=tree;
            }
            else{
                if(a<tree->data)
                Insert(tree->left,a);
                else Insert(tree->right,a);
            }
    }
}

//LICZBA ELEMENTOW NALEZACYCH DO PRZEDZIALU
int przedzial(node *tree, int p, int k, int &licznik){
    if (tree){
        if (tree->data>=p and tree->data<=k) licznik++;
        przedzial(tree->left, p, k, licznik);
        przedzial(tree->right,p,k,licznik);
    }
}

//SZUKANIE ELEMENTU
node* Find(node *&tree, int a){
    if (tree->data==a){
        return tree;
    }
    else if (a<tree->data) Find(tree->left,a);
        else Find(tree->right,a);
}

//SZUKANIE NAJWIEKSZEGO ELEMENTU W DRZEWIE/PODDRZEWIE
node *maximum(node *tree){
    while (tree->right) tree=tree->right;
    return tree;
}

//SZUKANIE NAJMNIJESZEGO ELEMENTU W DRZEWIE/PODDRZEWIE
node *minimum(node *tree){
    while(tree->left) tree=tree->left;
    return tree;
}

//SZUKANIE NASTEPNIKA
node *succ(node *tree, int a){
    node *l=Find(tree, a);
    if (tree->right) return minimum(tree->right);
    else {
        node *pom=tree;
        while (tree->parent->right==tree){
            tree=tree->parent;
            if (tree->parent==NULL) return NULL;
        }
        return tree->parent;
    }
}

//SZUKANIE POPRZEDNIKA
node *pred(node *tree, int a){
    node *l=Find(tree, a);
    if (tree->left) return maximum(tree->left);
    else {
        node *pom=tree;
        while (tree->parent->left==tree){
            tree=tree->parent;
            if (tree->parent==NULL) return NULL;
        }
        return tree->parent;
    }
}


//ILOSC WEZLOW
void Count(node *tree, int&l){
    if (tree!=NULL){
        l++;
        Count(tree->left, l);
        Count(tree->right, l);
    }
}

//TWORZENIA DRZEWA ZROWNOWAZONEGO Z TABLICY
void tworz_drzewo_rekurencyjnie(int T[],int p, int k,int s, node *&tree){
    if (p<=k){
        int srodek=(p+k)/2;
        if (srodek==s){
            tree=Create(T[s]);
        }
            else {
                Insert(tree, T[srodek]);
            }
        tworz_drzewo_rekurencyjnie(T, p, srodek-1, s, tree);
        tworz_drzewo_rekurencyjnie(T, srodek+1, k, s, tree);
    }
}

//ROWNOWAZENIE
node* zrownowaz_drzewo_na_pale(node *tree){
    int liczba_wezlow=0, indeks=0;
    Count(tree,liczba_wezlow);
    int tab[liczba_wezlow];

    node *pom=minimum(tree);

    while(pom!=NULL){
        tab[indeks]=pom->data;
        indeks++;
        if (pom->parent==NULL) break;
        pom=succ(pom,pom->data);
    }
    node *balanced_tree;
    tworz_drzewo_rekurencyjnie(tab,0,indeks-1,indeks/2,balanced_tree);

    return balanced_tree;
}
//KOD PROGRAMU
int main(){
    node *tree=Create(8);
    tree->parent=NULL;

    Insert(tree,7);
    Insert(tree,6);
    Insert(tree,5);
    Insert(tree,4);
    Insert(tree,3);
    Insert(tree,2);

    node*balanced_tree=zrownowaz_drzewo_na_pale(tree);
    PreOrder(balanced_tree);

    return 0;
}
