#include <chrono>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

struct Employee {
  Employee(std::string id) : id(id) {}
  std::string id;
  std::vector<std::string> lunch_partners;
  std::mutex m;
  std::string output() const {
    std::string ret = "Employee " + id + " has lunch partners: ";
    for (const auto &partner : lunch_partners) ret += partner + " ";
    return ret;
  }
};

void send_mail(Employee &, Employee &) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void assign_lunch_partner(Employee &e1, Employee &e2) {
  static std::mutex io_mutex;
  {
    std::lock_guard<std::mutex> lk(io_mutex);
    std::cout << e1.id << " and " << e2.id << " are waiting for locks"
              << std::endl;
  }

  {
    /* C++17 */
    std::scoped_lock lock(e1.m, e2.m);

    // Equivalent code 1 (using std::lock and std::lock_guard)
    // std::lock(e1.m, e2.m);
    // std::lock_guard<std::mutex> lk1(e1.m, std::adopt_lock);
    // std::lock_guard<std::mutex> lk2(e2.m, std::adopt_lock);

    // Equivalent code 2 (if unique_locks are needed, e.g. for condition
    // variables) std::unique_lock<std::mutex> lk1(e1.m, std::defer_lock);
    // std::unique_lock<std::mutex> lk2(e2.m, std::defer_lock);
    // std::lock(lk1, lk2);
    {
      std::lock_guard<std::mutex> lk(io_mutex);
      std::cout << e1.id << " and " << e2.id << " got locks" << std::endl;
    }
    e1.lunch_partners.push_back(e2.id);
    e2.lunch_partners.push_back(e1.id);
  }

  send_mail(e1, e2);
  send_mail(e2, e1);
}

int main() {
  Employee alice("alice"), bob("bob"), christina("christina"), dave("dave");

  std::vector<std::thread> threads;
  threads.emplace_back(assign_lunch_partner, std::ref(alice), std::ref(bob));
  threads.emplace_back(assign_lunch_partner, std::ref(christina),
                       std::ref(bob));
  threads.emplace_back(assign_lunch_partner, std::ref(christina),
                       std::ref(alice));
  threads.emplace_back(assign_lunch_partner, std::ref(dave), std::ref(bob));

  for (auto &thread : threads) thread.join();
  std::cout << alice.output() << '\n'
            << bob.output() << '\n'
            << christina.output() << '\n'
            << dave.output() << '\n';
}