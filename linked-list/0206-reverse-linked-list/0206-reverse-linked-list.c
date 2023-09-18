#include <stdlib.h>
#include "linkedlist.c"
/* iterative version */
// ListNode* reverseList(ListNode* head){
//  
//     if (head==NULL || head->next==NULL){
//         return head;
//     }
    
//     ListNode * curr=head;
//     ListNode * prev=NULL;
//     ListNode * tmp=NULL;

//     while(curr!=NULL){
//         tmp = curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=tmp;
//     }
//     return prev;
// }

ListNode* reverseListHelp(ListNode* curr, ListNode* prev){
    if (curr->next==NULL){
        curr->next=prev;
        return curr;
    } else {
        ListNode* newHead=reverseListHelp(curr->next, curr);
        curr->next=prev;
        return newHead;
    }
}

ListNode* reverseList(ListNode* head){

    if(head==NULL||head->next==NULL) return head;
    return reverseListHelp(head, NULL);
}


int main(){

    // printf("Type one of 1, 2, 3 to choose a test case: ");
    // int caseNum;
    // scanf("%d", &caseNum);

    ListNode* nodeList[10];
    ListNode* newHead = NULL;
    for (int caseNum = 1; caseNum <=3; caseNum++){
        printf("*-*- Doing test case %d... -*-*\n", caseNum);
        switch(caseNum){
        case 1:
            nodeList[0] = createNode(1);
            nodeList[1] = createNode(2);
            nodeList[2] = createNode(3);
            nodeList[3] = createNode(4);
            nodeList[4] = createNode(5);

            nodeList[0]->next = nodeList[1];
            nodeList[1]->next = nodeList[2];
            nodeList[2]->next = nodeList[3];
            nodeList[3]->next = nodeList[4];

            printLL(nodeList[0]);
            newHead = reverseList(nodeList[0]);
            printLL(newHead);
            break;
        case 2:
            nodeList[0] = createNode(1);
            nodeList[1] = createNode(2);

            nodeList[0]->next = nodeList[1];

            printLL(nodeList[0]);
            newHead = reverseList(nodeList[0]);
            printLL(newHead);
            break;
        case 3:
            printLL(NULL);
            newHead = reverseList(NULL);
            printLL(newHead);
            break;      
    }
    }
    
}