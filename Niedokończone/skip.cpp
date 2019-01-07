
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include<iomanip>
#include<time.h>

//Skip lista
#define MAX_NUM 20

using namespace std;

struct slnode {
	int value;
	slnode*next[MAX_NUM];
};
struct SkipList {
	slnode*first;
	slnode*last;
	int tmplvl;
};

//zwarca nowy level
int level() {
	int l = 1;
	while (rand() % 2  and l< MAX_NUM)l++;
	 return l;
}

int ret_lvl(SkipList&s, int key){

	for (int i=s.tmplvl-1; i>=0; i--){
        slnode*v=s.first->next[i];

        while(v ->next[i] and v->value!=key){
            v=v->next[i];
        }
        if(v->value==key)return i;
	}
	return -1;
}



void find(SkipList&s, int key, slnode*prev[MAX_NUM], slnode*&v) {
	v = s.first;

	for (int i = MAX_NUM - 1; i >= 0; i--)
		prev[i] = s.first;

	for (int i = s.tmplvl - 1; i >= 0; i--) {
		while ((v->next[i]) && (v->next[i]->value < key))
			v = v->next[i];
		prev[i] = v;
	}
	if (v->next[0])      //przejscie na el, ktory moze byc rowny el szukanemu
		v = v->next[0];
	//zwracamy liste na el poprzedni
	//zwracamy ew szukany el
}

int ret_lvl2(SkipList&s, int key){
    int l=0;
    slnode*v;
	slnode*prev[MAX_NUM];

	find(s, key, prev, v);

	if (v->value==key){
        while (v->next[l]->value!=v->next[0]->value){
          cout << " lala ";
          l++;
        }
        return l-1;
	}
	return -100;
}



void PrintList(SkipList l) {
	for (int i = l.tmplvl - 1; i >= 0; i--) {
		cout << "lvl: " << i << "|";

		slnode* pom = l.first->next[i];
		while (pom != l.last) {
			cout << " " << pom->value;
			pom = pom->next[i];
		}
		cout << endl;
	}
}

void insertkey(SkipList&s, int key) {
	slnode*v;
	slnode*prev[MAX_NUM];

	find(s, key, prev, v);
	if (v->value == key)
		return;
	int h = level();
	 //cin >> h;

	if (h>s.tmplvl)
		s.tmplvl = h;
	slnode*n = new slnode;
	n->value = key;
	for (int i = 0; i<h; i++) {
		n->next[i] = prev[i]->next[i];
		prev[i]->next[i] = n;
	}
}

void deletekey(SkipList&s, int key) {
	slnode*v;
	slnode*prev[MAX_NUM];
	find(s, key, prev, v);
    int lvl=ret_lvl(s, key);
	for (int i = 0; i <=lvl; i++) {
		if (prev[i]->next[i]->next[i])
			prev[i]->next[i] = prev[i]->next[i]->next[i];
		else {
			prev[i]->next[i] = NULL;
		}
	}
}

int leng(SkipList&l) {
	slnode*v;
	v = l.first;
	int len = 0;
	while (v->next[0]!=NULL) {
		v = v->next[0];
		len++;
	}
	return len;
}

SkipList CreateList() {

	SkipList l;
	l.tmplvl = 0;
	l.first = new slnode;
	l.first->value = 0;
	l.last = NULL;

	for (int i = 0; i<20; i++) {
		l.first->next[i] = l.last;
	}

	return l;
}

SkipList merge_skiplist(SkipList s, SkipList t){
    SkipList w = CreateList();
    slnode*prev[MAX_NUM];
    slnode*v_s=s.first->next[0];
    slnode*v_t=t.first->next[0];
    slnode*v_w=w.first;
    int lvl;
    slnode * pom;

    for (int i=0; i<MAX_NUM-1; i++)
        prev[i]=w.first->next[i];

    while(v_s->next[0]!=s.last and v_t->next[0]!=t.last){
        if (v_s->value<v_t->value){
            pom=v_s;
            lvl=ret_lvl(s, v_s->value);
            if (lvl>w.tmplvl) w.tmplvl=lvl;
            for (int i=lvl; i>=0; i--){
                prev[i]->next[i]=v_s;
                v_s->next[i]=w.last;
            }
            v_s=pom;
            v_s=v_s->next[0];
        }
            else if (v_s->value>v_t->value){
                    cout << "cos";
                pom=v_t;
                cout << "cos";
                lvl=ret_lvl(t, v_t->value);
                cout << lvl << endl;
                if (lvl>w.tmplvl) w.tmplvl=lvl;
                cout << "cos";
                cout << "AAAAAAAA";
                for (int i=lvl; i>=0; i--){
                        cout << "gaz";
                        prev[i]->next[i]=v_t;
                        cout << "las";
                        v_t->next[i]=w.last;
                }
                v_t=pom;
                v_t=v_t->next[0];
            }
                else {

                }
    }


    return w;
}

int main() {
    srand(time(0));
	SkipList l = CreateList();
	insertkey(l, 2);
	insertkey(l, 4);
	insertkey(l, 3);
	insertkey(l, 15);
	insertkey(l, 43);
	SkipList t = CreateList();
	insertkey(t, 1);
	insertkey(t, 8);
	insertkey(t, 9);
	insertkey(t, 12);
	insertkey(t, 14);
	insertkey(t, 13);


    cout <<" SKIPLIST L: " << endl;
	PrintList(l);
    cout << endl << " SKIPLIST T: " << endl;
	PrintList(t);



    cout <<" SKIPLIST L: " << endl;
	PrintList(l);
    cout << endl << " SKIPLIST T: " << endl;
	PrintList(t);

	cout << endl << ret_lvl2(t,13) << endl;
	return 0;
}

