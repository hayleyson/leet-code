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

    // int getSize(ListNode* head){ // why pointer?
    //     int size = 1;
    //     ListNode* curNode = head;
    //     while(curNode->next != nullptr){
    //         curNode = curNode->next;
    //         size++;
    //     }
    //     return size;
    // }

    // ListNode* deleteMiddle(ListNode* head) {
    //     int size = getSize(head);
    //     if (size == 1){
    //         return nullptr;
    //     } else {
    //         int delId = size/2;
    //         ListNode* curNode = head;
    //         int curId = 0;
    //         while (curId < (delId-1)){
    //             curNode = curNode->next;
    //             curId++;
    //         }
    //         ListNode* delNode = curNode->next;
    //         curNode->next = delNode->next;
    //         delete delNode;
    //         return head;
    //     }
    // }
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL; // If next of head is NULL then we are deleting the first and the only node in LinkedList.
        ListNode* slow=head;    //slow ptr will be at head
        ListNode* fast=head->next;   //fast ptr will be at next of head
        ListNode* n=NULL;
        while(fast && fast->next)
        {
            n=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        // after the loop there will be two cases as mentioned
        if(fast==NULL) //it means the list is of odd size and slow pointer is at the node to be deleted.
        {
            ListNode* m=slow->next;
            n->next=m;
            delete slow;
            return head;
        }
        if(fast->next==NULL) //this means the list is of even size and slow pointer is exactly at a node before the node to be deleted
        {
            ListNode* m=slow->next;
            slow->next=m->next;
            delete m;
            return head;
        }
        return head;   
    }
};


