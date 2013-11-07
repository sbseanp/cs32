#include <iostream>
#include "vec.h"
using namespace std;

// constructors done                                                            
Vec3::Vec3() : x(0), y(0), z(0) { }
Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) { }
/* Do not modify the following line. If you see the message "Pass by value      
   fail." in your output, it means you aren't using a reference somewhere       
   that you should be. */
Vec3::Vec3(const Vec3 &other) { cout << "Pass by value fail."; }

// getters and setters done                                                     
double Vec3::get_x() const { return x; }
double Vec3::get_y() const { return y; }
double Vec3::get_z() const { return z; }
void Vec3::set_x(double value) { x = value; }
void Vec3::set_y(double value) { y = value; }
void Vec3::set_z(double value) { z = value; }

// YOUR WORK GOES HERE                                                          
ostream& operator<<(ostream& output, const Vec3& obj) {
  output << "(" << obj.x << ", " << obj.y << ", " << obj.z << ")";
  return output;
}
istream& operator>>(istream& ins, Vec3& obj) {
  ins >> obj.x;
  ins >> obj.y;
  ins >> obj.z;
  return ins;
}
Vec3 operator+(const Vec3& obj1, const Vec3& obj2) {
  Vec3 newVec;
  newVec.x = obj1.x + obj2.x;
  newVec.y = obj1.y + obj2.y;
  newVec.z = obj1.z + obj2.z;
  return newVec;
}
Vec3 operator*(const Vec3& obj, double input) {
  Vec3 newVec;
  newVec.x = obj.x * input;
  newVec.y = obj.y * input;
  newVec.z = obj.z * input;
  return newVec;
}

Vec3& Vec3::operator+=(const Vec3& con) {
  this->x += con.x;
  this->y += con.y;
  this->z += con.z;
  return *this;
}

Vec3& Vec3::operator++() {
  this->x += 1;
  this->y += 1;
  this->z += 1;
  return *this;
}

Vec3 Vec3::operator++(int one) {
  Vec3 temp;
  temp.x = this->x;
  temp.y = this->y;
  temp.z = this->z;
  operator++();
  return temp;
}

double& Vec3::operator[](int index) {
  if (index == 0)
    return this->x;
  if (index == 1)
    return this->y;
  else
    return this->z;
}

double Vec3::operator[](int index) const{
  if (index == 0)
    return this->x;
  if (index == 1)
    return this->y;
  else
    return this->z;
}
