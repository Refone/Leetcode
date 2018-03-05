//
//  main.cpp
//  isValidSerialization
//
//  Created by 信仰圣光吧 on 16/2/21.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "Solution.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream infile("/Users/y/Public/programming/Leetcode/isValidSerialization/isValidSerialization/datafile.txt");
    string pre_order_str;
    infile>>pre_order_str;
    
    Solution solution;
    cout<<solution.isValidSerialization(pre_order_str)<<endl;
    return 0;
}
