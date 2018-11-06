/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//recursive 
class Solution {
public:
    int remove(ListNode* sup, ListNode* cur, int n){
        if(cur == NULL){
            return 0;
        }
        int pos = remove(cur, cur->next, n) + 1;
        if(pos == n ){
            sup->next = cur->next;                
        }
        return pos;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = remove(head, head->next, n);
        if((k+1) == n){
            return head->next;
        }
        return head;
    }
};

//stack 
class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> s;
        ListNode* sup = new ListNode(-1);
        sup->next = head;
        ListNode* cur = head, *pre=NULL;
        s.push(sup);
        while(cur!=NULL){
            s.push(cur);
            cur = cur->next;
        }
        int k=0;
        cur = NULL;
        while(!s.empty() && k<=n){
            cur = pre;
            pre = s.top();
            s.pop();
            k++;
        }
        if(k==n+1){
            if(cur != NULL){
                pre->next = cur->next;                
            }
        }
        return sup->next;
    }

};

// two pointer
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast,  *slow;
        int ahead = 0;
        fast = head;
        slow = head;
        while(fast!=NULL){
            fast = fast->next;
            ahead++;
            if(ahead > n+1){ // slow and faster show diff n+1 step
                slow = slow -> next;
            }
        }
        if(ahead >= n+1 && slow->next != NULL){
            slow->next = (slow->next)->next;
        }
        if(ahead <= n){
            return head->next;
        }
        return head;
    }
};