//
//  Solution.cpp
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
        vector<unordered_set<int>> graph(numCourses+1);
        vector<int> indegrees(numCourses,0);
        
        for (auto p : prerequisites) {
            graph[p.second].insert(p.first);
            ++indegrees[p.first];
        }
        
        //set as start point if indegree is 0
        vector<int> startPoint;
        int i = 0;
        for (auto d : indegrees) {
            if (!d) {startPoint.push_back(i);}
            ++i;
        }
        
        if (startPoint.size()==0) {
            return null_res;
        }
        
        for (auto p : startPoint){
            graph[numCourses].insert(p);
        }
        
        vector<bool> visited(numCourses,false);
        
        dfs(numCourses, graph, visited, res);
        
        reverse(res.begin(), res.end());
        res.erase(res.begin());
        if (res.size()<numCourses) {
            return null_res;
        }
        
        return res;
    }
private:
    void dfs(int d, vector<unordered_set<int>>& graph, vector<bool>& visited, vector<int>& res){
        for (auto p : graph[d]) {
            if (!visited[p]) {
                visited[p] = true;
                dfs(p, graph, visited, res);
            }
        }
        res.push_back(d);
    }
};
