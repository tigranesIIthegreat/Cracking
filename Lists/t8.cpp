bool has_cycle(ListNode *head) {
  if (!head || !head->next) {
    return false;
  }
  auto slow = head;
  auto fast = head;
  while (fast && fast->next) {
    if (slow->val == fast->val)
    {
      return true;
    }
    slow = slow->next;
    fast = fast->next->next;
  }
  return false;
}

ListNode *detectCycle(ListNode *head) {
  bool has = has_cycle(head);
  if (!has) {
    return nullptr;
  }
  unordered_map<ListNode *, bool> ht;
  while (head) {
    if (ht[head]) {
      return head;
    }
    ht[head] = true;
    head = head->next;
  }
  return nullptr;
}