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
#include <iostream>

#define MAX_CITY_NUM 50

using namespace std;

class Status{
public:
    int start;
    int cityNum;
    int cityPath[MAX_CITY_NUM][MAX_CITY_NUM] = {0};
    int cityBeen[MAX_CITY_NUM] = {0};
    
    Status(int s,int cn,int cp[MAX_CITY_NUM][MAX_CITY_NUM]):start(s),cityNum(cn){
        for (int i=0; i<cn; i++) {
            for (int j=0; j<cn; j++) {
                cityPath[i][j] = cp[i][j];
            }
        }
        cityBeen[s] = 1;
    }
};

class Solution {
public:
    void findItinerary(vector<pair<string, string>> tickets){
        list<string> all_cities;
        vector<pair<string, string>>::const_iterator it = tickets.begin();
        while (it != tickets.end()) {
            cout<<it->first<<" "<<it->second<<endl;
            all_cities.push_back(it->first);
            all_cities.push_back(it->second);
            ++it;
        }
        all_cities.sort();
        all_cities.unique();
        
        int i,j;
//        int cityPath[all_cities.size()][all_cities.size()];
        int cityPath[MAX_CITY_NUM][MAX_CITY_NUM] = {0};
        
        it = tickets.begin();
        while (it != tickets.end()) {
            i = findIndex(it->first, all_cities);
            j = findIndex(it->second, all_cities);
//            cout<<it->first<<"->"<<it->second<<":"<<i<<","<<j<<endl;
            cityPath[i][j] = 1;
            ++it;
        }
        
        int route[MAX_CITY_NUM];
        int startCity = findIndex("JFK", all_cities);
        int cityNum = int(all_cities.size());
        Status startState(startCity,cityNum,cityPath);
        findPath(startState);
    }
private:
    //find the index of @city in @cityList
    int findIndex(const string city, const list<string> cityList){
        list<string>::const_iterator it = cityList.begin();
        int idx = 0;
        while (city != *it && it != cityList.end()) {
            ++idx;
            ++it;
        }
        if (it == cityList.end()) {
            return -1;
        } else {
            return idx;
        }
    }
    
    void findPath(Status s){
        
    }
};