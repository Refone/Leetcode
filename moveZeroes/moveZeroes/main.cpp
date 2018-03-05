//
//  main.cpp
//  moveZeroes
//
//  Created by 信仰圣光吧 on 16/3/4.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "Solution.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream infile("/Users/y/Public/programming/Leetcode/moveZeroes/input.txt");
    vector<int> nums;
    int num;
    
    while (infile>>num) {
        nums.push_back(num);
    }
    
    Solution solution;
    solution.moveZeroes(nums);
    
    vector<int>::const_iterator it = nums.begin();
    while (it!=nums.end()) {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    
    return 0;
}
