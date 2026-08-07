# Definition for singly - linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: ListNode):
        if not head:
            return None

        cur = head.next
        prev = head
        prev.next = None

        while cur:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp

        return prev
