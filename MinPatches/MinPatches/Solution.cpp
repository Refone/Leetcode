//
//  Solution.cpp
//  
//
//  Created by 信仰圣光吧 on 16/2/22.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        int len = int(nums.size());
        int sum = 0;
        int patch = 0;
        int count = 0;
        
        while (sum < n) {
            if (count != len && nums[count] <= sum + 1) {
                sum += nums[count];
                count ++;
            }
            else {
                cout<<sum+1<<endl;
                patch ++;
                if (sum > (INT_MAX - 1) / 2) {
                    sum = INT_MAX;
                }
                else {
                    sum = sum * 2 + 1;
                }
            }
        }
        
        return patch;
    }
};