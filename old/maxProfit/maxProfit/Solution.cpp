//
//  Solution.cpp
//  
//
//  Created by 信仰圣光吧 on 16/2/26.
//
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = int(prices.size());
        if (n==0) {
            return 0;
        }
        vector<int> line(n,0);
        vector<vector<int>> dp(n,line);
        
        for (int i=0; i<n-1; i++)
            dp[i][i+1] = prices[i+1] - prices[i];
        
        for (int i=0; i<n-2; i++) {
            int p1 = prices[i+2] - prices[i];
            int p2 = prices[i+1] - prices[i];
            int p3 = prices[i+2] - prices[i+1];
            
            dp[i][i+2] = max(max(max(p1,p2),p3),0);
        }
        
        for (int step=3; step<n; step++) {
            for (int start=0; start<n-step; start++) {
                int maxprofit = 0;
                for (int j=0; j<=step; j++) {
                    int profit = 0;
                    if (j>0 && j<step) {
                        profit = dp[start][start+j-1] + dp[start+j+1][start+step];
                    }
                    if (profit>maxprofit) {
                        maxprofit = profit;
                    }
                }
                if ((prices[start+step]-prices[start])>maxprofit) {
                    maxprofit = prices[start+step]-prices[start];
                }
                dp[start][start+step] = maxprofit;
            }
        }
        
        return dp[0][n-1];
    }
};