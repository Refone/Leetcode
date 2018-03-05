//
//  Solution.cpp
//  
//
//  Created by 信仰圣光吧 on 16/3/3.
//
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = int(s.length());
        if (len != t.length()) {
            return false;
        }
        
        map<char, char> m1;
        map<char, char> m2;
        int i=0;
        while (i<len) {
            char c = m1[s[i]];
            if (c=='\0') {
                m1[s[i]] = t[i];
            } else {
                if (c!=t[i]) {
                    return false;
                }
            }
            
            c = m2[t[i]];
            if (c=='\0') {
                m2[t[i]] = s[i];
            } else {
                if (c!=s[i]) {
                    return false;
                }
            }
            ++i;
        }
        
        return true;
    }
};