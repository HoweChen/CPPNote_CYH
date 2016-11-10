#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  /* code */
  map<int, std::string> test = {{6, "f"}, {5, "e"}, {4, "d"},
                                {3, "c"}, {2, "b"}, {1, "a"}};

  for (auto itr : test) {
    // itr is not map<int, std::string>iterator, should change to i
    // if the arugment of test is a class, then auto would let itr(will be
    // changed to i) be the specific type of that argument as a member of test, so it would show the exact value of that type i, but it's not mutable
    //
    //
    // In this case the type of itr is a pair
    cout << itr.first << endl;
    itr.second = "Fuck";
  }

  for (auto i : test) {
    cout << i.second << endl;
  }

  for (auto &i : test) {
    cout << i.first << endl;
    i.second = "Fuck";
  }

  for (auto i : test) {
    cout << i.second << endl;
  }

  // we define an iterator of a STL
  vector<int> test2(5, 0);
  vector<int>::iterator itr_temp = test2.begin();
  //in this case itr_temp's type is itr_temp is an vector<int>::iterator
  //  itr_temp = 3;
  // illegal

  *itr_temp = 3; // legal

  return 0;
}

// change the content of what iterator point to, add &

// attr(optional) for ( range_declaration : range_expression ) loop_statement
// attr	-	any number of attributes
// range_declaration	-	a declaration of a named variable, whose type is the type of the element of the sequence represented by range_expression, or a reference to that type. Often uses the auto specifier for automatic type deduction
// range_expression	-	any expression that represents a suitable sequence (either an array or an object for which begin and end member functions or free functions are defined, see below) or a braced-init-list.
// loop_statement	-	any statement, typically a compound statement, which is the body of the loop
