#include <iostream>

using namespace std;


class ThirdDimension 
{
private:
	double hloubka;
public:
	ThirdDimension(double _hloubka)
	{
		hloubka = _hloubka;
	}
	virtual double GetVolume()
	{
		return 0;
	}
	double GetHloubka()
	{
		return hloubka;
	}
	
};

class Shape : public ThirdDimension
{
private:
	double _sirka;
	double _vyska;
public:
	Shape(double sirka, double vyska,double hloubka) : ThirdDimension(hloubka)
	{
		_sirka = sirka;
		_vyska = vyska;
	}
	double GetSirka()
	{
		return _sirka;
	}
	double GetVyska()
	{
		return _vyska;
	}
	virtual double GetArea()
	{
		return 2;
	}
};


class Shapes
{
private:
	ThirdDimension** collection;
	int count;
public:
	Shapes()
	{
		collection = (ThirdDimension * *)malloc(sizeof(ThirdDimension) * 10);
		count = 0;
	}
	void addShape(Shape* sh1)
	{
		collection[count] = sh1;
		count++;
	}
	void SortArr()
	{
		//double tmp_value;
		double checker = 0;
		//Shapes** tmp_shapes = (Shapes**)malloc(sizeof(Shapes) * 10);
		ThirdDimension* tmp_shape;


		for (int i = 0; i < count - 1; i++)
		{
			for (int j = 0; j < count - i - 1; j++)
			{
				if (collection[j + 1]->GetVolume() < collection[j]->GetVolume())
				{
					tmp_shape = collection[j + 1];
					collection[j + 1] = collection[j];
					collection[j] = tmp_shape;
				}
			}
		}

	}

	ThirdDimension* GetShape(int idx)
	{
		return collection[idx];
	}

	void PrintArr()
	{
		for (int a = 0; a < count; a++)
		{
			cout << GetShape(a)->GetVolume() << " ";
		}
	}

};



class Rectangle :public Shape
{
public:
	Rectangle(double sirka, double vyska,double hloubka) : Shape(sirka, vyska,hloubka)
	{

	}
	double GetArea()
	{
		double value = GetSirka() * GetSirka();
		return value;
	}
	double GetVolume()
	{
		return GetSirka() * GetVyska() * GetHloubka();
	}
};


class Circle :public Shape
{
public:
	Circle(int prumer) :Shape(prumer,prumer,prumer)
	{

	}
	double GetArea()
	{
		double value = (3.14 * (GetVyska() * GetVyska())) / 4;
		return value;
	}
	double GetVolume()
	{
		return GetSirka() * GetVyska() * GetHloubka();
	}

};


int main()
{

	Shapes* sh1 = new Shapes();

	Circle* cr1 = new Circle(5);
	Rectangle* rc1 = new Rectangle(10, 5,3);
	sh1->addShape(rc1);
	sh1->addShape(cr1);
	
	sh1->PrintArr();
	sh1->SortArr();
	sh1->PrintArr();




	return 1;
}
