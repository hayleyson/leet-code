from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:

    def getSize(self, head) -> int:
        size = 1 # initialize size as 1 (head)
        curNode = head # initialize curNode variable as head
        while curNode.next != None: # if there's next node
            curNode = curNode.next # update curNode to the next node
            size += 1 # and increase size by 1
        return size

    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        size = self.getSize(head)
        if size == 1:
            return None # return sentinel
        else:
            delId = int(size/2) # int() does the rounding-down
            curNode = head # initialize curNode as head
            curId = 0 # initialize curIndex as 0
            while curId < (delId-1): # if (while) curId hasn't reached the one index previous to delId
                prevNode = curNode
                curNode = curNode.next # jump to the next node
                curId += 1 # increase curId
            # now curId == delId-1 and curNode is the (curId-1)'th node from the head
            # how to remove a node from linked list?
            # - set the previous node's next to current node's next 
            # - unset current node's next
            delNode = curNode.next
            curNode.next = delNode.next
            delNode.next = None
            return head
            
