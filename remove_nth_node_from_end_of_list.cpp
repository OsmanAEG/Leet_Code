// LeetCode: 19

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head->next == nullptr) return nullptr;

    int size = 1;

    auto counter = head;

    while(counter->next != nullptr) {
      counter = counter->next;
      ++size;
    }

    int m = size - n;

    if(m == 0) {
      head = head->next;
      return head;
    }

    auto prev = head;
    auto remv = head;

    for(int i = 0; i < m; ++i) {
      prev = remv;
      remv = remv->next;
    }

    if(remv == nullptr) {
      prev->next = nullptr;
    } else {
      prev->next = remv->next;
    }

    return head;
  }
};