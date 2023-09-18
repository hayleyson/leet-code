#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode * createNode(int x){
    ListNode * mynode = (ListNode *)malloc(sizeof(ListNode));
    mynode->val = x;
    mynode->next = NULL;
    return mynode;
}


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
    
    int mysize = getSizeLL(head);
    int midpoint = mysize / 2;
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

void printLL(ListNode * head){
    ListNode* curr = head;
    while(curr!=NULL){
        printf("%d->", curr->val);
        curr=curr->next;
    }
    printf("END\n");
}

int main(){

    /* case 1 */
    // ListNode* node1 = createNode(6);
    // ListNode* node2 = createNode(2);
    // ListNode* node3 = createNode(1);
    // ListNode* node4 = createNode(7);
    // ListNode* node5 = createNode(4);
    // ListNode* node6 = createNode(3);
    // ListNode* node7 = createNode(1);

    // node7->next = node6;
    // node6->next = node5;
    // node5->next = node4;
    // node4->next = node3;
    // node3->next = node2;
    // node2->next = node1;

    // printLL(node7);
    // ListNode* newHead = deleteMiddle(node7);
    // printLL(newHead);

    /* case 2 */
    // ListNode* node1 = createNode(4);
    // ListNode* node2 = createNode(3);
    // ListNode* node3 = createNode(2);
    // ListNode* node4 = createNode(1);

    // node4->next = node3;
    // node3->next = node2;
    // node2->next = node1;

    // printLL(node4);
    // ListNode * newHead = deleteMiddle(node4);
    // printLL(newHead);

    /* case 3 */
    // ListNode* node1 = createNode(1);
    // ListNode* node2 = createNode(2);

    // node2->next = node1;

    // printLL(node2);
    // ListNode * newHead = deleteMiddle(node2);
    // printLL(newHead);

    /* case 4 */
    ListNode* node1 = createNode(1);

    printLL(node1);
    ListNode * newHead = deleteMiddle(node1);
    printLL(newHead);


    return 0;

}
