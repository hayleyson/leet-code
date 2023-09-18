#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

ListNode* createNode(int x){
    ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

void printLL(ListNode * head){
    ListNode* curr = head;
    while(curr!=NULL){
        printf("%d->", curr->val);
        curr=curr->next;
    }
    printf("END\n");
}

ListNode* oddEvenList(ListNode* head){
    
    if (head == NULL||head->next==NULL||head->next->next==NULL){
        return head; // nothing to change.
    }

    ListNode *curr= head, * oddsHead=NULL, * oddsCurr=NULL, * evensHead=NULL, *evensCurr=NULL;
    int index = 1;

    while(curr!=NULL){
        if (index % 2 == 1 && oddsHead==NULL) {
            oddsHead=curr;
            oddsCurr=curr;
        } else if (index % 2 == 1 && oddsHead!=NULL){
            oddsCurr->next=curr;
            oddsCurr=curr;
        } else if (evensHead==NULL){
            evensHead=curr;
            evensCurr=curr;
        } else {
            evensCurr->next=curr;
            evensCurr=curr;
        }        
        curr=curr->next;
        index++;
    }
    oddsCurr->next=evensHead;
    evensCurr->next=NULL;
    return oddsHead;
}

int main(){

    /* case 1 */
    // ListNode* node1 = createNode(1);
    // ListNode* node2 = createNode(2);
    // ListNode* node3 = createNode(3);
    // ListNode* node4 = createNode(4);
    // ListNode* node5 = createNode(5);

    // node1->next = node2;
    // node2->next = node3;
    // node3->next = node4;
    // node4->next = node5;

    // printLL(node1);
    // ListNode* newHead = oddEvenList(node1);
    // printLL(newHead);

    /* case 2 */
    ListNode* node1 = createNode(2);
    ListNode* node2 = createNode(1);
    ListNode* node3 = createNode(3);
    ListNode* node4 = createNode(5);
    ListNode* node5 = createNode(6);
    ListNode* node6 = createNode(4);
    ListNode* node7 = createNode(7);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    printLL(node1);
    ListNode* newHead = oddEvenList(node1);
    printLL(newHead);


}