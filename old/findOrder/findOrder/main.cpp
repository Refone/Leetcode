//
//  main.cpp
//  findOrder
//
//  Created by 信仰圣光吧 on 16/3/7.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "acDFS.cpp"

using namespace std;

int main() {
    ifstream infile("/Users/y/Public/programming/Leetcode/findOrder/input.txt");
    int courseNum;
    vector<pair<int, int>> prerequistes;
    string line;
    
    getline(infile, line);
    istringstream s(line);
    s>>courseNum;
    
    while (getline(infile,line)) {
        pair<int,int> edge;
        istringstream s(line);
        s>>edge.first>>edge.second;
        prerequistes.push_back(edge);
    }
    
    Solution solution;
    vector<int> res = solution.findOrder(courseNum, prerequistes);
    for (auto r:res) {
        cout<<r<<" ";
    }
    
    return 0;
}
