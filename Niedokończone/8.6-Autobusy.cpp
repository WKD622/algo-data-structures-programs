#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
const int BUSES_NUM=5;
const int CITIES_NUM=5;

using namespace std;

struct SetNode{
    char city;
    SetNode*parent;
    int rank;
};
struct bus{
    int start;
    int destination;
    int capacity;

};

SetNode* FindSet(SetNode*x);
void MakeSet(SetNode*x);
void Union(SetNode*x,SetNode*y);
void PrintSets(SetNode*data[]);
void InitBuses(bus buses[]);
void InitCities(SetNode*data[CITIES_NUM]);

void CapacityInsertSort(bus buses[]);
void PrintBuses(SetNode*cities[],bus buses[]);
int Groups(SetNode*cities[],bus buses[],int tourist_num,int start_index,int destination_index);

int main(){
    SetNode*cities[CITIES_NUM];
    InitCities(cities);

    bus buses[BUSES_NUM];
    InitBuses(buses);
    PrintBuses(cities,buses);

    int tourist_num;
    cout << "Ilu turystow potrzebujesz przewiezc: ";
    cin >> tourist_num;
    cout << "Trzeba ich podzielic na " << Groups(cities,buses,tourist_num,0,4) << " grup.";
    return 0;
}
int Groups(SetNode*cities[],bus buses[],int tourist_num,int start_index,int destination_index){
    CapacityInsertSort(buses);
    PrintBuses(cities,buses);
    int i=0;
    int capacity;
    while(i<BUSES_NUM and FindSet(cities[start_index])!=FindSet(cities[destination_index])){
        Union(cities[buses[i].start],cities[buses[i].destination]);
        capacity=buses[i].capacity;
        i++;
    }
    if(i!=BUSES_NUM)
        return ceil((double)tourist_num/capacity);
    return 0;
}
void CapacityInsertSort(bus buses[]){
    for(int i=1;i<BUSES_NUM;i++){
        bus tmp=buses[i];
        int j;
        for(j=i-1;j>=0 && buses[j].capacity<tmp.capacity;j--){
            buses[j+1]=buses[j];
        }
        buses[j+1]=tmp;
    }
}
void MakeSet(SetNode*x){
    x->parent=x;
    x->rank=0;
}
SetNode* FindSet(SetNode*x){
    //cout << " parent " << x->val << " to ";
    if(x!=x->parent)
        x->parent=FindSet(x->parent);
    return x->parent;
}
void Union(SetNode*x,SetNode*y){
    SetNode*s1=FindSet(x);
    SetNode*s2=FindSet(y);
    if(s1==s2)
        return;
    if(s1->rank < s2->rank){
        s1->parent=s2;
        //cout << s1->val << " parent na " << s1->parent->val << endl;
    }else{
        s2->parent=s1;
        //cout << s2->val << " parent na " << s2->parent->val << endl;
        if(s1->rank==s2->rank)
            s1->rank++;
    }
}
void InitBuses(bus buses[]){
    int starts[BUSES_NUM]={0,0,1,1,3};
    int destinations[BUSES_NUM]={1,3,2,4,4};
    int capacity[BUSES_NUM]={5,3,4,3,6};
    for(int i=0;i<BUSES_NUM;i++){
        buses[i].start=starts[i];
        buses[i].destination=destinations[i];
        buses[i].capacity=capacity[i];
    }
}
void InitCities(SetNode*data[CITIES_NUM]){
    char cities_names[CITIES_NUM]={'A','B','C','D','E'};
    for(int i=0;i<CITIES_NUM;i++){
        data[i]=new SetNode;
        data[i]->city=cities_names[i];
        MakeSet(data[i]);
    }
}
void PrintBuses(SetNode*cities[],bus buses[]){
    cout << endl << "Trasy: " << endl;
    for(int i=0;i<BUSES_NUM;i++){
        cout << "Z " << cities[buses[i].start]->city << " do " << cities[buses[i].destination]->city << " o pojemnosci " << buses[i].capacity << endl;
    }
}
