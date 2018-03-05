//
//  main.cpp
//  MinPatches
//
//  Created by 信仰圣光吧 on 16/2/22.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Solution.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream infile("/Users/y/Public/programming/Leetcode/MinPatches/MinPatches/datafile.txt");
    istringstream iss;
    string line;
    getline(infile,line);
    iss.str(line);
    vector<int> nums;
    int num;
    int range;
    
    while (iss>>num) {
        nums.push_back(num);
    }
    
    infile>>range;
    
    Solution solution;
    int result = solution.minPatches(nums, range);
    cout<<result<<endl;
    return 0;
}
