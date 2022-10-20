#include<iostream>
using namespace std; 
#define tab "\t"


//создава€ класс или структура
class Point
{
	double x; //это переменные члены класса (позвол€ют отличить один объект от другого)
	double y; //это пол€ структоры
public:
	double get_x()const
	{
		return x; 
	}
	double get_y()const
	{
		return y; 
	}
	void set_x(double x)
	{
		this->x = x; 
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//			Constructors:
	Point()
	{
		x = y = double(); //значение по умолчанию дл€ double
		cout << "Constructor:\t" << this << endl; 
	}
	
	Point(double x)
	{
		this->x = x; 
		this->y = 0; 
		cout << "1ArgConstructor:" << this << endl; 
	}
	Point (double x, double y)
	{
		this->x = x; 
		this->y= y; 
		cout << "Constructor:\t" << this << endl; 
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	
	//			Methods
	void print()const
	{
		cout << "X=" << x << "\tY="<< y << endl; 
	}
};


//#define STRUCT_POINT
//#define GET_SET

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP" << endl; 
#ifdef STRUCT_POINT
	int a;// объ€вление переменной а типа инт
	Point A; //объ€вление или создание переменной ј, типа Point
			//объ€вление объекта ј структоры Point
	A.x = 2.2;
	A.y = 3.4;
	//объ€вление экземпл€ра ј структуры Point
	cout << A.x << tab << A.y << endl;
	Point* pA = &A; //указатель на ј
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT_POINT

#ifdef GET_SET
	Point A;
	A.set_x(2);
	A.set_y(3);
	A.print();
#endif // GET_SET

	Point A;
	A.print();

	Point B=5; //single argument constructor
	B.print(); 

	Point C(2, 3); //full argument constructor
	C.print(); 
}