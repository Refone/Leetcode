//
//  main.cpp
//  findItinerary
//
//  Created by 信仰圣光吧 on 16/2/21.
//  Copyright (c) 2016年 信仰圣光吧. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Solution.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream infile("/Users/y/Public/programming/Leetcode/findItinerary/findItinerary/datafile.txt");
    
    if (!infile) {
        cout<<"read file error!"<<endl;
        return 0;
    }
    
    typedef pair<string,string> TICKET;
    TICKET next_pair;
    vector<TICKET> ticket_vector;
    
    string line,first,second;
    istringstream stream;
    while (getline(infile, line)) {
        stream.str(line);
        stream>>first>>second;
//        cout<<first<<second<<endl;
        next_pair = make_pair(first, second);
        ticket_vector.push_back(next_pair);
        stream.clear();
    }
    
//    cout<<ticket_vector[2].second<<endl;
    Solution solution;
    vector<string> result = solution.findItinerary(ticket_vector);
    
    vector<string>::const_iterator it = result.begin();
    while (it != result.end()) {
        cout<<*it<<" ";
        ++it;
    }
    return 0;
}
