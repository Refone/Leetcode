//
//  main.cpp
//  findMinHeightTrees
//
//  Created by 信仰圣光吧 on 16/3/6.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream infile("/Users/y/Public/programming/Leetcode/findMinHeightTrees/input.txt");
    string line;
    vector<pair<int, int>> edges;
    
    while (getline(infile,line)) {
        pair<int, int> edge;
        istringstream s(line);
        s>>edge.first>>edge.second;
        edges.push_back(edge);
    }
    
    Solution solution;
    vector<int> roots(solution.findMinHeightTrees(int(edges.size()+1), edges));
    for (vector<int>::iterator iter=roots.begin(); iter!=roots.end(); iter++) {
        cout<<*iter<<endl;
    }
    
    return 0;
}
