#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	int NOD(int n1, int n2)
	{
	  int div;
	  if (n1 == n2)  return n1;
	  int d = n1 - n2;
	  if (d < 0) {
		d = -d;  
		div = NOD(n1, d);
	  } 
	  else
		div = NOD(n2, d);
	  return div;
	}

	int NOK(int n1, int n2)
	{
	  return n1*n2 / NOD(n1, n2);
	}

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
    
    bool operator==(Fraction other)	{
		int nok = NOK(this->denominator_, other.denominator_);
		return ((this->numerator_ * nok / this->denominator_) == (other.numerator_ * nok / other.denominator_));
	}
	bool operator!=(Fraction other) { return !(*this == other);	}
	bool operator>(Fraction other) {
		int nok = NOK(this->denominator_, other.denominator_);
		return ((this->numerator_ * nok / this->denominator_) > (other.numerator_ * nok / other.denominator_));
	}
	bool operator<(Fraction other) 	{ return other > *this; }
	bool operator>=(Fraction other) { return !(*this < other); }
	bool operator<=(Fraction other) { return !(*this > other); }

};

int main()
{
	Fraction f1(1, 3);
	Fraction f2(3, 6);
	
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
        
	return 0;
}