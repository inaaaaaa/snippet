#include <iostream>
#include <string>

using namespace std;

class Builder
{
public:
  virtual void BuildBase() = 0;
  virtual void BuildHeader(string title) = 0;
  virtual void BuildHeading1(string s) = 0;
  virtual void BuildHeading2(string s) = 0;
  virtual void BuildParagraph(string s) = 0;
  virtual void BuildFooter() = 0;
  string GetResult() {
    return this->ret;
  }
protected:
  string ret;
  void append(string s) {
    this->ret += s;
  }
};

class HTMLBuilder : public Builder
{
public:
  HTMLBuilder() {}
  ~HTMLBuilder() {}
  void BuildBase() {
    this->ret = "";
  }
  void BuildHeader(string title) {
    append("<!DOCTYPE html>\n<html>\n<head><title>" + title + "</title></head>\n<body>\n");
  }
  void BuildHeading1(string s) {
    append("<h1>" + s + "</h1>\n");
  }
  void BuildHeading2(string s) {
    append("<h2>" + s + "</h2>\n");
  }
  void BuildParagraph(string s) {
    append("<p>" + s + "</p>\n");
  }
  void BuildFooter() {
    append("</body>\n</html>\n");
  }
};

class MarkDownBuilder : public Builder
{
public:
  MarkDownBuilder() {}
  ~MarkDownBuilder() {}
  void BuildBase() {
    this->ret = "";
  }
  void BuildHeader(string title) {
    append("# " + title + "\n");
  }
  void BuildHeading1(string s) {
    append("## " + s + "\n");
  }
  void BuildHeading2(string s) {
    append("### " + s + "\n");
  }
  void BuildParagraph(string s) {
    append(s + "  \n");
  }
  void BuildFooter() {
    append("");
  }
};

class Director
{
public:
  static void Construct(Builder *builder) {
    builder->BuildBase();
    builder->BuildHeader("This is Title");
    builder->BuildHeading1("Yes");
    builder->BuildParagraph("foo foofoo foofoofoo");
    builder->BuildHeading2("No");
    builder->BuildParagraph("bar barbar barbarbar");
    builder->BuildFooter();
  }
};

int main() {
  cout << "==== start ====" << endl;

  HTMLBuilder *b0 = new HTMLBuilder;
  Director::Construct(b0);
  cout << b0->GetResult();

  MarkDownBuilder *b1 = new MarkDownBuilder;
  Director::Construct(b1);
  cout << b1->GetResult();

  cout << "==== end ====" << endl;
}
