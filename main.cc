#include <iostream>
#include <string>
#include <vector>
#include "pinyin.h"
#include "simple_tokenizer.h"

using namespace simple_tokenizer;

int printFn(void* pCtx, int flags, const char* index, int len, int start, int end) {
  std::cout << "\t" << index << " " << len << " " << start << " " << end << "\n";
  return 0;
}

int main() {
  SimpleTokenizer* t = new SimpleTokenizer(nullptr, 0);
  std::vector<std::string> arr;
  // arr.push_back("hello, 你好。EnD完 zhangliangy");
  arr.push_back("张Li");
  for (std::string& s : arr) {
    std::cout << s << " as doc:\n";
    t->tokenize(nullptr, FTS5_TOKENIZE_DOCUMENT, s.c_str(), s.length(), printFn);
    std::cout << s << " as query:\n";
    t->tokenize(nullptr, FTS5_TOKENIZE_QUERY, s.c_str(), s.length(), printFn);
    std::cout << s << " as aux:\n";
    std::string result = SimpleTokenizer::tokenize_query(s.c_str(), s.length());
    std::cout << "\t" << result << "\t";
    result = SimpleTokenizer::tokenize_query(s.c_str(), s.length());
    std::cout << "\t" << result << "\t";
  }

  PinYin* pinyin = new PinYin();
  std::cout << "split zhangliangy:"
            << "\n";
  for (auto s : pinyin->split_pinyin("zhongg")) {
    std::cout << "\t" << s << "\n";
  }
  for (auto s : pinyin->split_pinyin("zhangliangy")) {
    std::cout << "\t" << s << "\n";
  }
  return 0;
}
