# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def reverseListHelp(self, prevNode, curNode) -> None:
        if curNode.next is None:
            curNode.next = prevNode
            return curNode
        else:
            nextNode = curNode.next
            curNode.next = prevNode
            lastNode = self.reverseListHelp(curNode, nextNode)
            return lastNode

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # curNode = head
        # prevNode = None
        # tmpNode = None
        # while curNode != None:
        #     tmpNode = curNode.next
        #     curNode.next = prevNode
        #     prevNode = curNode
        #     curNode = tmpNode
        
        # return prevNode
        if head is None:
            return head
        lastNode = self.reverseListHelp(None, head)
        return lastNode

        