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

    int getSize(ListNode* head){ // why pointer?
        int size = 1;
        ListNode* curNode = head;
        while(curNode->next != nullptr){
            curNode = curNode->next;
            size++;
        }
        return size;
    }

    ListNode* deleteMiddle(ListNode* head) {
        int size = getSize(head);
        if (size == 1){
            return nullptr;
        } else {
            int delId = size/2;
            ListNode* curNode = head;
            int curId = 0;
            while (curId < (delId-1)){
                curNode = curNode->next;
                curId++;
            }
            ListNode* delNode = curNode->next;
            curNode->next = delNode->next;
            delete delNode;
            return head;
        }
    }
};


