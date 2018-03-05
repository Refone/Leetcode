//
//  Solution.cpp
//  
//
//  Created by 信仰圣光吧 on 16/2/25.
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = int(nums.size());
        int m = n/2;
        
        vector<int>::iterator it = nums.begin() + m;
        
        nth_element(nums.begin(), it, nums.end());
        int mid = *it;
        
        // Index-rewiring.
        #define A(i) nums[(1+2*(i)) % (n|1)]
        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
            
        }
    }
    
private:
    void showVector(vector<int>& nums){
        vector<int>::const_iterator it = nums.begin();
        while (it != nums.end()) {
            cout<<*it<<" ";
            ++it;
        }
        cout<<endl;
    }
};