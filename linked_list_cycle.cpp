// LeetCode: 141

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if(head == nullptr) return false;

    auto slow = head;
    auto fast = head->next;

    while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
      if(fast == slow) return true;

      slow = slow->next;
      fast = fast->next->next;
    }

    return false;
  }
};