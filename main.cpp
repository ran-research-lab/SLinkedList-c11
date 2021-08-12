#include <iostream>
#include <string>
#include "slinkedlist.h"
#include "slinkedlist.cpp"
using namespace std;

// Variables and macros for assertions, DO NOT CHANGE ****
int totalAssertions = 0;
int passedAssertions  = 0;
#define expect( chk )  \
    totalAssertions++; \
    if (!(chk)) \
    printf("\x1B[31mAssertion (%s) failed %s at line %d\033[0m\t\t\n", #chk, __FILE__,__LINE__); \
    else { \
    printf("\x1B[32mPassed line %d: %s\033[0m\t\t\n", __LINE__, #chk); \
    passedAssertions++; \
    }
#define assertionReport() { \
    printf("==========================================\n"); \
    printf("Passed %d of %d assertions\n",passedAssertions,totalAssertions); \
    printf("\n"); \
    }
//*******************************************************


int main()
{
    SLinkedList<int> L;
    L.addFront(12);
    L.addFront(66);
    expect(L.front() == 66);
    cout << L.toString() << endl;


    SLinkedList<string> S;
    S.addFront("uno");
    S.addFront("dos");
    expect(S.front() == "dos");
    cout << S.toString() << endl;

    SLinkedList<string> S2;
    S2 = S;
    cout << S2.toString() << endl;
    S2.addFront("tres");
    cout << S2.toString() << endl;

    return 0;
}
