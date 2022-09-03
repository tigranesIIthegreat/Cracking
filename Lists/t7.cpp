size_t size(ListNode *l) {
  size_t result{};
  while (l) {
    ++result;
    l = l->next;
  }
  return result;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  auto s1 = size(headA);
  auto s2 = size(headB);
  if (s1 > s2) {
    for (int i{}; i < s1 - s2; ++i)
    {
      headA = headA->next;
    }
  }
  if (s1 < s2) {
    for (int i{}; i < s2 - s1; ++i)
    {
      headB = headB->next;
    }
  }
  while (headA && headB) {
    if (headA == headB)
    {
      return headA;
    }
    headA = headA->next;
    headB = headB->next;
  }
  return nullptr;
}