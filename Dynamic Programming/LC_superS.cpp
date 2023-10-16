#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NN = 1001;

int LCS[NN][NN];

void scs( string str1, string str2, int m, int n ) {
  for (int i=0; i<=m; i++) {
      for (int j=0; j<=n; j++) {
          if (i == 0 || j == 0)
            LCS[i][j] = 0;
          else if (str1[i-1] == str2[j-1])
            LCS[i][j] = LCS[i-1][j-1] + 1;
          else
            LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    }
    
  int i = m, j = n, index = LCS[m][n];
  string lcs_arr;
  while (i > 0 && j > 0) {
      if (str1[i-1] == str2[j-1]) {
          lcs_arr += str1[i-1]; 
          i--; 
          j--; 
          index--;     
        }
 
      else if (LCS[i-1][j] > LCS[i][j-1])
        i--;
      else
        j--;
    }
    
  i = m-1, j = n-1;
  int l = 0,k = 0;
  index = LCS[m][n];
  cout << lcs_arr << endl;
  //string containing the final answer
  string ans = "";
    
  while(i>=0 || j>=0) {
    if(l < index) {
      while(i >= 0 && str1[i] != lcs_arr[l])
        ans += str1[i--];
            
      while(j >= 0 && str2[j] != lcs_arr[l])
        ans += str2[j--];
            
      ans += lcs_arr[l++];
      j--;
      i--;
    }
    else{
      while(i >= 0)
        ans += str1[i--];
      while(j >= 0)
        ans += str2[j--];
    }
  }
  for(int i = ans.length()-1;i>=0;i--)
    cout<<ans[i];
  cout<<endl;
}

int main() {
  string s1 = "AGGTAB", s2 = "GXTXAYB";
  scs(s1,s2,s1.length(),s2.length());
  return 0;
}
