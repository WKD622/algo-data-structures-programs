#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    double val;
    node * next;
};

void add_node_val(node * list, double value)
{
    node *wart=list;
    while(wart->next != NULL && wart->next->val <= value)
        wart=wart->next;

    node* tmp = new node;
    tmp->val=value;
    tmp->next=wart->next;
    wart->next=tmp;
}

void countsort(int A[], int B[], int n, int k) //n - rozmiar tablic A i B, k - najwieksza wartosc
{
    int C[k+1];
    for(int i=0; i<=k; i++)
        C[i]=0;
    for(int i=0; i<n; i++)
        C[A[i]]++;
    for(int i=1; i<=k; i++)
        C[i]=C[i-1]+C[i];
    for(int i=n-1; i>=0; i--)
        B[(C[A[i]]--)-1] = A[i];
}

void radixsort(int A[], int B[], int n, int d)    //n - ilosc elementow w tablicy A,B, d - ilosc cyfr w liczbie
{
    int C[10];
    for(int j=0; j<d; j++)
    {
        for(int i=0; i<10; i++)
            C[i]=0;
        for(int i=0; i<n; i++)
            C[(A[i]/(int)pow(10,j))%10]++;
        for(int i=1; i<10; i++)
            C[i]=C[i-1]+C[i];
        for(int i=n-1; i>=0; i--)
            B[((C[(A[i]/(int)pow(10,j))%10])--)-1] = A[i];
        for(int i=0; i<n; i++)
            A[i]=B[i];
    }
}

node *bucketsort(node *list)
{
    /* Inicjalizacja tmp, liczby elementow, maksymalnej wartosci */
    node* tmp = list->next;
    int n = 0;
    int max_val = 0;
    while(tmp != NULL)
    {
        n++;
        if(tmp->val > max_val)
            max_val = tmp->val;
        tmp = tmp->next;
    }

    /* tworzy liste "koszy" i je wypelnia */
    node** bucket = new node * [n];

    for(int i = 0; i<n; i++)
    {
        bucket[i] = new node;
        bucket[i]->next = NULL;
    }

    tmp = list->next;
    int bucket_nr;
    while(tmp != NULL)
    {
        bucket_nr = tmp->val / (max_val+1) * n;
        add_node_val(bucket[bucket_nr], tmp->val);
        tmp = tmp->next;
    }

    /* scala kosze w jedna liste */
    for(int i=0; i<n-1; i++)
    {
        tmp = bucket[i]->next;
        if(tmp != NULL)
        {
            while(tmp->next != NULL)
                tmp=tmp->next;
            tmp->next=bucket[i+1]->next;
        }
    }

    return bucket[0];
}

int main()
{
    /* dane testowe do countsort, radixsort */
    int arr[]={12,43,62,42,67,51,72,92,80,20};
    int posort[10];
    //countsort(arr,posort,10,9);
    //radixsort(arr,posort,10,2);
    //for(int i=0; i<10; i++)
    //    cout<<posort[i]<<" ";


    /* dane testeowe do bucketsort */

    double arr2[10]={0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    node *node_arr = new node;
    node_arr->next = NULL;

    for(int i=0; i<10; i++)
        add_node_val(node_arr,arr2[i]);

    bucketsort(node_arr);

    node* tmp=node_arr->next;
    while(tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }

    return 0;
}
