#include<iostream>
using namespace std; 
#define tab "\t"

class Point
{
	double x; //это переменные члены класса (позволяют отличить один объект от другого)
	double y; //это поля структоры
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
		x = y = double(); //значение по умолчанию для double
		//cout << "Constructor:\t" << this << endl; 
	}
	
	Point(double x)
	{
		this->x = x; 
		this->y = 0; 
		//cout << "1ArgConstructor:" << this << endl; 
	}
	Point (double x, double y)
	{
		this->x = x; 
		this->y= y; 
		//cout << "Constructor:\t" << this << endl; 
	}
	~Point()
	{
		//cout << "Destructor:\t" << this << endl;
	}
	
	//			Methods
	void print()const
	{
		cout << "X=" << x << "\tY="<< y << endl; 
	}
	double Distance_btw_points(double x2, double y2)const//передаем переменные
	{
		double result_distance;
		result_distance = sqrt(pow((x2 - this->x), 2) + pow((y2 - this->y), 2));
		return result_distance;
	}
	double Distance_btw_points(Point point)const//передаем другой Объект в метод этой точки
	{
		double result_distance;
		result_distance = sqrt(pow((point.get_x() - this->x), 2) + pow((point.get_y() - this->y), 2));
		return result_distance;
	}
};//создавая класс или структура

double Distance_btwn_points(double x1, double y1, double x2, double y2);

//#define STRUCT_POINT
//#define GET_SET

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP" << endl; 

#ifdef STRUCT_POINT
	int a;// объявление переменной а типа инт
	Point A; //объявление или создание переменной А, типа Point
			//объявление объекта А структоры Point
	A.x = 2.2;
	A.y = 3.4;
	//объявление экземпляра А структуры Point
	cout << A.x << tab << A.y << endl;
	Point* pA = &A; //указатель на А
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT_POINT

#ifdef GET_SET
	Point A;
	A.set_x(2);
	A.set_y(3);
	A.print();
#endif // GET_SET
	double x1, y1; 
	cout << "Введите координаты точки А X1= "; cin >> x1;
	cout << "Введите координаты точки А Y2= "; cin >> y1;
	Point A (x1, y1);
	//A.print();

	float x2, y2; 
	cout << "Введите координаты второй точки X2= "; cin >> x2;
	cout << "Введите координаты второй точки Y2= "; cin >> y2;
	Point B (x2, y2); 
	//B.print(); 

	//Point C(2, 3); //full argument constructor
	//C.print(); 

	cout << "Расстояние (от точки А)  до точки В (через передачу параметров) = "<<A.Distance_btw_points(B.get_x(), B.get_y()) << endl;
	cout << "Расстояние (от точки А)  до точки В (через передачу объекта) = "<<A.Distance_btw_points(B) << endl;
	cout << "Расстояние (от точки А)  до точки В (через функцию) = "<< Distance_btwn_points(A.get_x(), A.get_y(), B.get_x(), B.get_y()) << endl;
	
	/*double x1, x2, y1, y2; 
	cout << "Введите координаты первой точки X1= "; cin >> x1;
	cout << "Введите координаты первой точки Y1= "; cin >> y1;
	cout << "Введите координаты второй точки X2= "; cin >> x2;
	cout << "Введите координаты второй точки Y2= "; cin >> y2;
	cout << "Расстояние между точками = " << Distance_btwn_points(x1, y1, x2, y2) << endl;*/ 
}

double Distance_btwn_points(double x1, double y1, double x2, double y2)
{
	double result_distance;
	
	result_distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	return result_distance; 
}