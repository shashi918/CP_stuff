/**
 * max circular sub-array function tkas the array and no 
 * of elements algorithm is used is kadane algorithm 
 */
#include <iostream>  
int CircularSubarraySum(int arr[], int num)
{
    int max_sum = 0;
    int curr_sum;
   for (int i = 0; i <num; i++)
   {
       curr_sum = 0;
       for (int j = i; j < num+i; j++)
       {
           curr_sum = curr_sum + arr[j%num];
           if(curr_sum < 0)
               curr_sum = 0;
            if(max_sum < curr_sum)
           max_sum = curr_sum;
       }
   }
   if(max_sum == 0)
   {
       max_sum = arr[0];
       for(int i = 0; i < num-1; i++)
        if(max_sum < arr[i+1])
        {
            max_sum = arr[i+1];
        }
   }
   return max_sum;
}

int main()
{
int arr[] = {-2,-3, -1};
int n = sizeof(arr) / sizeof(arr[0]);
int c = CircularSubarraySum(arr, n);
printf("%d",c);
}