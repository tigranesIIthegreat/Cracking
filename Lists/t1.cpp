ListNode *deleteDuplicates(ListNode *head) {
  if (!head || !head->next) {
    return head;
  }
  auto result = head;
  std::unordered_map<int, bool> m;
  m[head->val] = true;
  while (head->next) {
    if (m[head->next->val] == false) {
      m[head->next->val] = true;
      head = head->next;
    }
    else {
      auto next = head->next;
      head->next = head->next->next;
      delete next;
    }
  }
  return result;
}