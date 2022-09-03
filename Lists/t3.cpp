ListNode *deleteMiddle(ListNode *head) {
  if (head->next == nullptr) {
    delete head;
    head = nullptr;
    return head;
  }
  auto slow = head;
  auto fast = head;
  auto prev = head;
  slow = slow->next;
  fast = fast->next->next;
  while (fast && fast->next) {
    slow = slow->next;
    prev = prev->next;
    fast = fast->next->next;
  }
  prev->next = slow->next;
  delete slow;
  return head;
}