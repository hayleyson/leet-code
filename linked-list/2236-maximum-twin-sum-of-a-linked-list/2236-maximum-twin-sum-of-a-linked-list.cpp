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
    int pairSum(ListNode* head) {
        int size = 1;
        ListNode* curNode = head;
        while(curNode->next){
            size++;
            curNode=curNode->next;
        }

        int half = size/2;
        int idx = 0;
        int sumList[half];
        sumList[0]=head->val;
        int maxSum=0;
        curNode = head;
        while(curNode->next){
            idx++;
            curNode = curNode->next;
            if (idx<half) sumList[idx]=curNode->val;
            else {
                maxSum=max(sumList[size-1-idx] + curNode->val, maxSum);
            }
        }
        return maxSum;
    }
};

