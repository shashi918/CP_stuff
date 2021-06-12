#include <iostream>
int SubarraySum(int arr[], int num)
{
    int max = 0;
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        count += arr[i];
        if(count < 0)
        {
        count = 0;
        }
        else if (count > max)
        max = count;
    }
    return max;
}

int main()
{
int arr[] = {-2,-3,4,-1,-2,1,5,-3};
int c = SubarraySum(arr, 8);
printf("%d",c);
}