#include<stdio.h>

int main(){
    int arr[100],n,i,max;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    max=arr[0];
    for(i=1;i<n;i++)
        if(arr[i]>max)
            max=arr[i];
    printf("Largest element is %d",max);
    return 0;
}
