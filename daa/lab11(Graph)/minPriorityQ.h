#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int heapsize;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int a[],int i)
{
    int smallest;
    int l=2*i;
    int r=2*i+1;
    if(l<=heapsize && a[l]<a[i])
    {
        smallest=l;
    }
    else
    {
        smallest=i;
    }
    if(r<=heapsize && a[r]<a[smallest])
    {
        smallest=r;
    }
    if(smallest!=i)
    {
        swap(&a[i],&a[smallest]);
        heapify(a,smallest);
    }
}
void buildheap(int a[],int n)
{
    int i;
    heapsize=n;
    for(i=n/2;i>=1;i--)
        heapify(a,i);
}
int minimum(int a[])
{
    return a[1];
}
int extractmin(int a[])
{
    if(heapsize<1)
    {
        printf("Heap Underflow");
        return -1;
    }
    int min=a[1];
    a[1]=a[heapsize];
    heapsize--;
    heapify(a,1);
    return min;
}
void decreasekey(int a[],int i,int key)
{
    if(key>a[i])
    {
        printf("New key is greater than current key");
        return;
    }
    a[i]=key;
    while(i>1 && a[i/2]>a[i])
    {
        swap(&a[i],&a[i/2]);
        i=i/2;
    }
}
void insert(int a[],int key)
{
    heapsize++;
    a[heapsize]=INT_MAX;
    decreasekey(a,heapsize,key);
}

void increasekey(int a[],int i,int key)
{
    if(key<a[i])
    {
        printf("New key is smaller than current key");
        return;
    }
    a[i]=key;
    heapify(a,i);
}
void deletekey(int a[],int i)
{
    decreasekey(a,i,INT_MIN);
    extractmin(a);
}
void changekey(int a[],int i,int key)
{
    if(key>a[i])
    {
        increasekey(a,i,key);
    }
    else if(key<a[i])
    {
        decreasekey(a,i,key);
    }
}