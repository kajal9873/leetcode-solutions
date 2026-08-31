/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstidx = -1, lastidx = -1, prevcritidx = -1;
        int mindist = INT_MAX;
        int idx = -1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr->next){
            ListNode* next = curr->next;
            if((curr->val>prev->val && curr->val>next->val) || (curr->val<prev->val && curr->val<next->val)){
                int curridx = idx+1;
                if(firstidx==-1){
                    firstidx = curridx;
                }else{
                    mindist = min(mindist, curridx-prevcritidx);
                }
                prevcritidx = curridx;
                lastidx = curridx;
            }
            prev = curr;
            curr = next;
            idx++;
        }
        if(firstidx==-1 || firstidx==lastidx){
            return {-1,-1};
        }
        return {mindist,lastidx-firstidx};
    }
};