/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 typedef struct ListNode ListNode;

int getSizeLL(struct ListNode * head){
    int size = 0;
    ListNode * curr = head;
    while (curr != NULL){
        size++;
        curr = curr->next;
    }
    return size;
}
struct ListNode* deleteMiddle(struct ListNode* head){
    
    int midpoint = getSizeLL(head) / 2;
    if (midpoint==0){
        return NULL;
    }
    
    int index=0;
    ListNode* curr=head;
    ListNode* prev=NULL;
        
    while (curr != NULL){
        // printf("val: %d, index: %d\n", curr->val, index);
        if (index == midpoint){
            // printf("Deleting this node. (index: %d, val: %d)\n", index, curr->val);
            prev->next = curr->next;
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
        index++;
    }
    return head;
    
}
