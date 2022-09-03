ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  if (l1 == nullptr)
    return l2;
  if (l2 == nullptr)
    return l1;
  int carry{};
  ListNode *fake = new ListNode;
  ListNode *result = fake;
  while (l1 && l2) {
    result->next = new ListNode((l1->val + l2->val + carry) % 10);
    result = result->next;
    carry = (l1->val + l2->val + carry) / 10;
    l1 = l1->next;
    l2 = l2->next;
  }
  while (l1) {
    result->next = new ListNode((l1->val + carry) % 10);
    carry = (l1->val + carry) / 10;
    result = result->next;
    l1 = l1->next;
  }
  while (l2) {
    result->next = new ListNode((l2->val + carry) % 10);
    carry = (l2->val + carry) / 10;
    result = result->next;
    l2 = l2->next;
  }
  if (carry) {
    result->next = new ListNode(1);
  }
  result = fake->next;
  delete fake;
  return result;
}