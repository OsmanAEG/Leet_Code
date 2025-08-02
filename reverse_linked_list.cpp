// LeetCode: 206

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) {
      return head;
    }

    auto next = head->next;
    head->next = nullptr;

    while(next != nullptr) {
      auto next_next = next->next;

      next->next = head;
      head = next;
      next = next_next;
    }

    return head;
  }
};