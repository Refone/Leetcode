//
//  main.cpp
//  wiggleSort
//
//  Created by 信仰圣光吧 on 16/2/25.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream infile("/Users/y/Public/programming/Leetcode/wiggleSort/datafile.txt");
    
    vector<int> nums;
    int num;
    while (infile>>num) {
        nums.push_back(num);
    }
    
    Solution solution;
    solution.wiggleSort(nums);
    
    vector<int>::const_iterator it = nums.begin();
    while (it != nums.end()) {
        cout<<*it<<" ";
        ++it;
    }
    return 0;
}
