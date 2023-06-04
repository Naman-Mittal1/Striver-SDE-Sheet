#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long water = 0;
    
    if(n < 3) {
        return water; 
    }
    
    int left = 0; 
    int right = n - 1; 
    
    long leftMax = arr[left]; 
    long rightMax = arr[right]; 
    
    while(left < right) {
        if(arr[left] <= arr[right]) {
            if(arr[left] > leftMax) {
                leftMax = arr[left];
            } else {
                water += (leftMax - arr[left]);
            }
            left++;
        } else {
            if(arr[right] > rightMax) {
                rightMax = arr[right];
            } else {
                water += (rightMax - arr[right]);
            }
            right--;
        }
    }
    
    return water;
}