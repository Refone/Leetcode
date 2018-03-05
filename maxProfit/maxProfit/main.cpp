//
//  main.cpp
//  maxProfit
//
//  Created by 信仰圣光吧 on 16/2/26.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Solution.cpp"

using namespace std;
int main(int argc, const char * argv[]) {
    ifstream infile("/Users/y/Public/programming/Leetcode/maxProfit/datafile.txt");
    
    vector<int> prices;
    int price;
    while (infile>>price) {
        prices.push_back(price);
    }
    
    Solution solution;
    cout<<solution.maxProfit(prices)<<endl;
    return 0;
}
