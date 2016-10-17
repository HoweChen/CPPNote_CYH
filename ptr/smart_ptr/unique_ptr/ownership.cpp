#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <memory>

#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define LL long long

inline LL Power(int b, int p) {
  LL ret = 1;
  for (int i = 1; i <= p; i++)
    ret *= b;
  return ret;
}

const int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

//  simple for
#define F(i, a) for (int i = (0); i < (a); i++)
//  for size
#define Fs(i, sz) for (size_t i = 0; i < sz.size(); i++)
//  for i(e)terator
#define Fe(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define Set(a, s) memset(a, s, sizeof(a))
#define Max(a, b) (a < b ? b : a)
#define Min(a, b) (a > b ? b : a)

using namespace std;

int find_occurence_character(string s, char c);

int find_occurence_substring(string s, string substr);

string replace_substring_to_another_substring(string s, string substr_original, string substr_target);

int main(int argc, const char *argv[]) {

  //time to code
//  auto_ptr<string> films[5] = {
//      auto_ptr<string>(new string("A")),
//      auto_ptr<string>(new string("B")),
//      auto_ptr<string>(new string("C")),
//      auto_ptr<string>(new string("D")),
//      auto_ptr<string>(new string("E")),
//  };

//  auto_ptr<string> test;
//  test = films[2];
////  films[2] would lost the ownership
//  F(i, 5) {
//    cout << *films[i] << endl;
//  }

  unique_ptr<string> pu1(new string("Hi ho"));
  unique_ptr<string> pu2;
//  pu2 = pu1; //not allow;

  unique_ptr<string> pu3;
  pu3 = unique_ptr<string>(new string("Hi ho"));
  cout << *pu3 << endl;

  return 0;
}

int find_occurence_substring(string s, string substr) {
  int count = 0;
  size_t nPos = s.find(substr, 0); // fist occurrence
  while (nPos != string::npos) {
    count++;
    nPos = s.find(substr, nPos + 1);
  }

  return count;
}

int find_occurence_character(string s, char c) {
  int count = 0;
  Fs(i, s) {
    if (s[i] == c) ++count;
    else continue;
  }
  return count;
}

string replace_substring_to_another_substring(string s, string substr_original, string substr_target) {
  size_t index = 0;
  while (true) {
    /* Locate the substring to replace. */
    index = s.find(substr_original, index);
    if (index == std::string::npos) break;

    /* Make the replacement. */
    s.replace(index, substr_original.length(), substr_target);

    /* Advance index forward so the next iteration doesn't pick it up as well. */
    index += substr_original.length();
  }
  return s;

}

// @END_OF_SOURCE_CODE
