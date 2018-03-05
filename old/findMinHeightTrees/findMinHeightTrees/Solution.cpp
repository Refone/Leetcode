//
//  Solution.cpp
//  
//
//  Created by 信仰圣光吧 on 16/3/6.
//
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        map<int, int> degree;
        for (auto e:edges) {
            ++degree[e.first];
            ++degree[e.second];
        }
        if (n==1) {
            vector<int> res;
            res.push_back(0);
            return res;
        }
        if (n==2) {
            vector<int> res;
            res.push_back(edges[0].first);
            res.push_back(edges[0].second);
            sort(res.begin(),res.end());
            return res;
        }
        
        vector<int> del;
        for (auto d:degree) {
            if (d.second==1) {
                del.push_back(d.first);
            }
        }
        
        if (del.size()==(n-1)) {
            for (auto d:degree) {
                if (d.second!=1) {
                    vector<int> res;
                    res.push_back(d.first);
                    return res;
                }
            }
        }
        
        for (auto d:del) {
            auto iter = edges.begin();
            while (iter->first!=d && iter->second!=d) {
                ++iter;
            }
            edges.erase(iter);
        }
        
        return findMinHeightTrees(int(edges.size()+1), edges);
    }
};
//
//vector<int> vertices;
//vector<int> degree(n,0);
//vector<int> degree1Vertice;
//
//if (n==2) {
//    vertices.push_back(edges[0].first);
//    vertices.push_back(edges[0].second);
//    sort(vertices.begin(),vertices.end());
//    return vertices;
//}
//
//for (int i=0; i<n; ++i) {
//    ++degree[edges[i].first];
//    ++degree[edges[i].second];
//}
//
//for (int i=0; i<n; ++i) {
//    if (degree[i]>1) {
//        vertices.push_back(i);
//    } else {
//        degree1.push_back(i);
//    }
//}
//
//if (vertices.size()==1) {
//    return vertices;
//} else {
//    int m=0;
//    for (int i=0; i<n; i++) {
//        if (edges[i].first) {
//            <#statements#>
//        }
//    }
//    return
//}