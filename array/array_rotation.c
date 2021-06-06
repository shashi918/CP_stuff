#include <stdio.h>
void leftrotate(int[], int,int);
void reversearray(int[],int, int);

int main() {
    int testcases;
    scanf("%d",&testcases);
    while(testcases != 0)
    {
        int size;
        scanf("%d",&size);
        int arr[size];
        int rotate;
        scanf("%d",&rotate);
        for (size_t i = 0; i < size; i++)
        {
            scanf("%d",&arr[i]);
        }
        int n = sizeof(arr)/sizeof(arr[0]);
        leftrotate(arr, rotate, n);
        for (size_t i = 0; i < size; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
        testcases--;
    }
}

void leftrotate(int arr[], int d, int n) {
    if (d == 0)
    return;
    d = d % n;
    reversearray(arr, 0, d -1);
    reversearray(arr, d, n -1);
    reversearray(arr, 0, n -1);
}

void reversearray(int arr[], int start, int end) {

    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
