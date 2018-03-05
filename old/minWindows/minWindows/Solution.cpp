//
//  Solution.cpp
//  
//
//  Created by 信仰圣光吧 on 16/3/7.
//
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        slen = int(s.length());
        if (!slen) {
            return "";
        }
        for (int i=0; i<slen; ++i) {
            int offset = int(s[i] - 'A');
            unsigned long pos = 1;
            pos <<= offset;
            flags.push_back(pos);
        }
        
        tlen = int(t.length());
        set<char> tSet;
        for (int i=0; i<tlen; ++i) {
            int offset = int(t[i] - 'A');
            unsigned long pos = 1;
            pos = pos<<offset;
            shadom |= pos;
            tSet.insert(t[i]);
        }
        shadom = ~shadom;
        minj_i = int(tSet.size()-1);
        if (!minj_i) {
            for (int i=0; i<slen; ++i) {
                if (s[i]==t[0]) {
                    string res = "";
                    res.push_back(t[0]);
                    return res;
                }
            }
            return "";
        }
        
        
        int i = 0;
        int j = 0;
        int minlen = INT_MAX;
        int min_i = 0;
        int min_j = 0;
        bool done;
        
        while (i<slen && j<slen) {
            if (arbitrate(i, j)) {
                done = true;
                if ((j-i+1)<minlen) {
                    minlen = j - i +1;
                    min_i = i;
                    min_j = j;
                }
            } else {
                done = false;
            }
            
            if (done) {
                ++i;
            } else {
                ++j;
            }
        }
        
        string res="";
        if (i==j) {
            return res;
        }
        for (int k=min_i; k<=min_j; ++k) {
            res.push_back(s[k]);
        }
        return res;
    }
private:
    int tlen;
    int slen;
    unsigned long shadom;
    vector<unsigned long> flags;
    int minj_i;
    
    bool arbitrate(int i, int j)
    {
        
        unsigned long res = 0;
        for (int k=i; k<=j; ++k) {
            res |= flags[k];
        }
        
        res |= shadom;
        res = ~res;
        
        return !res;
    }
};