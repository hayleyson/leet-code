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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode* curNode = head;
        ListNode* nextNode, *prevNode;
        ListNode* evenStart=head-> next;
        int i = 0;
        while(curNode->next != nullptr){
            nextNode=curNode -> next;
            curNode->next = nextNode-> next;
            prevNode = curNode;
            curNode = nextNode;
            i++;
        }
        if (i%2==0) curNode -> next = evenStart;
        else prevNode->next = evenStart;
        return head;
        
    }
};
