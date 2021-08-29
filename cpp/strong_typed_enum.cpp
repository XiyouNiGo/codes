#include <bits/stdc++.h>

using namespace std;
/* we can specify the basic type of enum */
enum class st_enum1 : char;

enum class st_enum2 : char {
    TEST
};

enum class st_enum3 : char {
    /* the name is not conflict */
    TEST
};

/* strong-type enum requires a name */
/* enum class : char; */

int main(int argc, char *argv[]) {
    char ch = 'A';
    /* this is wrong  */
    /* st_enum1 e1 = ch; */

    /* this is right */
    st_enum1 e2 = st_enum1(ch);

    /* specify field to use the member */
    cout << sizeof(st_enum2::TEST) << endl;
    return 0;
}

