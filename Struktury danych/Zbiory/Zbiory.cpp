#include <iostream>

using namespace std;

struct node{
    node*parent;
    int val;
    int ranks;
};

node *MakeSet(int v){
    node *sets=new node;
    sets->parent=sets;
    sets->val=v;
    sets->ranks=0;
    return sets;
}

node *FindSet(node *x){
    if (x->parent!=x)
        x->parent=FindSet(x->parent);
    return x->parent;
}

node *Union( node *x, node *y){
    x=FindSet(x);
    y=FindSet(y);
    if(x->ranks < y->ranks) x->parent=y;
    else{
        y->parent =x;
        if(y->ranks==x->ranks)
            x->ranks++;
    }
}

int main(){


    return 0;
}
