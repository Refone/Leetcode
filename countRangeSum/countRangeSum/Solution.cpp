//
//  Solution.cpp
//  
//
//  Created by 信仰圣光吧 on 16/2/24.
//
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper)
    {
        int n = int(nums.size());
        int ret = 0;
        int sum;
        
        if (n==0) {return ret;}
        
        int sums[10000][10000] = {0};
        
        for (int i=0;i<n;i++){
            sums[i][i] = nums[i];
            if (nums[i]>=lower && nums[i]<=upper) {++ret;}
        }
        
        for (int i=1;i<n;i++){
            for (int j=0;j+i<n;j++){
                sum = sums[j][j+i-1] + nums[j+i];
                sums[j][j+i] = sum;
                if (sum>=lower && sum<=upper) {++ret;}
            }
        }
        return ret;
    }
};