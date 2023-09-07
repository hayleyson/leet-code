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
        // if (head == nullptr || head -> next == nullptr || head->next->next==nullptr) return head;
        
        // ListNode* curNode = head;
        // ListNode* tmpNode, *prevNode;
        // ListNode* evenStart=head-> next;
        // int i = 0;
        // // connecting node to the next next node
        // while(curNode->next != nullptr){ // loop ends when curNode is the last elem of linked list
        //     tmpNode=curNode -> next;
        //     curNode->next = tmpNode-> next; // connect current node to a node 2 steps ahead
        //     prevNode = curNode; // save current curNode for later
        //     curNode = tmpNode; // move curNode 1 step ahead
        //     i++;
        // }
        // // connecting end of odd group to start of even group
        // if (i%2==0) curNode -> next = evenStart;  // if the linked list length is odd
        // else prevNode->next = evenStart; // if the linked list length is even
        // return head;


        /* c.f. solution by _LeetCoder25_ */
        if(!head || !head->next || !head->next->next) return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even_start = head->next;
        
        while(odd->next && even->next){
            odd->next = even->next; //Connect all odds
            even->next = odd->next->next;  //Connect all evens
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_start;   //Place the first even node after the last odd node.
        return head; 
        
    }
};
