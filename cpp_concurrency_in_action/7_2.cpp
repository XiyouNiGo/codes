#include <atomic>

template <typename T>
class lock_free_stack {
 private:
  struct node {
    T data;
    node* next;
    node(T const& data_) : data(data_) {}
  };
  std::atomic<node*> head;

 public:
  void push(T const& data) {
    // A example to teach ZhouKuo using division by std::atomic
    // std::atomic<int> ai;
    // int tmp = ai.load();
    // while (!ai.compare_exchange_weak(tmp, ai / 2));

    node* const new_node = new node(data);
    new_node->next = head.load();
    /* compare_exchange_weak may happen spurious failure owing to thread
     * rounding */
    while (!head.compare_exchange_weak(new_node->next, new_node))
      ;
  }
};
