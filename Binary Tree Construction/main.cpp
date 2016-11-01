#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

long BTree(long node_number);

int main() {
  /* code */
  long n;
  cin >> n;
  if (n <= 0) {
    exit(0);
  } else {
    for (long i = 0; i < n; ++i) {
      long node_number;
      cin >> node_number;
      if (node_number < 1 || node_number > 10000) {
        exit(0);
      } else {
        cout << BTree(node_number) << endl;
      }
    }
  }
  return 0;
}

long BTree(long node_number) {
  if (node_number == 1) {
    return 1;
  } else if (node_number == 2) {
    return 2;
  } else if (node_number == 3) {
    return 5;
  } else {
    long result = 0;
    long middle;
    if (node_number % 2 == 0) {
      middle = node_number / 2;
      for (long i = 1; i < middle; ++i) {
        long j = node_number - i;
        result += BTree(i) * BTree(j);
      }
      result = 2 * result;
      result += pow(double(BTree(middle)), double(2));
    } else {
      middle = node_number / 2 + 1;
      for (long i = 1; i < middle; ++i) {
        long j = node_number - i;
        result += BTree(i) * BTree(j);
      }
      result = 2 * result;
    }
    //    for (long i = 1; i < node_number; ++i) {
    //      long j = node_number - i;
    //      result += BTree(i) * BTree(j);
    //    }
    return result;
  }
}
