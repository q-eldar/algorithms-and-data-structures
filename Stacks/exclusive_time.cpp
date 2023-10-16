#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <sstream>
#include <tuple>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stack;
using std::pair;
using std::tuple;

void Split(std::string &s, std::string &delim, std::vector<std::string> &elems){
  std::regex rgx(delim);
  std::sregex_token_iterator begin(s.begin(), s.end(), rgx, -1);
  std::sregex_token_iterator end;
  while (begin != end) {
    elems.push_back(*begin);
    ++begin;
  }
}

class Log {
public:
  int id;
  bool is_start;
  int time;
  Log(std::string content ) {
    std::vector<std::string> strs;
    std::string delim = ":";
    Split(content, delim, strs);
    id = stoi(strs[0]);
    is_start = strs[1] == "start";
    time = stoi(strs[2]);
  }
};

vector<int> exclusive_time(int n, vector<string> &logs) {
  stack<Log> log_stack;
  vector<int> result(n);
  for (std::string content : logs) {
    Log event(content);
    if (event.is_start)
      log_stack.push(event);
    else {
      Log top = log_stack.top();
      log_stack.pop();
      result[top.id] += (event.time - top.time + 1);
      if (!log_stack.empty())
        result[log_stack.top().id] -= (event.time - top.time + 1);
    }
  }
  return result;
}

int main() {
  vector<string> logs{
    "0:start:0",
    "1:start:2",
    "1:end:3",
    "2:start:4",
    "2:end:7",
    "0:end:8"
  };
  for(const auto& item : exclusive_time(3, logs))
    cout << item << endl;
}
