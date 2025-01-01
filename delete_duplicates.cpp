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
  ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr) return head;

    const auto first_head = head;
    auto next_head = head->next;

    while(head->next != nullptr) {
      if(head->val == next_head->val) {
        next_head = next_head->next;
        head->next = next_head;
      } else {
        head = next_head;
        next_head = head->next;
      }
    }

    return first_head;
  }
};