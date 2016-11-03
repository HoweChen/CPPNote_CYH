#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
namespace mp = boost::multiprecision;

map<int, unsigned long long> BinaryTreeMap;

//unsigned long long BTree(int node_number);
void BTree(int node_number);

int main() {
  /* code */
  BinaryTreeMap[1] = 1;
  BinaryTreeMap[2] = 2;
  BinaryTreeMap[3] = 5;
//  for (int i = 4; i <= 100; ++i) {
//    BTree(i);
//  }


  int n;
  cin >> n;
  if (n <= 0) {
    exit(0);
  } else {
    vector<unsigned long long> result;
    for (size_t i = 0; i < n; ++i) {
      int node_number;
      cin >> node_number;
      if (node_number < 1 || node_number > 10000) {
        exit(0);
      } else {
        map<int, unsigned long long>::iterator search = BinaryTreeMap.find(node_number);
        if (search != BinaryTreeMap.end()) {
          result.push_back(search->second);
        } else {
          BTree(node_number);
          result.push_back(BinaryTreeMap.find(node_number)->second);
        }
      }
    }

    for (int j = 0; j < result.size(); ++j) {
      cout << result[j] << endl;
    }

  }
  return 0;
}


void BTree(int node_number) {
  //version 2
  for (int i = 4; i <= node_number; ++i) {
    unsigned long long result = 0;
    int without_root = i - 1;
    int middle = without_root / 2;

    if (without_root % 2 == 0) {

      for (int k = 1; k < middle; ++k) {
        int j = without_root - k;
        result = result + 2 * BinaryTreeMap.find(k)->second * BinaryTreeMap.find(j)->second;
        cout << i << ": 2 * F[" << k << "] * F[" << j << "] = " << result << endl;
      }
      result = result + BinaryTreeMap.find(middle)->second * BinaryTreeMap.find(middle)->second;
      cout << i << ": F[" << middle << "] * F[" << middle << "] = " << result << endl;
      result = result + 2 * BinaryTreeMap.find(without_root)->second;
      cout << i << ": 2 * F[" << without_root << "] = " << result << endl;

    } else {

      for (int k = 1; k <= middle; ++k) {
        int j = without_root - k;
        result = result + 2 * BinaryTreeMap.find(k)->second * BinaryTreeMap.find(j)->second;
        cout << i << ": 2 * F[" << k << "] * F[" << j << "] = " << result << endl;
      }
      result = result + 2 * BinaryTreeMap.find(without_root)->second;
      cout << i << ": 2 * F[" << without_root << "] = " << result << endl;

    }
    BinaryTreeMap[i] = result;
//    cout<<result<<endl;

  }

//  return BinaryTreeMap.find(node_number)->second;
}


//unsigned long long BTree(int node_number) {
//
////  version 1
//  map<int, unsigned long long>::iterator search = BinaryTreeMap.find(node_number);
//  if (search != BinaryTreeMap.end()) {
//    return search->second;
//  } else {
//    unsigned long long result = 0;
//    int without_root = node_number - 1;
//    int middle = without_root / 2;
//
//    if (without_root % 2 == 0) {
//
//      for (int i = 1; i < middle; ++i) {
//        int j = without_root - i;
//        result = result + 2 * BTree(i) * BTree(j);
//      }
//      result = result + int(pow(double(BTree(middle)), double(2)));
//      result = result + 2 * BTree(without_root);
//
//    } else {
//
//      for (int i = 1; i <= middle; ++i) {
//        int j = without_root - i;
//        result = result + 2 * BTree(i) * BTree(j);
//      }
//      result = result + 2 * BTree(without_root);
//
//    }
//    BinaryTreeMap[node_number] = result;
//    return result;
//  }
//}
