ListNode *partition(ListNode *head, int x) {
  if (!head || !head->next) {
    return head;
  }
  ListNode *smalls = new ListNode;
  ListNode *greats = new ListNode;
  auto last_small = smalls;
  auto last_great = greats;
  while (head) {
    if (head->val < x) {
      last_small->next = head;
      head = head->next;
      last_small = last_small->next;
      last_small->next = nullptr;
    }
    else {
      last_great->next = head;
      head = head->next;
      last_great = last_great->next;
      last_great->next = nullptr;
    }
  }
  auto tmp = smalls;
  smalls = smalls->next;
  delete tmp;
  tmp = greats;
  greats = greats->next;
  delete tmp;
  if (greats == nullptr) {
    return smalls;
  }
  if (smalls == nullptr) {
    return greats;
  }
  last_small->next = greats;
  greats = nullptr;
  return smalls;
}