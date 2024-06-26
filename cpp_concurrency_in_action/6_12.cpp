#include <map>
#include <mutex>
#include <shared_mutex>
#include <vector>

typedef int Key;
typedef int Value;

std::map<Key, Value> threadsafe_lookup_table::get_map() const {
  std::vector<std::unique_lock<std::shared_mutex> > locks;
  /* to keep away from dead-lock, we needn't to lock at once */
  for (unsigned i = 0; i < buckets.size(); ++i) {
    locks.push_back(std::unique_lock<std::shared_mutex>(buckets[i].mutex));
  }
  std::map<Key, Value> res;
  for (unsigned i = 0; i < buckets.size(); ++i) {
    for (bucket_iterator it = buckets[i].data.begin();
         it != buckets[i].data.end(); ++it) {
      res.insert(*it);
    }
  }
  return res;
}
