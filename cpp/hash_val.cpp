#include <bits/stdc++.h>

using namespace std;

//代码来自侯捷

class Customer {
public:
    string mFirstName;
    string mLastName;
    string mAge;

    Customer(string firstName, string lastName, string age)
        : mFirstName(firstName), mLastName(lastName), mAge(age) {  }

    bool operator==(const Customer& c) const
    {
        return (mFirstName == c.mFirstName && mLastName == c.mLastName && mAge == c.mAge);
    }
};

class CustomerHash {
public:
    size_t operator()(const Customer& c) const {
        return hash_val(c.mFirstName, c.mLastName, c.mAge);
    }

    template <typename... Types>
    size_t hash_val(const Types&... args)const {
        size_t seed = 0;
        hash_value(seed, args...);
        return seed;
    }

    template <typename T, typename... Types>
    void hash_value(size_t& seed,
                         const T& firstArg,
                         const Types&... args) const {
        hash_combine(seed, firstArg);
        hash_value(seed, args...);
    }

    template <typename T>
    void hash_value(size_t& seed,
                         const T& val) const {
        hash_combine(seed, val);
    }

    template<typename T>
    void hash_combine(size_t& seed,
                             const T& val) const {
        seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
};

int main() {
    unordered_multiset<Customer, CustomerHash> set;
}

