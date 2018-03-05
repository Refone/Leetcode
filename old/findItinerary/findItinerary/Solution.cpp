//
//  Solution.cpp
//  
//
//  Created by 信仰圣光吧 on 16/2/21.
//
//

#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <iostream>

#define MAX_CITY_NUM 50

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets){
        // Each node (airport) contains a set of outgoing edges (destination).
        map<string, multiset<string>> graph;
        // We are always appending the deepest node to the itinerary,
        // so will need to reverse the itinerary in the end.
        vector<string> itinerary;
        if (tickets.size() == 0){
            return itinerary;
        }
        // Construct the node and assign outgoing edges
        for (pair<string, string> eachTicket : tickets){
            graph[eachTicket.first].insert(eachTicket.second);
        }
        stack<string> dfs;
        dfs.push("JFK");
        while (!dfs.empty()){
            string topAirport = dfs.top();
            if (graph[topAirport].empty()){
                itinerary.push_back(topAirport);
                dfs.pop();
            }
            else {
                dfs.push(*(graph[topAirport].begin()));
                graph[topAirport].erase(graph[topAirport].begin());
            }
        }
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};