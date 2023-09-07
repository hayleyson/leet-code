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
        ListNode* tmpNode, *prevNode;
        ListNode* evenStart=head-> next;
        int i = 0;
        // connecting node to the next next node
        while(curNode->next != nullptr){ // loop over until curNode is not the last elem of linked list
            tmpNode=curNode -> next;
            curNode->next = tmpNode-> next; // connect current node to a node 2 steps ahead
            prevNode = curNode; // save current curNode for later
            curNode = tmpNode; // move curNode 1 step head
            i++;
        }
        // connecting end of odd group to start of even group
        if (i%2==0) curNode -> next = evenStart;  // if the linked list length is odd
        else prevNode->next = evenStart; // if the linked list length is even
        return head;
        
    }
};
