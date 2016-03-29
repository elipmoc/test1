#include <list>
using namespace std;
#include "vegeclass.h"

//nCi���o�͂���֐�
double Vege::C(int n, int i){
	double p1 = 1, p2 = 1;
	for (int s = n; s > n-i; s--){
		p1*=s;
	}
	for (int s = i; s > 1; s--){
		p2*=s;
	}
	
	return p1/p2; 
}

//(a+b)��n���i�Ԗڂ����o��
double Vege::Pascal(double a,double b,int n,int i){

	double a2 = 1, b2 = 1;
	for (int s = n - i; s > 0; s--){
		a2 *= a;
	}
	for (int s = i; s > 0; s--){
		b2 *= b;
	}
	return a2*b2*C(n, i);
}

Point Vege::vegepoint(double time, list<Point*> &points){
	double x=0, y=0,f;
	int i = 0;
	for (list<Point*>::iterator it = points.begin(); it != points.end(); ++it){
		f = 0;
		f = Vege::instance()->Pascal(1 - time, time, points.size()-1,i);
		x += f*(*it)->x;
		y += f*(*it)->y;
		i++;
	}
	Point v(x, y);
	return v;
}