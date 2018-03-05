//
//  Solution.cpp
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
        sort(coins.begin(),coins.end());
        outfile.open("/Users/y/Public/programming/Leetcode/coinChange/output.txt");
        return coinAmount(coins, amount);
    }
private:
    ofstream outfile;
    int coinAmount(vector<int> coins, int amount){
        //<coins> has already been sorted
        int maxIndex = int(coins.size()-1);
        if (maxIndex==0) {
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
        }
        if (maxIndex==-1) {
            return -1;
        }
        if (maxIndex==1) {
            sort(coins.begin(),coins.end());
            return doubleCoin(coins[0],coins[1], amount);
        }
        auto maxPtr = coins.begin() + maxIndex;
        int maxCoin = *maxPtr;
        int maxCoinNum = amount/maxCoin;
        int partRet = -1;
        int minPartRet = INT_MAX;
        int finalMaxCoinCost=0;
        bool flag = false;
        int ret;
        
        if (amount%maxCoin==0) {
            outfile<<"[";
            vector<int>::const_iterator it = coins.begin();
            while (it != coins.end()) {
                outfile<<*it<<" ";
                ++it;
            }
            outfile<<"]("<<amount<<"): "<<ret<<endl;
            return maxCoinNum;
        }
        
        coins.erase(maxPtr);
        
        partRet = coinAmount(coins, amount - maxCoin*maxCoinNum);
        if (partRet!=-1 && partRet<minPartRet) {
            flag = true;
            minPartRet = partRet;
            finalMaxCoinCost = maxCoinNum;
        }
        
        while (maxCoinNum>0) {
            --maxCoinNum;
            partRet = coinAmount(coins, amount - maxCoin*maxCoinNum);
            if (partRet!=-1 && partRet<minPartRet) {
                flag = true;
                minPartRet = partRet;
                finalMaxCoinCost = maxCoinNum;
            }
        }
        
        if (flag) {
            ret = finalMaxCoinCost + minPartRet;
        } else{
            ret = -1;
        }
        
        //printf the result
        outfile<<"[";
        vector<int>::const_iterator it = coins.begin();
        while (it != coins.end()) {
            outfile<<*it<<" ";
            ++it;
        }
        outfile<<maxCoin<<"]("<<amount<<"): "<<ret<<endl;
        
        return ret;
    }
    
    int doubleCoin(int smallCoin, int bigCoin, int amount){
        if (amount%bigCoin==0) {
            return amount/bigCoin;
        }
        
        int bigCoinCost = amount/bigCoin;
        int rest;
        while (bigCoinCost>=0) {
            rest = amount-bigCoin*bigCoinCost;
            if (rest%smallCoin==0) {
                return bigCoinCost + rest/smallCoin;
            }
            --bigCoinCost;
        }

        return -1;
    }
};