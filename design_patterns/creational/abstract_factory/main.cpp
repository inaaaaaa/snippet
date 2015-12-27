#include <iostream>
#include <string>

using namespace std;

class AbstractFactory
{
public:
  virtual string GenBase() = 0;
  virtual string GenHeader(string title) = 0;
  virtual string GenHeading1(string s) = 0;
  virtual string GenHeading2(string s) = 0;
  virtual string GenParagraph(string s) = 0;
  virtual string GenFooter() = 0;
};

class HTMLFactory : public AbstractFactory
{
public:
  string GenBase() {
    return "";
  }
  string GenHeader(string title) {
    return "<!DOCTYPE html>\n<html>\n<head><title>" + title + "</title></head>\n<body>\n";
  }
  string GenHeading1(string s) {
    return "<h1>" + s + "</h1>\n";
  }
  string GenHeading2(string s) {
    return "<h2>" + s + "</h2>\n";
  }
  string GenParagraph(string s) {
    return "<p>" + s + "</p>\n";
  }
  string GenFooter() {
    return "</body>\n</html>\n";
  }
};

class MarkDownFactory : public AbstractFactory
{
public:
  string GenBase() {
    return "";
  }
  string GenHeader(string title) {
    return "# " + title + "\n";
  }
  string GenHeading1(string s) {
    return "## " + s + "\n";
  }
  string GenHeading2(string s) {
    return "### " + s + "\n";
  }
  string GenParagraph(string s) {
    return s + "  \n";
  }
  string GenFooter() {
    return "";
  }
};

class Client
{
public:
  static string Create(AbstractFactory *factory) {
    string s = factory->GenBase();
    s += factory->GenHeader("This is Title");
    s += factory->GenHeading1("Yes");
    s += factory->GenParagraph("foo foofoo foofoofoo");
    s += factory->GenHeading2("No");
    s += factory->GenParagraph("bar barbar barbarbar");
    s += factory->GenFooter();
    return s;
  }
};

int main() {
  cout << "==== start ====" << endl;
  cout << Client::Create(new HTMLFactory);
  cout << Client::Create(new MarkDownFactory);
  cout << "==== end ====" << endl;
}
