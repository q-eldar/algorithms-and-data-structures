#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverse_words(string sent) {
  reverse(sent.begin(), sent.end());
  int start = 0;
  int end = 0;

  while(start < sent.size()) {
    while (end < sent.size() && sent[end] != ' ') end++;
    reverse(sent.begin() + start, sent.begin() + end);
    while (end < sent.size() && sent[end] == ' ') end++;
    start = end;
  }
  return sent;
}

int main() {
  string sent{"The quick brown fox jumped over a lazy dog"};

  cout << reverse_words(sent) << endl;
}
