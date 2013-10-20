// grading2.cpp - uses C++ style object-handling (AFTER CHANGES BELOW)          
// Sean Prasertsit, Keith Waldron 10/17/2013                                    

#include <iostream>
using namespace std;

class Record {

public:
  void setGrades(double q1, double q2,double m, double f);
  char overallGrade() const;

private:
  double quiz1, quiz2;
  double midterm, final;
  char letterEquiv(double grade) const;

};

Record getScores();

int main() {
  Record rec = getScores();
  cout << "Grade is " << rec.overallGrade() << endl;
  return 0;
}

Record getScores() {
  Record result;
  double q1, q2, m, f;
  cout << "Enter scores in this order: 2 quizzes, midterm, final: ";
  cin >> q1 >> q2 >> m >> f;
  result.setGrades(q1, q2, m, f);
  return result;
}
