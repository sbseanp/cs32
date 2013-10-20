// grading2.cpp - uses C++ style object-handling (AFTER CHANGES BELOW)          
// Sean Prasertsit, Keith Waldron 10/17/2013                                    

#include <iostream>
using namespace std;

class Record {

public:
  void setGrades(double q1, double q2,double m, double f);
  char overallGrade() const;
  double getQuiz1(), getQuiz2(), getMiderm(), getFinal();
  void setQuiz1(double sq1), setQuiz2(double sq2), setMidterm(double sm), setFinal(double sf);
  
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

char Record::letterEquiv(double grade) const {
  if (grade >= 90) return 'A';
  if (grade >= 80) return 'B';
  if (grade >= 70) return 'C';
  if (grade >= 60) return 'D';
  return 'F';
}

char Record::overallGrade() const {
  double quizPct = (quiz1 / 10 + quiz2 / 10) / 2;
  double overall = 25 * quizPct + 0.25 * midterm + 0.5 * final;
  return letterEquiv(overall);
}

void Record::setGrades(double q1, double q2, double m, double f) {
  quiz1 = q1;
  quiz2 = q2;
  midterm = m;
  final = f;
}

double Record::getQuiz1() {
  return quiz1;
}

double Record::getQuiz2() {
  return quiz2;
}

double Record::getMidterm() {
  return midterm;
}

double Record::getFinal() {
  return final;
}
