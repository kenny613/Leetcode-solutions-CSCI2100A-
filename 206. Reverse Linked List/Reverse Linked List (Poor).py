 #Leetcode206: generate reversed linkedlist (Poor version)
    #https://leetcode.com/submissions/detail/350174579/
    #Time:O(n^2) #Space:O(n)
    
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self,head): 
        if not head or not head.next:
            return head
        newhead=self.reverseList(head.next)
        n=newhead
        while n.next is not None:
            n=n.next    
        n.next=head
        n.next.next=None
        return newhead
 