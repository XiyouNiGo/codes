#include "gtest/gtest.h"

using namespace std;

class VectorTest : public ::testing::Test {
protected:
    void SetUp() override {
        cout << "SetUp is called." << endl;
    }
    void TearDown() override {
        cout << "TearDown is called." << endl;
    }
    static void SetUpTestCase() {
        cout << "SetUpTestCase is called." << endl;
    }
    static void TearDownTestCase() {
        cout << "TearDownTestCase is called." << endl;
    }

    static vector<int> class_vec_;
    vector<int> member_vec_;
};

TEST_F(VectorTest, Test1) {
    cout << "Test1 is being tested." << endl;
}

TEST_F(VectorTest, Test2) {
    cout << "Test1 is being tested." << endl;
}
