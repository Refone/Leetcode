//
//  main.cpp
//  maxProduct
//
//  Created by 信仰圣光吧 on 16/3/4.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    ifstream infile("/Users/y/Public/programming/Leetcode/maxProduct/input.txt");
    
    vector<string> words;
    string word;
    while (infile>>word) {
        words.push_back(word);
    }
    
    Solution solution;
    cout<<solution.maxProduct(words)<<endl;
    return 0;
}
