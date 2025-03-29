#include "iostream"

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
	Fraction() = default;
    
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

    std::string get_info()
    {
		return std::to_string(this->numerator_) + "/" + std::to_string(this->denominator_);
    }
	void reducing()
	{
		int nod = NOD(this->numerator_, this->denominator_);
		this->numerator_ /= nod;
		this->denominator_ /= nod;
	}

    // new 
    Fraction operator+(Fraction other) {
        int nok = NOK(this->denominator_, other.denominator_);
        return Fraction(((this->numerator_ * nok / this->denominator_) + (other.numerator_ * nok / other.denominator_)), nok);
    }
	Fraction operator-(Fraction other) {
        int nok = NOK(this->denominator_, other.denominator_);
        return Fraction(((this->numerator_ * nok / this->denominator_) - (other.numerator_ * nok / other.denominator_)), nok);
    }
	Fraction operator*(Fraction other) {
		Fraction tmp(this->numerator_ * other.numerator_, this->denominator_ * other.denominator_);
		tmp.reducing();
        return tmp;
    }
	Fraction operator/(Fraction other) {
		Fraction tmp(this->numerator_ * other.denominator_, this->denominator_ * other.numerator_);
		tmp.reducing();
        return tmp;
    }
	Fraction& operator++() {
		this->numerator_ += this->denominator_;
		return *this;
	}
	Fraction operator++(int) {
		Fraction tmp = *this;
		++(*this);
		return tmp;
	}
	Fraction& operator--() {
		this->numerator_ -= this->denominator_;
		return *this;
	}
	Fraction operator--(int) {
		Fraction tmp = *this;
		--(*this);
		return tmp;
	}

};

int main()
{
    int tmp_numerator, tmp_denominator;
    std::cout << "Enter first fraction numerator: ";
    std::cin >> tmp_numerator;
    std::cout << "Enter first fraction denominator: ";
    std::cin >> tmp_denominator;
    Fraction f1(tmp_numerator, tmp_denominator);
    std::cout << "Enter second fraction numerator: ";
    std::cin >> tmp_numerator;
    std::cout << "Enter second fraction denominator: ";
    std::cin >> tmp_denominator;
    Fraction f2(tmp_numerator, tmp_denominator);

	Fraction sec_tmp;

    Fraction tmp = f1 + f2;
    std::cout << f1.get_info() << " + " << f2.get_info() << " = " << tmp.get_info() << '\n';
	tmp = f1 - f2;
    std::cout << f1.get_info() << " - " << f2.get_info() << " = " << tmp.get_info() << '\n';
	tmp = f1 * f2;
    std::cout << f1.get_info() << " * " << f2.get_info() << " = " << tmp.get_info() << '\n';
	tmp = f1 / f2;
    std::cout << f1.get_info() << " / " << f2.get_info() << " = " << tmp.get_info() << '\n';
	sec_tmp = f1;
	tmp = ++f1 * f2;
    std::cout << "++" << sec_tmp.get_info() << " * " << f2.get_info() << " = " << tmp.get_info() << '\n';
	std::cout << "First fraction: " << f1.get_info() << '\n';
	sec_tmp = f1;
	tmp = f1-- * f2;
    std::cout << sec_tmp.get_info() << "-- / " << f2.get_info() << " = " << tmp.get_info() << '\n';
	std::cout << "First fraction: " << f1.get_info() << '\n';

    return 0;
}