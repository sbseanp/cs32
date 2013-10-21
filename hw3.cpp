#include <iostream>
using namespace std;

class Record {

public:
  Record();
  Record(double rq1, double rq2, double rm, double rf);
  void setGrades(double q1, double q2,double m, double f);
  char overallGrade() const;
  char overallGrade(double quizwt, double midtermwt, double finalwt);
  double getQuiz1();
  double getQuiz2();
  double getMidterm();
  double getFinal();
  void setQuiz1(double sq1);
  void setQuiz2(double sq2);
  void setMidterm(double sm);
  void setFinal(double sf);

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

Record::Record() {
  quiz1 = 0;
  quiz2 = 0;
  midterm = 0;
  final = 0;
}

Record::Record(double q1, double q2, double m, double f) {
  quiz1 = q1, quiz2 = q2, midterm = m, final = f;
  if (q1 < 0)
    quiz1 = 0;
  if (q1 > 10)
    quiz1 = 10;
  if (q2 < 0)
    quiz2 = 0;
  if (q2 > 10)
    quiz2 = 10;
  if (m < 0)
    m = 0;
  if (m > 100)
    m = 100;
  if (f < 0)
    f = 0;
  if (f > 100)
    f = 100;
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

char Record::overallGrade(double qwt, double mwt, double fwt) {
  double quizPct = (quiz1 / 10 + quiz2 / 10) / 2;
  double total = qwt + mwt + fwt;
  if (total != 1) {
    qwt = qwt / total;
    mwt = mwt / total;
    fwt = fwt / total;
  }
  double overall = qwt * 100 * quizPct + mwt * midterm + fwt * final;
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

void Record::setQuiz1(double score) {
  quiz1 = score;
}

void Record::setQuiz2(double score) {
  quiz2 = score;
}

void Record::setMidterm(double score) {
  midterm = score;
}

void Record::setFinal(double score) {
  final = score;
}
