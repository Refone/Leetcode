//
//  Solution.cpp
//  
//
//  Created by 信仰圣光吧 on 16/3/4.
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> word_size;
        vector<unsigned long> word_partten;
        int words_num = int(words.size());
        
        vector<string>::const_iterator iter = words.begin();
        while (iter != words.end()) {
            string word = *iter;
            int len = int(word.length());
            word_size.push_back(len);
            unsigned long originPartten = 0x00000000;
            
            for (int i=0; i<len; i++) {
                unsigned long partten = 0x00000001;
                int offset = int(word[i] - 'a');
                partten = partten<<offset;
                originPartten |= partten;
            }
            word_partten.push_back(originPartten);
            ++iter;
        }
        
        int max = 0;
        for (int i=0; i<words_num; i++) {
            for (int j=i+1; j<words_num; j++) {
                if ((word_partten[i]&word_partten[j])==0) {
                    int k = word_size[i]*word_size[j];
                    if (k>max) {
                        max = k;
                    }
                }
            }
        }
        
        return max;
    }
};