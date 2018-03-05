//
//  main.cpp
//  exist
//
//  Created by 信仰圣光吧 on 16/3/4.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Solution.cpp"
using namespace std;

int main() {
    ifstream infile("/Users/y/Public/programming/Leetcode/exist/input.txt");
    string line;
    vector<vector<char>> map;
    
    while (getline(infile,line)) {
        istringstream s(line);
        vector<char> aline;
        char c;
        while (s>>c) {
            aline.push_back(c);
        }
        map.push_back(aline);
    }
    
    string str("acdb");
    
    Solution solution;
    cout<<solution.exist(map, str)<<endl;
    
    return 0;
}
