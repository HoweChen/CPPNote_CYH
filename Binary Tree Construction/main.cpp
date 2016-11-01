#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>

using namespace std;

map<int, unsigned long long int> BinaryTreeMap;

unsigned long long int BTree(int node_number);

int main() {
  /* code */
  BinaryTreeMap[1] = 1;
  BinaryTreeMap[2] = 2;
  BinaryTreeMap[3] = 5;
  for (int i = 4; i <= 100; ++i) {
    BTree(i);
  }


  int n;
  cin >> n;
  if (n <= 0) {
    exit(0);
  } else {
    for (size_t i = 0; i < n; ++i) {
      int node_number;
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

unsigned long long int BTree(int node_number) {

  map<int, unsigned long long int>::iterator search = BinaryTreeMap.find(node_number);
  if (search != BinaryTreeMap.end()) {
    return search->second;
  } else {
    unsigned long long int result = 0;
    int without_root = node_number - 1;
    int middle = without_root / 2;

    if (without_root % 2 == 0) {

      for (int i = 1; i < middle; ++i) {
        int j = without_root - i;
        result = result + 2 * BTree(i) * BTree(j);
      }
      result = result + int(pow(double(BTree(middle)), double(2)));
      result = result + 2 * BTree(without_root);

    } else {

      for (int i = 1; i <= middle; ++i) {
        int j = without_root - i;
        result = result + 2 * BTree(i) * BTree(j);
      }
      result = result + 2 * BTree(without_root);

    }
    BinaryTreeMap[node_number] = result;
    return result;
  }

}
