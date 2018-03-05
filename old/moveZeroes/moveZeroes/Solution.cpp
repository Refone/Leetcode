//
//  Solution.cpp
//  
//
//  Created by 信仰圣光吧 on 16/3/4.
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1;
        int j = 0;
        int n = int(nums.size());
        
        for (j=0; j<n; j++) {
            if (nums[j]!=0) {
                ++i;
                if (i!=j) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
};
