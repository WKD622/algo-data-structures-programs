#include <iostream>
#include <conio.h>

using namespace std;

//STRUKTURY
struct node{ //DRZEWO
    int data;
    node *left;
    node *right;
    node *parent;
};
struct node2{ //ŁANCUCH
    int val;
    node2*next;
};

//FUNKCJE DO OBSLUGI ŁANCUCHA
node2* Create_l(){
    node2 *pom=new node2;
    pom->next=NULL;
    pom->val=-999;
    }
void Insert_l(int a, node2 *&l){
    node2*pom=new node2;
    pom->val=a;
    pom->next=l->next;
    l->next=pom;
}

//FUNKCJE DO OBSLUGI DRZEWA
void PreOrder(node *&BST){ //WYPISYWANIE DRZEWA METODA PREORDER
    if (BST != NULL){
        cout << BST->data << " ";
        PreOrder(BST->left);
        PreOrder(BST->right);
    }
}
void InOrder(node *&BST){ //WYPISYWANIE DRZEWA METODA INORDER
    if (BST != NULL){
        PreOrder(BST->left);
        cout << BST->data << " ";
        PreOrder(BST->right);
    }
}
node* Create(int a){ //TWORZENIE WEZLA
    node*tree=new node;
    tree->data=a;
    tree->parent=NULL;
    tree->left=NULL;
    tree->right=NULL;
    return tree;
}
void Insert(node*&tree, int a){ //DODAWANIE WARTOSCI DO DRZEWA
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
int przedzial(node *tree, int p, int k, int &licznik){ //LICZBA ELEMENTOW NALEZACYCH DO PRZEDZIALU
    if (tree){
        if (tree->data>=p and tree->data<=k) licznik++;
        przedzial(tree->left, p, k, licznik);
        przedzial(tree->right,p,k,licznik);
    }
}
node* Find(node *&tree, int a){ //SZUKANIE ELEMENTU
    if (tree->data==a){
        return tree;
    }
    else if (tree->left and a<tree->data) Find(tree->left,a);
        else if (tree->right) Find(tree->right,a);
            else if (!tree->left and a<tree->data) return NULL;
                else return NULL;
}
node *maximum(node *tree){ //SZUKANIE NAJWIEKSZEGO ELEMENTU
    while (tree->right) tree=tree->right;
    return tree;
}
node *minimum(node *tree){ //SZUKANIE NAJMNIJESZEGO ELEMENTU
    while(tree->left){
        tree=tree->left;
    }
    return tree;
}
node *succ(node *tree, int a){ //SZUKANIE NASTEPNIKA
    tree=Find(tree, a);
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
node *pred(node *tree, int a){ //SZUKANIE POPRZEDNIKA
    tree=Find(tree, a);
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
void Insert_Tree( node *&tree, node *&l ){ //WSTAWIANIE DRZEWA DO DRZEWA - DO USUWANIA KORZENIA
        if(l->data<tree->data and tree->left==NULL){
                tree->left=l;
                tree->left->parent=tree;
                getch();
                cout << "kupa1";
        }
        else if(l->data>=tree->data and tree->right==NULL){
                tree->right=l;
                tree->right->parent=tree;
                getch();
                cout << "kupa2";
            }
            else if(l->data<tree->data){
                Insert_Tree(tree->left,l);
                getch();
            }
                else{
                    Insert_Tree(tree->right,l);
                    getch();
                }

}
void Delete(node *&tree){ //USUWANIE ELEMENTU O KONRETNEJ WARTOSCI NIE DZIALA!!!!!!!!!
    if (tree->parent==NULL){
        node *poml=tree->left;
        node *pomr=tree->right;
        pomr->parent=NULL;
        Insert_Tree(pomr,poml);
        delete tree;
        tree=pomr;
    }
    else if (tree->left==NULL and tree->right==NULL){
        node *pom=tree;
        tree=tree->parent;
        if(tree->left==pom)
        tree->left=NULL;
        else tree->right=NULL;
        delete pom;
    }
        else if(tree->left==NULL and tree->right!=NULL){
            node *pomr=tree->right;
            node *pom=tree;
            tree=tree->parent;
            delete pom;
            tree->right=pomr;
            }
            else if(tree->left!=NULL and tree->right==NULL){
                node *poml=tree->left;
                node *pom=tree;
                tree=tree->parent;
                delete pom;
                tree->right=poml;
            }
                else{
                    if (tree->parent->data>tree->data){
                        node *poml = tree->left;
                        node *pomr = tree->right;
                        node *pom=tree;
                        tree=tree->parent;
                        delete pom;
                        pomr->parent=tree;
                        tree->left=pomr;
                        while(pomr->left!=NULL) pomr=pomr->left;
                        pomr->left=poml;
                    }else{
                        node *poml=tree->left;
                        node *pomr=tree->right;
                        node *pom=tree;
                        tree=tree->parent;
                        delete pom;
                        pomr->parent=tree;
                        tree->right=pomr;
                        while(pomr->left!=NULL) pomr=pomr->left;
                        pomr->left=poml;
                    }
                }
}
void Count(node *tree, int&l){ //ILOSC WEZLOW
    if (tree!=NULL){
        l++;
        Count(tree->left, l);
        Count(tree->right, l);
    }
}
void tworz_drzewo_rekurencyjnie(int T[],int p, int k,int s, node *&tree){ //TWORZENIE ZROWNOWAZONEGO DRZEWA
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
void czesc_wspolna(node *tree1, node *tree2){ //CZESC WSPOLNA DRZEW
    int k=0,l=0;
    Count(tree1,k);
    Count(tree2,l);
    int m,i=0;
    if (k<l) m=k;
        else m=l;
    int T[m];

    node *pom1=minimum(tree1);
    node *pom2=minimum(tree2);
    while (pom1!=NULL and pom2!=NULL){
        if (pom1->data==pom2->data){
            T[i]=pom1->data;
            i++;
            pom1=succ(pom1,pom1->data);
            pom2=succ(pom2,pom2->data);
        }
            else if (pom1->data<pom2->data){
                pom1=succ(pom1,pom1->data);
            }
                else{
                    pom2=succ(pom2,pom2->data);
                }
    }

    cout << "CZESC WSPOLNA TABLICA: ";
    for (int j=0; j<i; j++){
        cout << T[j] <<" ";
    }
    node *pom3;
    tworz_drzewo_rekurencyjnie(T,0,i-1,1,pom3);
    cout << endl << "DRZEWO ";
    PreOrder(pom3);
}
void roznica(node *tree1, node *tree2){ //ROZNICA DRZEW

    int i=0;
    node2*l=Create_l();
    node *pom1=minimum(tree1);
    node *pom2=minimum(tree2);

    while (pom1!=NULL and pom2!=NULL){
        if (pom1->data==pom2->data){
            pom1=succ(pom1,pom1->data);
            pom2=succ(pom2,pom2->data);
        }
            else if (pom1->data<pom2->data){
                Insert_l(pom1->data,l);
                i++;
                pom1=succ(pom1,pom1->data);

            }
                else{
                    Insert_l(pom1->data,l);
                    i++;
                    pom2=succ(pom2,pom2->data);
                }
    }

    int T[i];
    l=l->next;
    int k=0;
    while(l){
        T[k]=l->val;
        l=l->next;
        k++;
    }
    node *tree;
    tworz_drzewo_rekurencyjnie(T,0,i-1,(i-1)/2,tree);
    PreOrder(tree);
}

//KOD PROGRAMU
int main(){
    node *tree1=Create(8);
    tree1->parent=NULL;

    Insert(tree1,10);
    Insert(tree1,5);
    Insert(tree1,7);
    Insert(tree1,3);
    Insert(tree1,13);
    Insert(tree1,9);


    return 0;
}
