
#include <bits/stdc++.h>

using namespace std;

class Based {
 public:
  explicit Based(string bd = "initialized based_data") : based_data(bd) {
    cout << "Based() is called, now based_data is "
    	 << based_data << endl;
  }

  void alter_data() {
    based_data = "Based altered";
    cout << "Based's alter_data() is called, now based_data is "
         << based_data << endl;
  }
 protected:
  string based_data;
};

class Derived : public Based {
 public:
  explicit Derived(string dd = "initialized derived_data") : Based(), derived_data(dd) {
	cout << "Derived() is called, now derived_data is "
		 << derived_data << endl;
  }

  void alter_data() {
    Based::alter_data();
//	static_cast<Based>(*this).alter_data();
	derived_data = "Derived altered";
	cout << "Derived's alter_data() is called, now derived_data is "
		 << derived_data << " while based_data is "
		 << based_data << endl;
  }
 protected:
  string derived_data;
};

int main(int argc, char *argv[]) {
  Derived d;
  d.alter_data();
  return 0;
}
