#include<iostream>
using namespace std; 
#define tab "\t"

#define COPY_CHECK

int Minimal_common_divider(int a, int b); //Copyright By EVKLID

class Fraction
{
	int integer; 
	int numerator; 
	int denominator; 
public:
	void set_integer(int integer)
	{
		this->integer = integer; 
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator; 
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator; 
	}
	int get_integer() const
	{
		return integer; 
	}
	int get_numerator() const
	{
		return numerator; 
	}
	int get_denominator() const
	{
		return denominator; 
	}
	//				CONSTRUCTORS
	Fraction(int integer = 0, int numerator = 0, int denominator = 0)
	{
		this->integer = integer; 
		this->numerator = numerator; 
		this->denominator = denominator; 
		cout << "construction_complete" << endl; 
	}
	Fraction(const Fraction& other)//COPY operator
	{
		 this->integer = other.integer;
		 this->numerator = other.numerator; 
		 this->denominator = other.denominator; 
		 cout << "Copy_DONE" << endl; 
	}
	~Fraction()
	{
		cout << "destruction_complete" << endl; 
	}
	//				METHODS
	void Print()
	{
		if (integer != 0 && numerator != denominator)cout << get_integer() << " " << get_numerator() << "/" << get_denominator() << endl;
		else if (numerator == denominator) cout << get_integer() << endl; 
		else cout << get_numerator() << "/" << get_denominator() << endl;;
	}
	void Integer_to_numerator()
	{
		numerator = integer * denominator + numerator; 
		this->integer = 0; 
	}
	void Integer_extractor()
	{
		if (integer == 0)
		{
			integer = numerator / denominator; 
			this->numerator = numerator - integer * denominator; 
		}
	}
	void Reduction()
	{
		int divider = Minimal_common_divider(this->numerator, this->denominator); 
		this->numerator = numerator / divider; 
		this->denominator = denominator / divider; 
	}
	void Inverse()
	{
		Integer_to_numerator();
		int buffer = 0; 
		buffer = numerator;
		this->numerator = denominator;
		this->denominator = buffer; 
	}
//					OPERATORS
	Fraction& operator = (const Fraction& other)//assignment operator
	{
		this->integer = other.integer;
		this->numerator = other.numerator; 
		this->denominator = other.denominator; 
		return *this; 
	}
};

Fraction operator*(const Fraction& left,  const Fraction& right)
{
	Fraction Left = left; 
	Fraction Right = right; 
	Left.Integer_to_numerator();
	Right.Integer_to_numerator();
	Fraction result;
	result.set_numerator(Left.get_numerator() * Right.get_numerator());
	result.set_denominator(Left.get_denominator() * Right.get_denominator());
	result.Integer_extractor();
	return result;
}
//Fraction operator/(const Fraction& left, const Fraction& right)
//{
//	Fraction Left = left;
//	Fraction Right = right;
//	Left.Integer_to_numerator();
//	Right.Integer_to_numerator();
//	Right.Inverse();
//	Fraction result;
//	result.set_numerator(Left.get_numerator() * Right.get_numerator());
//	result.set_denominator(Left.get_denominator() * Right.get_denominator());
//	//result.Integer_extractor();
//	return result;
//}

void main()
{
	setlocale(LC_ALL, ""); 

	Fraction A(1, 2, 3);
	A.Print();

#ifdef COPY_CHECK
	Fraction C = A;
	C.Print();
#endif // COPY_CHECK
	/*C.Integer_to_numerator(); 
	C.Print(); 
	C.Integer_extractor();
	C.Print(); 
	C.Reduction();
	C.Print();
	cout << Minimal_common_divider(11, 3) << endl; */
	/*C.Inverse(); 
	C.Print(); */
	/*Fraction D; 
	D = C; 
	D.Print(); */


}
int Minimal_common_divider(int a, int b)
{
	for (; ;)
	{
		if (a != 0 && b != 0)
		{
		if (a > b)
		{
			a = a % b;
		}
		else b = b % a;
		}
		else return a + b; 
	}
}//наименьший общий делитель