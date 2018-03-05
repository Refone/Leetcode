/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Runtime: 60 ms

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* p1=l1;
        ListNode* p2=l2;
        ListNode* p = head;
        bool end = false;
        int n1,n2,n;
        
        while (!end) {
            end = true;
            
            if (p1) {
                end = false;
                n1 = p1->val;
                p1 = p1->next;
            } else {
                n1 = 0;
            }
            
            if (p2) {
                end = false;
                n2 = p2->val;
                p2 = p2->next;
            } else {
                n2 = 0;
            }
            
            n = n1 + n2 + p->val;
            if (n>=10) {
                p->val = n - 10;
                ListNode* pp = new ListNode(1);
                p->next = pp;
                p = p->next;
            } else {
                p->val = n;
                if (p1||p2) {
                    ListNode* pp = new ListNode(0);
                    p->next = pp;
                    p = p->next;
                }
            }
        } //end while
        
        return head;
        
    }
};
