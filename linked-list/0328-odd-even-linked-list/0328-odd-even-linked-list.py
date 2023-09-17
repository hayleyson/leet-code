from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        else:
            curNode = head
            tmpNode = None
            prevNode = None
            i = 0
            evenStart = None
            while curNode.next != None:
                if i + 1 == 1:
                    evenStart = curNode.next
                tmpNode = curNode.next
                curNode.next = tmpNode.next
                prevNode = curNode
                curNode = tmpNode
                i += 1
            if i % 2 == 0:
                curNode.next = evenStart
            else:
                prevNode.next = evenStart
            return head