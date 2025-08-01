#include <iostream>
using namespace std;
class Fraction
{
private:
    int numerator_;
    int denominator_;

    // Своя реализация алгоритма Евклида для НОД
    static int gcd(int a, int b)
    {
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce()
    {
        int divisor = gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
        if (denominator_ < 0)
        {
            denominator_ = -denominator_;
            numerator_ = -numerator_;
        }
    }

public:
    Fraction(int numerator = 0, int denominator = 1)
        : numerator_(numerator), denominator_(denominator)
    {
        if (denominator_ == 0)
        {
            cout << "Знаменатель не может быть 0, установка в 1\n";
            denominator_ = 1;
        }
        reduce();
    }

    friend ostream& operator<<(ostream& os, const Fraction& f)
    {
        os << f.numerator_ << '/' << f.denominator_;
        return os;
    }

    bool operator==(const Fraction& other) const
    {
        return numerator_ == other.numerator_ && denominator_ == other.denominator_;
    }
    bool operator!=(const Fraction& other) const { return !(*this == other); }
    bool operator<(const Fraction& other) const
    {
        return (numerator_ * other.denominator_) < (other.numerator_ * denominator_);
    }
    bool operator>(const Fraction& other) const { return other < *this; }
    bool operator<=(const Fraction& other) const { return !(*this > other); }
    bool operator>=(const Fraction& other) const { return !(*this < other); }

    Fraction operator+(const Fraction& other) const
    {
        return Fraction(numerator_ * other.denominator_ + other.numerator_ * denominator_, denominator_ * other.denominator_);
    }

    Fraction operator-(const Fraction& other) const
    {
        return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_, denominator_ * other.denominator_);
    }

    Fraction operator*(const Fraction& other) const
    {
        return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Fraction operator/(const Fraction& other) const
    {
        return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
    }

    Fraction operator-() const
    {
        return Fraction(-numerator_, denominator_);
    }

    Fraction& operator++()
    {
        numerator_ += denominator_;
        reduce();
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& operator--()
    {
        numerator_ -= denominator_;
        reduce();
        return *this;
    }

    Fraction operator--(int)
    {
        Fraction temp = *this;
        --(*this);
        return temp;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int n1, d1, n2, d2;
    cout << "Введите числитель дроби 1: ";
    cin >> n1;
    cout << "Введите знаменатель дроби 1: ";
    cin >> d1;

    cout << "Введите числитель дроби 2: ";
    cin >> n2;
    cout << "Введите знаменатель дроби 2: ";
    cin >> d2;

    Fraction f1(n1, d1);
    Fraction f2(n2, d2);

    cout << f1 << " + " << f2 << " = " << (f1 + f2) << '\n';
    cout << f1 << " - " << f2 << " = " << (f1 - f2) << '\n';
    cout << f1 << " * " << f2 << " = " << (f1 * f2) << '\n';
    cout << f1 << " / " << f2 << " = " << (f1 / f2) << '\n';

    cout << "++" << f1 << " * " << f2 << " = " << (++f1 * f2) << '\n';
    cout << "Значение дроби 1 = " << f1 << '\n';

    cout << f1 << "-- * " << f2 << " = " << (f1-- * f2) << '\n';
    cout << "Значение дроби 1 = " << f1 << '\n';


    return 0;
}