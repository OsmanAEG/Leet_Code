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
  ListNode* perform_addition(ListNode* l1, ListNode* l2) {
    ListNode* start = new ListNode(0);
    auto nav = start;

    int trailing_digit = 0;

    while(l2 != nullptr) {
      const auto val = l1->val + l2->val + trailing_digit;
      int new_val = 0;

      if(val > 10) {
        new_val = val%10;
      } else if(val == 10) {
        new_val = 0;
      } else {
        new_val = val;
      }

      nav->next = new ListNode(new_val);

      trailing_digit = (val - new_val)/10;

      l1 = l1->next;
      l2 = l2->next;

      nav = nav->next;
    }

    while(l1 != nullptr) {
      const auto val = l1->val + trailing_digit;
      int new_val = 0;

      if(val > 10) {
        new_val = val%10;
      } else if(val == 10) {
        new_val = 0;
      } else {
        new_val = val;
      }

      nav->next = new ListNode(new_val);

      trailing_digit = (val - new_val)/10;

      l1 = l1->next;

      nav = nav->next;
    }

    if(trailing_digit > 0) {
      nav->next = new ListNode(trailing_digit);
    }

    return start->next;
  }

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto nav1 = l1;
    auto nav2 = l2;

    int sum1 = 0;
    int sum2 = 0;

    while(nav1 != nullptr) {
      ++sum1;
      nav1 = nav1->next;
    }

    while(nav2 != nullptr) {
      ++sum2;
      nav2 = nav2->next;
    }

    if(sum1 > sum2) {
      return perform_addition(l1, l2);
    }

    return perform_addition(l2, l1);
  }
};