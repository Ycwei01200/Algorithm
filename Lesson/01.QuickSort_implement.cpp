#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
void QuickSort(vector<int> &arr, int left, int right) {
  if (left >= right)
    return;
  int random_index = left + rand() % (right - left + 1);

  int l = left - 1; // 最後一個比random小的index

  swap(arr[random_index], arr[right]); // 確保random不會被交換導致陣列壞掉
  int random_value = arr[right];
  for (int i = left; i < right; i++) {
    if (arr[i] < random_value) {
      l++;
      swap(arr[i], arr[l]);
    }
  }
  swap(arr[right], arr[l + 1]);
  QuickSort(arr, left, l);
  QuickSort(arr, l + 2, right);
}
int main() {
  vector<int> arr = {5, 4, 1, 3, 2};
  int left = 0, right = arr.size() - 1;
  srand(time(NULL));
  QuickSort(arr, left, right);
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  return 0;
}