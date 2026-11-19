#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ostream>


int gcd(int a,int b){
    if(b==0){return std::abs(a);}
    else{return gcd(b, a%b);}
}


class Fraction{
private:
    int m_numerator{0};
    int m_denominator{1};
public:
    explicit Fraction(int numerator=0,int denominator=1):
    m_numerator{numerator}, m_denominator{denominator}{
        reduce();
    }

    void reduce(){
        int gcd_result{gcd(m_numerator,m_denominator)};
        m_numerator = m_numerator / gcd_result;
        m_denominator = m_denominator / gcd_result;
    }


    friend Fraction operator*(const Fraction& f1, const Fraction& f2){
        return Fraction{f1.m_numerator * f2.m_numerator,f1.m_denominator * f2.m_denominator};
    }

    friend Fraction operator*(const Fraction& f, int value){
        return Fraction{f.m_numerator * value,f.m_denominator};
    }

    friend Fraction operator*(int value, const Fraction& f){
        return f * value;
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f){
        out << f.m_numerator <<"/"<< f.m_denominator;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Fraction& f){
        int numerator{};
        char fraction_char{};
        int denominator{};
        in >> numerator >> fraction_char >> denominator;
        if(denominator == 0){in.setstate(std::ios_base::failbit);}
        if(in){f = Fraction{numerator,denominator};}
        return in;
    }

};




int main(){
    Fraction f1{};
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2{};
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

    return 0;
}
