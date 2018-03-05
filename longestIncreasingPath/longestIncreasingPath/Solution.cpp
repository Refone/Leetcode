//
//  Solution.cpp
//  
//
//  Created by 信仰圣光吧 on 16/2/24.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max=1;
        bool flag = true;
        
        int l = int(matrix.size());
        if (l==0) {
            return 0;
        }
        
        int r = int(matrix[0].size());
        
        vector<vector<int>> matrixV;
        for (int i=0; i<l; i++) {
            vector<int> m;
            for (int j=0; j<r; j++) {
                m.push_back(1);
            }
            matrixV.push_back(m);
        }
        
        while (flag) {
            flag = false;
            for (int i=0; i<l; i++) {
                for (int j=0; j<r; j++) {
                    int roundMax = 0;
                    if (i>0 && matrix[i-1][j]<matrix[i][j]) {
                        if (matrixV[i-1][j]>roundMax) {
                            roundMax = matrixV[i-1][j];
                        }
                    }
                    if (j>0 && matrix[i][j-1]<matrix[i][j]) {
                        if (matrixV[i][j-1]>roundMax) {
                            roundMax = matrixV[i][j-1];
                        }
                    }
                    if (i+1<l && matrix[i+1][j]<matrix[i][j]) {
                        if (matrixV[i+1][j]>roundMax) {
                            roundMax = matrixV[i+1][j];
                        }
                    }
                    if (j+1<r && matrix[i][j+1]<matrix[i][j]) {
                        if (matrixV[i][j+1]>roundMax) {
                            roundMax = matrixV[i][j+1];
                        }
                    }
                    if (roundMax+1>matrixV[i][j]) {
                        flag = true;
                        matrixV[i][j] = roundMax+1;
                        if (matrixV[i][j]>max) {
                            max = matrixV[i][j];
                        }
                    }
                }
            }
        }
        return max;
    }
};