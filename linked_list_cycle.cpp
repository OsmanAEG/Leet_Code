// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return false;

    auto tail = head;
    head = head->next;

    while(head != nullptr) {
      if(head == tail) return true;
      if(head->next == nullptr || head->next->next == nullptr) return false;

      head = head->next->next;
      tail = tail->next;
    }

    return false;
  }
};