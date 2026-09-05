class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1, l2):

        dummy = ListNode(0)
        current = dummy
        carry = 0

        while l1 is not None or l2 is not None or carry != 0:

            sum = carry

            if l1 is not None:
                sum += l1.val
                l1 = l1.next

            if l2 is not None:
                sum += l2.val
                l2 = l2.next

            carry = sum // 10

            current.next = ListNode(sum % 10)
            current = current.next

        return dummy.next


# Create linked list
def create_linked_list(arr):
    dummy = ListNode(0)
    current = dummy

    for value in arr:
        current.next = ListNode(value)
        current = current.next

    return dummy.next


# Print linked list
def print_linked_list(head):
    result = []

    while head is not None:
        result.append(head.val)
        head = head.next

    print(result)


# -------------------------
# Take input from user
# -------------------------

l1_input = input("Enter elements of l1 separated by space: ")
l2_input = input("Enter elements of l2 separated by space: ")

l1 = create_linked_list(map(int, l1_input.split()))
l2 = create_linked_list(map(int, l2_input.split()))


# Solve
solution = Solution()
answer = solution.addTwoNumbers(l1, l2)


# Print answer
print("Result:", end=" ")
print_linked_list(answer)