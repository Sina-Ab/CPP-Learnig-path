#include <cstdlib>
#include <iostream>
#include <cmath>


int gcd(int a,int b){
    if(b==0){return std::abs(a);}
    else{return gcd(b, a%b);}
}


class Fraction{
private:
    int m_numerator{0};
    int m_denominator{1};
public:
    explicit Fraction(int numerator,int denominator=1):
    m_numerator{numerator}, m_denominator{denominator}{
        reduce();
    }

    void print(){
        std::cout << m_numerator <<"/"<< m_denominator << "\n";
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
};




int main(){
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}
