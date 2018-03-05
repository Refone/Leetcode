//
//  main.cpp
//  coinChange
//
//  Created by 信仰圣光吧 on 16/2/26.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Solution3.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream infile("/Users/y/Public/programming/Leetcode/coinChange/datafile.txt");
    string line;
    
    getline(infile,line);
    istringstream s(line);
    
    vector<int> coins;
    int amount;
    
    int num;
    while (s>>num) {
        coins.push_back(num);
    }
    
    infile>>amount;
    Solution solution;
    cout<<solution.coinChange(coins, amount)<<endl;
    return 0;
}
