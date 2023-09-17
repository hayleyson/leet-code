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
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* curNode = head;
    //     ListNode* prevNode = NULL;
    //     ListNode* tmpNode = NULL;

    //     while(curNode != NULL){
    //         tmpNode = curNode->next;
    //         curNode->next = prevNode;
    //         prevNode = curNode;
    //         curNode = tmpNode;
    //     }
    //     return prevNode;
    // }

    ListNode* reverseListHelp(ListNode* prevNode, ListNode* curNode) {
        if (!curNode->next){
            curNode->next = prevNode;
            return curNode;
        } else {
            ListNode* nextNode = curNode-> next;
            curNode->next = prevNode;
            ListNode* lastNode = reverseListHelp(curNode, nextNode);
            return lastNode;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* lastNode = reverseListHelp(NULL, head);
        return lastNode;
    
    }



};

 
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
