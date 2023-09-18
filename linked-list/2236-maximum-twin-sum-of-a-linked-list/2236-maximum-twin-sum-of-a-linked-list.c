#include <stdlib.h>
#include "linkedlist.c"

int pairSum(ListNode* head){
    if (head->next->next==NULL){ // if length is 2
        return head->val + head->next->val;
    }

    int size = getSizeLL(head);
    int sumArr[size/2];

    ListNode* curr=head;
    int index=0, maxSum=0, tmpSum=0;
    while(curr!=NULL){
        if (index < size/2){
            sumArr[index]=curr->val;
        } else {
            tmpSum= sumArr[size - index - 1]+curr->val;
            maxSum= tmpSum > maxSum ? tmpSum : maxSum;
        }
        curr=curr->next;
        index++;
    }
    return maxSum;
}

int main(){


    ListNode* nodeList[10];
    int maxPairSum = 0;
    for (int caseNum = 1; caseNum <=3; caseNum++){
        printf("== test case %d ==\n", caseNum);
        switch(caseNum){
        case 1:
            nodeList[0] = createNode(5);
            nodeList[1] = createNode(4);
            nodeList[2] = createNode(2);
            nodeList[3] = createNode(1);

            nodeList[0]->next = nodeList[1];
            nodeList[1]->next = nodeList[2];
            nodeList[2]->next = nodeList[3];
            nodeList[3]->next = NULL;

            printLL(nodeList[0]);
            maxPairSum = pairSum(nodeList[0]);
            printf("Max pair sum: %d\n", maxPairSum);
            break;
        case 2:
            nodeList[0] = createNode(4);
            nodeList[1] = createNode(2);
            nodeList[2] = createNode(2);
            nodeList[3] = createNode(3);

            nodeList[0]->next = nodeList[1];
            nodeList[1]->next = nodeList[2];
            nodeList[2]->next = nodeList[3];
            nodeList[3]->next = NULL;

            printLL(nodeList[0]);
            maxPairSum = pairSum(nodeList[0]);
            printf("Max pair sum: %d\n", maxPairSum);
            break;
        case 3:
            nodeList[0] = createNode(1);
            nodeList[1] = createNode(100000);

            nodeList[0]->next = nodeList[1];
            nodeList[1]->next = NULL;

            printLL(nodeList[0]);
            maxPairSum = pairSum(nodeList[0]);
            printf("Max pair sum: %d\n", maxPairSum);
            break;  
    }
    }

}