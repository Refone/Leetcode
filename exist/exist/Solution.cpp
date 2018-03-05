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
    bool exist(vector<vector<char>>& board, string word) {
        int n = int(word.length());
        if (n==0) {
            return true;
        }
        
        _x = int(board.size());
        if (_x==0) {
            return false;
        }
        
        _y = int(board[0].size());
        
        vector<vector<bool>> been;
        for (int i=0; i<_x; i++) {
            vector<bool> b;
            for (int j=0; j<_y; j++) {
                b.push_back(false);
            }
            been.push_back(b);
        }
        
        if (n==1) {
            for (int i=0; i<_x; i++) {
                for (int j=0; j<_y; j++) {
                    if (board[i][j]==word[0]) {
                        return true;
                    }
                }
            }
        } else {
            char nc = word[0];
            word.erase(0,1);
            for (int i=0; i<_x; i++) {
                for (int j=0; j<_y; j++) {
                    if (board[i][j]==nc) {
                        been[i][j] = true;
                        if (search(board, been, word, i, j)) {
                            return true;
                        }
                        been[i][j] = false;
                    }
                }
            }
        }
        
        return false;
    }
private:
    int _x,_y;
    bool search(vector<vector<char>>& board,vector<vector<bool>>& been, string word, int x, int y){
        char nextchar = word[0];
        word.erase(0,1);
        
        if (x+1<_x) {
            if ((!been[x+1][y]) && (board[x+1][y]==nextchar)) {
                if (word.length()==0) {
                    return true;
                } else {
                    been[x+1][y] = true;
                    if (search(board, been, word, x+1, y)) {return true;}
                    been[x+1][y] = false;
                }
            }
        }
        
        if (x-1>=0) {
            if ((!been[x-1][y]) && (board[x-1][y]==nextchar)) {
                if (word.length()==0) {
                    return true;
                } else {
                    been[x-1][y] = true;
                    if (search(board, been, word, x-1, y)) {return true;}
                    been[x-1][y] = false;
                }
            }
        }
        
        if (y+1<_y) {
            if ((!been[x][y+1]) && (board[x][y+1]==nextchar)) {
                if (word.length()==0) {
                    return true;
                } else {
                    been[x][y+1] = true;
                    if (search(board, been, word, x, y+1)) {return true;}
                    been[x][y+1] = false;
                }
            }
        }
        
        if (y-1>=0) {
            if ((!been[x][y-1]) && (board[x][y-1]==nextchar)) {
                if (word.length()==0) {
                    return true;
                } else {
                    been[x][y-1] = true;
                    if (search(board, been, word, x, y-1)) {return true;}
                    been[x][y-1] = false;
                }
            }
        }
        
        return false;
    }
};
