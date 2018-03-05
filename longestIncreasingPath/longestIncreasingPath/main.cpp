//
//  main.cpp
//  longestIncreasingPath
//
//  Created by 信仰圣光吧 on 16/2/24.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Solution.cpp"
#include "SolutionDFS.cpp"
#include "SolutionDFS2.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream infile("/Users/y/Public/programming/Leetcode/longestIncreasingPath/datafile.txt");
    
    vector<vector<int>> matrix;
    int i=0;
    string line;
    istringstream s;
    int num;
    
    while (getline(infile,line)) {
        s.str(line);
        vector<int> m;
        while (s>>num) {
            m.push_back(num);
        }
        matrix.push_back(m);
        ++i;
        s.clear();
    }
    
    SolutionDFS2 solution;
    cout<<solution.longestIncreasingPath(matrix)<<endl;
    return 0;
}
