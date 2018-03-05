//
//  Solution2.cpp
//  
//
//  Created by 信仰圣光吧 on 16/2/26.
//
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Solution{
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = int(coins.size());
        if (n==0) {
            if (amount==0) {
                return 0;
            } else {
                return -1;
            }
        }
        if (n==1) {
            if (amount%coins[0]==0) {
                return amount/coins[0];
            }
        }
        
        vector<int> mapLine(amount+1, -1);
        mapLine[0] = 0;
        for (int i=0; i<n; i++) {
            map.push_back(mapLine);
        }
        
        sort(coins.begin(), coins.end());
        
        for (int i=0; i<n; i++) {
            for (int j=1; j<=amount; j++) {
                fillMap(i, j, coins);
            }
        }
        
        return map[n-1][amount];
    }
private:
    vector<vector<int>> map;
    void fillMap(int i, int amount, vector<int>& coins){
        if (i==0) {
            if (amount%coins[i]==0) {
                map[i][amount] = amount/coins[i];
                return;
            } else {
                map[i][amount] = -1;
                return;
            }
        }
        
        if (i==1) {
            int maxCoin = coins[i];
            int maxCoinCost = amount/maxCoin;
            int rest;
            if (amount%maxCoin==0) {
                map[i][amount] = maxCoinCost;
                return;
            }
            
            while (maxCoinCost>=0) {
                rest = amount - maxCoinCost*maxCoin;
                if (map[i-1][rest]!=-1) {
                    map[i][amount] = map[i-1][rest] + maxCoinCost;
                    return;
                }
                --maxCoinCost;
            }
            
            if (maxCoinCost<0) {
                map[i][amount] = -1;
                return;
            }
        }
        
        if (i>1) {
            int maxCoin = coins[i];
            int maxCoinCost = amount/maxCoin;
            int minCost = INT_MAX;
            bool flag = false;
            int rest;
            int restCost;
            
            if (amount%maxCoin==0) {
                map[i][amount] = maxCoinCost;
                return;
            }
            
            while (maxCoinCost>=0) {
                rest = amount - maxCoinCost*maxCoin;
                restCost = map[i-1][rest];
                
                if (restCost!=-1 && (restCost+maxCoinCost)<minCost) {
                    flag = true;
                    minCost = restCost+maxCoinCost;
                }
                
                --maxCoinCost;
            }
            
            if (flag) {
                map[i][amount] = minCost;
                return;
            } else {
                map[i][amount] = -1;
                return;
            }
        }
    }
};
