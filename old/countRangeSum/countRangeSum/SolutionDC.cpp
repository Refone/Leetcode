//
//  SolutionDC.cpp
//  
//
//  Created by 信仰圣光吧 on 16/2/24.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
class SolutionDC {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = int(nums.size());
        int ret = 0;
        
        if(n){
            ret = rangeSum(nums, 0, n-1, lower, upper);
        }
        
        return ret;
    }
    
private:
    int rangeSum(vector<int>& nums, int left, int right, int lower, int upper){
        //cout<<"rangSum("<<left<<","<<right<<"):"<<endl;
        int ret;
        if (left==right) {
            ret = ((nums[left]>=lower)&&(nums[right]<=upper))?1:0;
            return ret;
        }
        
        int mid =(left + right)/2;
        int leftSum = rangeSum(nums, left, mid, lower, upper);
        int rightSum = rangeSum(nums, mid+1, right, lower, upper);
        int crossSum = 0;
        
        //long[] arr = new long[right-mid];
        vector<long> arr;
        long sum = 0;
        for (int i= mid+1; i<=right; i++) {
            sum += nums[i];
            arr.push_back(sum);
        }
        
        sort(arr.begin(),arr.end());
        
        sum = 0;
        for (int i=mid; i>=left; i--) {
            sum += nums[i];
            crossSum += binarySearch(arr, upper-sum+0.5) - binarySearch(arr, lower-sum-0.5);
        }
        
        return leftSum + rightSum + crossSum;
    }
    
    int binarySearch(vector<long>& arr, double upper){
        //how many items there in arr < upper
        int r = int(arr.size()-1);
        int l = 0;
        int m = 0;
        
        while (l<=r) {
            m = (l+r)/2;
            if (arr[m]<=upper) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return l;
    }
};