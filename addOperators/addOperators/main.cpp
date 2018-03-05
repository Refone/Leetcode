//
//  main.cpp
//  addOperators
//
//  Created by 信仰圣光吧 on 16/3/8.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "Solution.cpp"

using namespace std;

int main() {
    ifstream infile("/Users/y/Public/programming/Leetcode/addOperators/input.txt");
    string numStr;
    int result;
    
    infile>>numStr;
    infile>>result;
    
    Solution solution;
    vector<string> res = solution.addOperators(numStr, result);
    for (auto r : res) {
        cout<<r<<endl;
    }
    
    return 0;
}
