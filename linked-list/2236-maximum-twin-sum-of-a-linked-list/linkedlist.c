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

int getSizeLL(struct ListNode * head){
    int size = 0;
    ListNode * curr = head;
    while (curr != NULL){
        size++;
        curr = curr->next;
    }
    return size;
}
