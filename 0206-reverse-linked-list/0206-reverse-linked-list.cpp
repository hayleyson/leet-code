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
    ListNode* reverseList(ListNode* head) {
        ListNode* curNode = head;
        ListNode* prevNode = NULL;
        ListNode* tmpNode = NULL;

        while(curNode != NULL){
            tmpNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = tmpNode;
        }
        return prevNode;
    }
};

    // # -- iterative version -- # 
    // # -- 37ms, 17.7mb -- #
    // # def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    // #     curNode = head
    // #     prevNode = None
    // #     tmpNode = None
    // #     while curNode != None:
    // #         tmpNode = curNode.next
    // #         curNode.next = prevNode
    // #         prevNode = curNode
    // #         curNode = tmpNode
        
    // #     return prevNode
        



    
    // # -- recursion version -- # 
    // # -- 47ms, 22.9mb -- #
    // def reverseListHelp(self, prevNode, curNode) -> None:
    //     if curNode.next is None:
    //         curNode.next = prevNode
    //         return curNode
    //     else:
    //         nextNode = curNode.next
    //         curNode.next = prevNode
    //         lastNode = self.reverseListHelp(curNode, nextNode)
    //         return lastNode

    // def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

    //     if head is None:
    //         return head
    //     lastNode = self.reverseListHelp(None, head)
    //     return lastNode
