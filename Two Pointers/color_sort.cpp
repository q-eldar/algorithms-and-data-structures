#include <iostream>
#include <vector>
using namespace std;

vector<int> color_sort(vector<int> colors) {
  int red = 0;                  // color 0
  int white = 0;                // color 1
  int blue = colors.size() - 1; // color 2

  while (white <= blue) {
    if (colors[white] == 0) {
      swap(colors[white], colors[red]);
      red++;
      white++;
    } else if (colors[white] == 1) {
      white++;
    } else {
      swap(colors[white], colors[blue]);
        blue--;
    }
  }
  return colors;
}

int main() {
  vector<int> colors{1, 1, 0, 2};
  colors = color_sort(colors);

  for (int item : colors)
    cout << item << " ";
  cout << endl;
}
