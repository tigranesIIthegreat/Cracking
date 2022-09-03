size_t size(ListNode *l) {
  size_t result{};
  while (l) {
    ++result;
    l = l->next;
  }
  return result;
}

bool isPalindrome(ListNode *l) {
  if (!l || !l->next) {
    return true;
  }
  auto s = size(l);
  std::stack<int> st;
  for (int i{}; i < s / 2; ++i) {
    st.push(l->val);
    l = l->next;
  }
  if (s % 2) {
    l = l->next;
  }
  while (l) {
    if (st.top() == l->val) {
      st.pop();
      l = l->next;
    }
    else {
      return false;
    }
  }
  return true;
}