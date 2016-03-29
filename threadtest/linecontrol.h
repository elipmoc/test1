class LineControl{
	list<Point*>points;
	Point* mausev;
	int px,py;
	int butan;
public:
	LineControl(){
			mausev = new Point(0, 0);
			points.push_back(mausev);
	}


	void main(){
		GetMousePoint(&px, &py);
		mausev->x = px;
		mausev->y = py;
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0){ butan+=1; }
		else { butan = 0;  }

		if (butan == 1){
			points.push_back(new Point(px,py));
		}
		for (list<Point*>::iterator it = points.begin(); it != points.end(); ++it){
			DrawCircle((*it)->x,(*it)->y,2,GetColor(255,0,0),true,true);
		}
		for (double i = 0; i <= 1; i += 0.001){
			Point v1 = Vege::instance()->vegepoint(i, points);
			Point v2 = Vege::instance()->vegepoint(i+0.001, points);
			DrawLine(v1.x, v1.y, v2.x, v2.y, GetColor(255, 255, 255), true);
		}

	
	}
};