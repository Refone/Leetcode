//
//  Solution.cpp
//  
//
//  Created by 信仰圣光吧 on 16/2/22.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class NodeStack {
public:
    NodeStack():state(false){}
    
    void push(string node){
        if (node != "#") {
            node_stack.push(node);
            state_stack.push(0);
        } else {
            if (node_stack.empty()) {
                state = true;
            } else if (state_stack.top()==0) {
                node_stack.push("#");
                state_stack.push(1);
            } else if (state_stack.top()==1) {
                node_stack.pop();
                node_stack.pop();
                state_stack.pop();
                state_stack.pop();
                push("#");
            }
        }
    }
    
    bool isCompleted(){return state;}
private:
    stack<string> node_stack;
    stack<int> state_stack;
    bool state;
};

class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder+=",";
        vector<string> nodes;
        
        int i = 0;
        int pos;
        while (i<preorder.size()) {
            pos = int(preorder.find(",",i));
            string node = preorder.substr(i,pos-i);
            nodes.push_back(node);
            i = pos+1;
        }
        
        vector<string>::const_iterator it = nodes.begin();
        NodeStack s;
        while (it != nodes.end() && !s.isCompleted()) {
            s.push(*it);
            ++it;
        }
        
        if (it == nodes.end() && s.isCompleted()) {
            return true;
        } else {
            return false;
        }
    }
};
