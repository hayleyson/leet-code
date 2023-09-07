# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        size = 1
        curNode = head
        # measure size of LL
        while curNode.next != None:
            size += 1
            curNode = curNode.next
        
        halfPoint = size/2
        idx = 0
        curNode = head
        sumList = [head.val]
        while curNode.next != None:
            idx += 1
            curNode = curNode.next
            if idx < halfPoint:
                sumList.append(curNode.val)
            else:
                sumList[size-1-idx]+= curNode.val
        
        return max(sumList)