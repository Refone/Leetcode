//
//  main.cpp
//  countRangeSum
//
//  Created by 信仰圣光吧 on 16/2/24.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "SolutionDC.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream infile("/Users/y/Public/programming/Leetcode/countRangeSum/datafile.txt");
    istringstream instream;
    string line;
    
    getline(infile,line);
    instream.str(line);
    int num;
    int lower;
    int upper;
    vector<int> nums;
    
    while (instream>>num) {
        nums.push_back(num);
    }
    
    infile>>lower;
    infile>>upper;
    
    SolutionDC solution;
    cout<<solution.countRangeSum(nums, lower, upper)<<endl;
    return 0;
}
