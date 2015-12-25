#ifndef _SUBJECT_H_
#define _SUBJECT_H_

class Subject {
 public:
  virtual ~Subject() {};
  virtual void SetParam(int i) = 0;
  virtual void Do() = 0;

 protected:
  Subject() {};
};
#endif
