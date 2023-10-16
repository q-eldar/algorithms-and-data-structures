// https://leetcode.com/problems/maximum-product-subarray/
// solution: https://www.interviewbit.com/blog/word-break-problem/
#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

bool wordBreak(string s, vector < string > & wordDict) {
  set < string > word_set(wordDict.begin(), wordDict.end());
  vector < bool > dp(s.length() + 1);
  dp[0] = true;
 
  for (int i = 1; i <= s.length(); i++) {
    for (int j = 0; j < i; j++) {
      if (dp[j] and word_set.find(s.substr(j, i - j)) != word_set.end()) {
        dp[i] = true;
        break;
      }
    }
  }
  return dp[s.length()];
}

int main() {
  string s{"leetcode"};
  vector<string> words{"leet","code"};
  cout << wordBreak(s, words) << endl;
}
