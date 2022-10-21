#include<stdio.h>
#include<time.h>
#include<math.h>
int insertion_sort_asc(int ar[],int n)
{
    int i,j,temp,count=1;
    for(i=1;i<n;i++)
    {
        count+=2;
        temp=ar[i];
        for(j=i-1;j>=0&&ar[j]>temp;j--)
        {
            count++;
            ar[j+1]=ar[j];
        }
        ar[j+1]=temp;
    }
    return count;
}
int insertion_sort_desc(int ar[],int n)
{
    int i,j,temp,count=1;
    for(i=1;i<n;i++)
    {
        temp=ar[i];
        count+=2;
        for(j=i-1;j>=0&&ar[j]<temp;j--)
        {
            count++;
            ar[j+1]=ar[j];
        }
        ar[j+1]=temp;
    }
    return count;
}

void give_values(int ar[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        ar[i]=rand()%100;
    }
}
void print_array(int ar[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");
}

int main()
{
    clock_t start,end;
    start=clock();
    int c=1;
    int n,d,a;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int ar[n];
    int arr2[10000];
    while(c)
    {
        printf("0. Exit\n");
        printf("1. Input array\n");
        printf("2. Output array\n");
        printf("3. Sort array in ascending order\n");
        printf("4. Sort array in descending order\n");
        printf("5. Computational time to sort in ascending order random data\n");
        printf("6. Computational time to sort in ascending order of already ascendingly sorted data\n");
        printf("7. Computational time to sort in ascending order of already descendingly sorted data\n");
        printf("8. 3,4,5. for values 5000 to 50000\n");
        printf("Enter your choice: ");

        scanf("%d",&c);     
        int i,j;
        switch(c)
        {
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                printf("Enter the elements: ");
                give_values(ar,n);
                break;
            case 2:
                printf("\n-------------------------------\n\n");
                print_array(ar,n);
                printf("\n\n-------------------------------\n\n");
                break;
            case 3:
                insertion_sort_asc(ar,n);
                break;
            case 4:
                insertion_sort_desc(ar,n);
                break;
            case 5:
                printf("\n-------------------------------\n\n");
                insertion_sort_asc(ar,n);
                printf("\n\n-------------------------------\n\n");

                break;
            case 6:
                printf("\n-------------------------------\n\n");
                printf("Computational time to sort in ascending order of already ascendingly sorted data: ");
                insertion_sort_asc(ar,n);
                insertion_sort_asc(ar,n);
                printf("\n\n-------------------------------\n\n");
                break;
            case 7:
                printf("\n-------------------------------\n\n");
                printf("Computational time to sort in ascending order of already descendingly sorted data: ");
                insertion_sort_desc(ar,n);
                insertion_sort_asc(ar,n);
                printf("\n\n-------------------------------\n\n");
                break;
            case 8:
                printf("\n-------------------------------\n\n");
                give_values(arr2,10000);
                insertion_sort_asc(arr2,10000);
                insertion_sort_asc(arr2,10000);
                insertion_sort_desc(arr2,10000);
                insertion_sort_asc(arr2,10000);
                
                printf("\n\n-------------------------------\n\n");



                break;
            default:
                printf("Invalid choice\n");
        }



    }
    end=clock();
    float time=(float)end-start;
    printf("\n\nTime taken: %f nano-seconds\n",time);
    return 0;
}