#include <iostream>
#include<algorithm>
using namespace std;
int linear_search(vector<int> arr , int n , int target){
    for (int i = 0; i<n; i++){
        if(arr[i]==target){
            return i+1;
        }
       
    }
    return 0;

}

int binary_search(int start , int end  ,int target , vector<int> arr){
    
    while (start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==target){
            return mid+1;
        }
        else if (arr[mid]>target){
            end  = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    return 0;
}
int fibonacciSearch(vector<int> arr , int n, int target)
{
    int fib2 = 0;     
    int fib1 = 1;     
    int fibM = fib1 + fib2;  // F(k)

    // Find smallest Fibonacci number >= n
    while (fibM < n)
    {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib1 + fib2;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = min(offset + fib2, n - 1);

        if (arr[i] < target)
        {
            
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;

            offset = i;
        }

        else if (arr[i] > target)
        {
            // Target is on the left
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        }

        else
        {
            return i;
        }
    }

    if (fib1 == 1 && arr[offset + 1] == target)
        return offset + 1;

    return 0;
}
int main(){
    int target = 20 ;
    vector<int> arr = {1,2,4,10,15,20,100};
    int n = 8;
//     int temp = linear_search(arr,n,target);
//    if(temp){
//     cout<<"found at "<<temp<<endl;
//    }
//    else cout<<"not found"<<endl;
    //  int temp = binary_search(0 , n-1 , target,arr);
    //  if (temp){
    //     cout<<"found at "<< temp<<endl;
    //  }
    //  else {
    //     cout<<"not found"<<endl;
    //  }
    int fib_result = fibonacciSearch(arr,n,target);
    cout<<fib_result<<endl;
    return 0 ;
}


