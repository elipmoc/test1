
class Point{
public:
	double x;
	double y;
	Point(double xx, double yy){ x = xx, y = yy; }
};

class Vege{
	Vege(){}
	~Vege(){}
	double C(int, int);
	double Pascal(double,double,int,int);
public:
	static Vege* instance()
	{
		static Vege vege;
		return &vege;
	}

	Point vegepoint(double,list<Point*> &points);
};

