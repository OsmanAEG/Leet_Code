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
  ListNode* middleNode(ListNode* head) {
    auto tail = head;

    while(head != nullptr && head->next != nullptr) {
      head = head->next->next;
      tail = tail->next;
    }

    return tail;
  }
};