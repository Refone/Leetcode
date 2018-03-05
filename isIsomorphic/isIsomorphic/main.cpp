//
//  main.cpp
//  isIsomorphic
//
//  Created by 信仰圣光吧 on 16/3/3.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Solution.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream infile("/Users/y/Public/programming/Leetcode/isIsomorphic/input.txt");
    string s;
    string t;
    
    infile>>s;
    infile>>t;
    
    Solution solution;
    cout<<solution.isIsomorphic(s,t)<<endl;
    return 0;
}
