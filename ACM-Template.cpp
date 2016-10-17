#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

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

string replace_substring_to_another_substring(string s, string substr_original,
                                              string substr_target);

int main(int argc, const char *argv[]) {

  // time to code
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
    if (s[i] == c)
      ++count;
    else
      continue;
  }
  return count;
}

string replace_substring_to_another_substring(string s, string substr_original,
                                              string substr_target) {
  size_t index = 0;
  while (true) {
    /* Locate the substring to replace. */
    index = s.find(substr_original, index);
    if (index == std::string::npos)
      break;

    /* Make the replacement. */
    s.replace(index, substr_original.length(), substr_target);

    /* Advance index forward so the next iteration doesn't pick it up as well.
     */
    index += substr_original.length();
  }
  return s;
}

// @END_OF_SOURCE_CODE
