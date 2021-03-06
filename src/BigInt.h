#ifndef BIGINT_H
#define BIGINT_H

#include <cstdlib> // for std::exit
#include <iostream>
#include <string>
#include <sstream>

// this will maintain compatibility with some compilers
template <typename T>
std::string to_string(T n)
{
  std::ostringstream s;
  s << n;
  return s.str();
}

using namespace std;

struct DivData
{
  int divisions;
  int remainder;
};

class BigInt
{
public:
  BigInt();
  BigInt(int x);
  explicit BigInt(string x);

  friend ostream& operator<<(ostream& out, const BigInt& right);
  friend bool operator<(const BigInt& left, const BigInt& right);
  friend bool operator>(const BigInt& left, const BigInt& right);
  friend bool operator==(const BigInt& left, const BigInt& right);
  BigInt operator+(const BigInt& right);
  BigInt operator-(const BigInt& right);
  BigInt operator*(const BigInt& right);
  BigInt operator/(const BigInt& right);
  BigInt operator%(const BigInt& right);

private:
  string data;
  bool isNegative;

  void makeLengthsEqual(string& a, string& b);
  void removeLeadingZeroes(string& str);

  string sum(string left, string right);
  string difference(string left, string right);

  string singleDigitProduct(char left, char right) { return to_string((left - '0') * (right - '0')); }

  int charToInt(char c) { return c - '0'; }
  char intToChar(int n) { return n + '0'; }

  int numberOfDivisions(const string& numerator, const string& denominator);
  BigInt remainderOfDivision(const string& numerator, const string& denominator);
};

#endif