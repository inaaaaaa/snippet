#include <iostream>
#include <string>

using namespace std;

class AbstractFactory
{
public:
  virtual string MakeBase() = 0;
  virtual string MakeHeader(string title) = 0;
  virtual string MakeHeading1(string s) = 0;
  virtual string MakeHeading2(string s) = 0;
  virtual string MakeParagraph(string s) = 0;
  virtual string MakeFooter() = 0;
};

class HTMLFactory : public AbstractFactory
{
public:
  string MakeBase() {
    return "";
  }
  string MakeHeader(string title) {
    return "<!DOCTYPE html>\n<html>\n<head><title>" + title + "</title></head>\n<body>\n";
  }
  string MakeHeading1(string s) {
    return "<h1>" + s + "</h1>\n";
  }
  string MakeHeading2(string s) {
    return "<h2>" + s + "</h2>\n";
  }
  string MakeParagraph(string s) {
    return "<p>" + s + "</p>\n";
  }
  string MakeFooter() {
    return "</body>\n</html>\n\n";
  }
};

class MarkDownFactory : public AbstractFactory
{
public:
  string MakeBase() {
    return "";
  }
  string MakeHeader(string title) {
    return "# " + title + "\n";
  }
  string MakeHeading1(string s) {
    return "## " + s + "\n";
  }
  string MakeHeading2(string s) {
    return "### " + s + "\n";
  }
  string MakeParagraph(string s) {
    return s + "  \n";
  }
  string MakeFooter() {
    return "\n";
  }
};

class Document
{
public:
  static string Create(AbstractFactory *factory) {
    string s = factory->MakeBase();
    s += factory->MakeHeader("This is Title");
    s += factory->MakeHeading1("Yes");
    s += factory->MakeParagraph("foo foofoo foofoofoo");
    s += factory->MakeHeading2("No");
    s += factory->MakeParagraph("bar barbar barbarbar");
    s += factory->MakeFooter();
    return s;
  }
};

int main() {
  cout << "==== start ====" << endl;
  cout << Document::Create(new HTMLFactory);
  cout << Document::Create(new MarkDownFactory);
  cout << "==== end ====" << endl;
}
