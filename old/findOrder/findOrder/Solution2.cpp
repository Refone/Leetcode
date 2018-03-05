//
//  Solution2.cpp
//  
//
//  Created by 信仰圣光吧 on 16/3/7.
//
//
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        const vector<int> null_res;
        vector<unordered_set<int>> graph(numCourses);
        vector<int> indegrees(numCourses,0);
        
        for (auto p : prerequisites) {
            graph[p.second].insert(p.first);
            ++indegrees[p.first];
        }
        
        int remain = numCourses;
        bool flag = true;
        while (remain>0 && flag) {
            flag = false;
            vector<int> del;
            for (int i=0; i<numCourses; i++) {
                if (indegrees[i]==0) {
                    del.push_back(i);
                    flag = true;
                }
            }
            
            for (auto d : del) {
                for (auto p = prerequisites.begin();p!=prerequisites.end();) {
                    if (p->second==d) {
                        --indegrees[p->first];
                        prerequisites.erase(p);
                    } else {
                        ++p;
                    }
                }
                res.push_back(d);
                indegrees[d] = -1;
                --remain;
            }
        }
        
        if (res.size()==numCourses) {
            return res;
        } else {
            return null_res;
        }
    }
};
