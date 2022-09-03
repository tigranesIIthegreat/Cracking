ListNode *removeNthFromEnd(ListNode *head, int n) {
  size_t size{};
  auto curr = head;
  while (curr) {
    ++size;
    curr = curr->next;
  }
  if (size == n) {
    auto next = head->next;
    delete head;
    return next;
  }
  curr = head;
  for (int i{}; i < size - 1 - n; ++i) {
    curr = curr->next;
  }
  auto next = curr->next;
  curr->next = next->next;
  delete next;
  return head;
}