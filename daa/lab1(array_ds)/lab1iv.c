#include<stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a,b,c;
    printf("Enter the value of a,b,c\n");
    scanf("%d%d%d",&a,&b,&c);
    swap(&a,&b);
    swap(&a,&c);
    printf("After swapping a=%d,b=%d,c=%d\n",a,b,c);
}