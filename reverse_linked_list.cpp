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
    if(head == nullptr || head->next == nullptr) return head;

    ListNode* prev_head = nullptr;

    while(head != nullptr) {
      ListNode* next_head = head->next;
      head->next = prev_head;

      prev_head = head;
      head = next_head;
    }

    return prev_head;
  }
};