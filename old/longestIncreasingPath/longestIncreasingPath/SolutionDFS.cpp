//
//  SolutionDFS.cpp
//  
//
//  Created by 信仰圣光吧 on 16/2/24.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
class SolutionDFS {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max=1;
        
        l = int(matrix.size());
        if (l==0) {
            return 0;
        }
        
        r = int(matrix[0].size());
        
        for (int i=0; i<l; i++) {
            vector<bool> m;
            for (int j=0; j<r; j++) {
                m.push_back(false);
            }
            matrixF.push_back(m);
        }
        
        for (int i=0; i<l; i++) {
            vector<int> m;
            for (int j=0; j<r; j++) {
                m.push_back(1);
            }
            matrixV.push_back(m);
        }
        
        for (int i=0; i<l; i++) {
            for (int j=0; j<r; j++) {
                if (!matrixF[i][j]) {
                    int path = maxPath(i, j, matrix);
                    if (path>max) {
                        max = path;
                    }
                }
            }
        }
        
        return max;
    }
    
private:
    int l;
    int r;
    int max;
    vector<vector<bool>> matrixF;
    vector<vector<int>> matrixV;
    
    int maxPath(int i,int j,vector<vector<int>> matrix){
        int roundMax = 0;
        int path;
        if (matrixF[i][j]) {
            return matrixV[i][j];
        }
        if (i>0 && matrix[i-1][j]<matrix[i][j]) {
            path = maxPath(i-1, j, matrix);
            if (path>roundMax) {
                roundMax = path;
            }
        }
        
        if (j>0 && matrix[i][j-1]<matrix[i][j]) {
            path = maxPath(i, j-1, matrix);
            if (path>roundMax) {
                roundMax = path;
            }
        }
        if (i+1<l && matrix[i+1][j]<matrix[i][j]) {
            path = maxPath(i+1, j, matrix);
            if (path>roundMax) {
                roundMax = path;
            }
        }
        if (j+1<r && matrix[i][j+1]<matrix[i][j]) {
            path = maxPath(i, j+1, matrix);
            if (path>roundMax) {
                roundMax = path;
            }
        }
        matrixF[i][j] = true;
        if (roundMax) {
            matrixV[i][j] = roundMax+1;
            return roundMax+1;
        } else {
            matrixV[i][j] = 1;
            return 1;
        }
    }
};