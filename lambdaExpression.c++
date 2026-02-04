#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec = {5, 2, 8, 2, 1, 5, 7, 9};

  //   sort(vec.begin(), vec.end(), [](const int& a, const int& b) {
  //     cout << a << " : " << b << endl;
  //     return a > b;
  //   });

  //   for (int val : vec) {
  //     cout << val << " ";
  //   }

  //------------------------------------------------------------------------------------------------

  //   auto it =
  //       find_if(vec.begin(), vec.end(), [](const int& a) { return a % 3 == 0;
  //       });

  //   if (it != vec.end())
  //     cout << *(it) << endl;
  //   else
  //     cout << "No such element!";

  //------------------------------------------------------------------------------------------------

  auto res = [](int a) { return a + a; };

  cout << res(2);

  return 0;
}