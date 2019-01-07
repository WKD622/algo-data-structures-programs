#include <iostream>
#include <time.h>
#include <cstdlib>
#define m 20

using namespace std;

//STRUKTURY
struct SLNode{
    int val;
    SLNode * next[m];
};
struct SkipList{
    SLNode * first;
    SLNode * last;
    int lvl;
};

//FUNKCJE
int level(float n){  //LOSUJE LEVEL DLA NOWEGO ELEMENTU
    int l=0;
    while(rand()%2 < n) l++;
    if (l<m) return l;
        else return m-1;
}
int repair_level(SkipList &s){  //JESLI OD SKIPLISTY ODPINAMY ELEMENT USTAWIA NOWY MAKSYMALNY LEVEL
    for (int i=s.lvl; i>0; i--){
        if (s.first->next[i]==s.last){
            s.lvl--;
        }
    }
    return s.lvl;
}
int return_level(SkipList s, int value){  //ZWRACA LEVEL ELEMENTU O WYSZCZEGOLNIONEJ WERTOSCI
    SLNode*pom=s.first;
    SLNode*prev[m];
    if (pom->next[0]!=s.last){
        for (int i=s.lvl; i>=0; i--){
            while (pom->next[i]->val<value)
                pom=pom->next[i];
            prev[i]=pom;
        }
        int i=0;
        pom=pom->next[0];
        if (pom->val==value){
            while (i<=s.lvl and ((prev[i]->next[i]==pom and pom->next[i]!=s.last) or (prev[i]->next[i]==pom and pom->next[i]==s.last))){
                i++;
            }
            return --i;
        }
    }
}
void update_level_of_SkipList(SkipList &s){  //USTAWIA POPRAWNY LEVEL CALEJ SKIPLISCIE
    int i=0;
    while(s.first->next[i]!=s.last and i<m){
        i++;
    }
    --i;
    s.lvl=i;
}
void PrintList(SkipList s){  //WYPISUJE SKIPLISTE
    cout << endl;
    for (int i=s.lvl; i>=0; i--){
        cout << "LVL "<< i << " |";
        SLNode *pom=s.first->next[i];
        while(pom!=s.last){
            cout << " " << pom -> val;
            pom=pom->next[i];
        }
        cout << endl;
    }
    cout << endl;
}
SkipList CreateList(){  //TWORZY SKIPLISTE
    SkipList l;
    l.lvl=0;
    l.first = new SLNode;
    l.last = new SLNode;
    l.first->val=-32000;
    l.last->val=32000;
    for (int i=m-1; i>=0; i--){
        l.first->next[i]=l.last;
    }
    return l;
}
void Insert (SkipList &s, int value){  //WSTAWIA NOWY ELEMENTY DO SKIPLISTY
    SLNode*it=s.first;
    SLNode*prev[20];

    for (int i=m-1; i>=0; i--){
        prev[i]=s.first;
    }
    for (int i=s.lvl; i>=0; i--){
        while(it->next[i]->val<value){
                it=it->next[i];
        }
        prev[i]=it;
    }
    it=it->next[0];

    if(it->val==value) return;
        else{
            int curr=level(0.5);
            if (curr>s.lvl) s.lvl=curr;
            SLNode*x=new SLNode;
            x->val=value;
            for (int i=curr; i>=0; i--){
                x->next[i]=prev[i]->next[i];
                prev[i]->next[i]=x;
            }
        }
}
bool find_val(SkipList s, int value){  //SPRAWDZA CZY DANA WARTOSC JEST JUZ W SKIPLISCIE
    SLNode *pom=s.first;
    if (pom->next[0]==s.last) return false;
        else{
            for (int i=s.lvl; i>=0; i--){
                while (pom->next[i]->val<value){
                    pom=pom->next[i];
                }
            }
            pom=pom->next[0];
            if (pom->val==value) return true;
                else return false;
        }
}
void delete_val(SkipList &s, int value){  //USUWA WYSZCZEGOLNIONA WARTOSC ZE SKIPLISTY
    SLNode*prev[m];
    SLNode*pom=s.first;
    if (pom->next[0]!=s.last){
        for (int i=s.lvl; i>=0; i--){
            while (pom->next[i]->val<value)
                pom=pom->next[i];
            prev[i]=pom;
        }
        pom=pom->next[0];
        if (pom->val==value){
            for (int i=0; i<=s.lvl; i++){
                if (prev[i]->next[i]->val==pom->val){
                    prev[i]->next[i]=pom->next[i];
                }
            }
            delete pom;
            s.lvl=repair_level(s);
        }
    }
}
void delete_part(SkipList &s, int b, int e){  //USUWA ELEMENTY Z PRZEDZIALU WARTOSCI ZE SKIPLISTY
    SLNode*prev_b[m];
    SLNode*prev_e[m];
    SLNode*pom=s.first;
    if (pom->next[0]!=s.last){
        for (int i=s.lvl; i>=0; i--){
            while (pom->next[i]->val<b)
                pom=pom->next[i];
            prev_b[i]=pom;
        }
        pom=s.first;
        for (int i=s.lvl; i>=0; i--){
            while (pom->next[i]->val<e)
                pom=pom->next[i];
            prev_e[i]=pom;
        }
        //USUWANIE ELEMENTOW
        pom=prev_b[0]->next[0];
        while (pom!=prev_e[0]->next[0]){
            SLNode*pom2=pom;
            pom=pom->next[0];
            delete pom2;
        }
        //PRZEPINANIE ELEMENTOW
        for (int i=s.lvl; i>=0; i--)
                prev_b[i]->next[i]=prev_e[i]->next[i];
        s.lvl=repair_level(s);
    }
}
void mov_val(SkipList &s, SkipList &t, int value_s_to_t){  //PRZEPINA WARTOSC Z JEDNEJ SKIPLISTY DO DRUGIEJ
    SLNode*pom=s.first;
    SLNode*prev[m];
    //USTAWIAM PREVY NA SKIPLISCIE S PRZED WARTOSCIA DO PRZEPIECIA
    for (int i=s.lvl; i>=0; i--){
        while (pom->next[i]->val < value_s_to_t)
            pom=pom->next[i];
        prev[i]=pom;
    }
    //PRZESKAKUJE NA WARTOSC DO PRZEPIECIA I PREVAMI LACZE WARTOSCI WCZESNIEJSZE Z POZNIEJSZYMI
    pom=pom->next[0];
    if (pom->val==value_s_to_t){
        int x=return_level(s,pom->val);
        for (int i=x; i>=0; i--){
            prev[i]->next[i]=pom->next[i];
        }
        //NAPRAWIAM POZIOMY SKIPLISTY S, NA WYPADEK JESLI WYPIETY ELEMENT BYL NAJWYZSZY
        repair_level(s);

        //UPDATEUJE LEVEL SKIPLISTY T NA WYPADEK GDYBY PRZEMINANY ELEMENT BYL WYZSZY NIZ TE DOTYCHCZAS I USTAWIAM TEGO SAMEGO PREVA BO NIE JEST MI JUZ POTRZEBNY W ODPOWIEDNIE MIEJSCE
        SLNode*pom2=t.first;
        if (x>t.lvl) t.lvl=x;
        for (int i=t.lvl; i>=0; i--){
            while (pom2->next[i]->val < value_s_to_t)
                pom2=pom2->next[i];
            prev[i]=pom2;
        }
        //WPINAM NOWA WARTOSC I NAPRAWIAM LEVEL T
        if (pom2->next[0]->val!=value_s_to_t){
            for (int i=x; i>=0; i--){
                pom->next[i]=prev[i]->next[i];
                prev[i]->next[i]=pom;
            }
            repair_level(t);
        }
    }
}
void set_end(SkipList &s, SLNode*e[m]){  //PRZESUWA TABLICE WSKAZNIKOW NA SLNODE NA SAM KONIEC, TUZ PRZED S.LAST
    SLNode*pom=s.first;
    for (int i=m-1; i>=0; i--){
        while(pom->next[i]!=s.last){
            pom=pom->next[i];
        }
        e[i]=pom;
    }
}
SkipList merge_SkipLists(SkipList s, SkipList t){  //SCALA DWIE SKIPLISTY
    SkipList w=CreateList();
    SLNode*pom_s=s.first;
    SLNode*pom_t=t.first;
    SLNode*prev[m];
    SLNode*e[m];

    while (pom_s->next[0]!=s.last and pom_t->next[0]!=t.last){  //DOPOKI NIE SKONCZY SIE JEDNA ZE SKIPLIST PRZEPINAM
        set_end(w,e);
        //PRZEPINANIE ZE SKIPLISTY S
        for (int i=s.lvl; i>=0; i--){
            while (pom_s->next[i]->val < pom_t->next[0]->val){
                pom_s=pom_s->next[i];
            }
            prev[i]=pom_s;  //USTAWIAM PREVY NA SKIPLISCIE S ZEBY ODPIAC ELEMENTY
        }
        if (pom_s!=s.first){
            w.lvl=m-1;
            for (int i=s.lvl; i>=0; i--){
                if (s.first->next[i]->val<t.first->next[0]->val){
                    e[i]->next[i]=s.first->next[i];
                    s.first->next[i]=prev[i]->next[i];
                    prev[i]->next[i]=w.last;
                }
            }
            update_level_of_SkipList(w);
            update_level_of_SkipList(s);
        }
        pom_s=s.first;
        //--------------------------------------------------------------------------
        //PRZEPINANIE ZE SKIPLISTY T
        set_end(w,e);
        for (int i=t.lvl; i>=0; i--){
            while(pom_t->next[i]->val < pom_s->next[0]->val){
                pom_t=pom_t->next[i];
            }
            prev[i]=pom_t;
        }
        if (pom_t!=t.first){
            w.lvl=m-1;
            for (int i=t.lvl; i>=0; i--){
                if (t.first->next[i]->val<s.first->next[0]->val){
                    e[i]->next[i]=t.first->next[i];
                    t.first->next[i]=prev[i]->next[i];
                    prev[i]->next[i]=w.last;
                }
            }
        }
        pom_t=t.first;
    }
    return w;
}
void Subtract_SkipLists(SkipList &s, SkipList t){  //OBLICZANIE ROZNICY SKIPLISTY S I T (S-T)
    SLNode*pom_s=s.first;
    SLNode*pom_t=t.first;
    SLNode*prev[m];

    while (pom_s->next[0]!=s.last and pom_t->next[0]!=t.last){
        pom_t=t.first;
        for (int i=t.lvl; i>=0; i--){
            while (pom_t->next[i]->val<pom_s->next[0]->val){
                pom_t=pom_t->next[i];
            }
        }
        pom_s=s.first;
        for (int i=s.lvl; i>=0; i--){
            while (pom_s->next[i]->val<pom_t->next[0]->val){
                pom_s=pom_s->next[i];
            }
            prev[i]=pom_s;
        }
        if (pom_t->next[0]->val == pom_s->next[0]->val and pom_t->next[0]!=t.last and pom_s->next[0]!=s.last){
            pom_t=pom_t->next[0];
            pom_s=pom_s->next[0];
            for (int i=s.lvl; i>=0; i--){
                if (prev[i]->next[i]==pom_s){
                    prev[i]->next[i]=pom_s->next[i];
                }
            }
            update_level_of_SkipList(s);
        }
    }
}

//PROGRAM
int main(){

    srand(time(0));

    SkipList s=CreateList();

    Insert(s,1);
    Insert(s,2);
    Insert(s,3);
    Insert(s,4);
    Insert(s,5);
    Insert(s,6);
    Insert(s,7);

    PrintList(s);
    delete_part(s,3,5);
    PrintList(s);
    return 0;
}


