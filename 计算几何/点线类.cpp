#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
double EPS=1e-8;
//误差判断
int sgn(double x){
	return (x>EPS)-(x<-EPS);
}
//二维向量结构体
struct point{
	double x,y;
	point(){}
	point(double xx,double yy):x(xx),y(yy){}
	point operator + (point p){
		return point(x+p.x,y+p.y);
	}
	point operator - (point p){
		return point(x-p.x,y-p.y);
	}
	point operator * (double d){
		return point(x*d,y*d);
	}
	double dot(point p){//内积
		return x*p.x+y*p.y;
	}
	double det(point p){//外积，叉乘
		return x*p.y-y*p.x;
	}
	bool on_segment(point p0,point p1){//判断点是不是在线段p1，p2之间
		if((min(p0.x,p1.x)<=x && x<=max(p0.x,p1.x)) && (min(p0.y,p1.y)<=y && y<=max(p0.y,p1.y)))
			return true;
		return false;
	}
};
struct line{
	point a,b;
	line(){}
	line(const point &a,const point &b):a(a),b(b){}
	bool OnSegment(point p){//判断点p是不是在线段上
		return sgn((a-p).det(b-p))==0&&sgn((a-p).dot(b-p))<=0;
	}
	point Intersection(line &l){//求两直线的交点
		return a+(b-a)*((l.b-l.a).det(l.a-a)/(l.b-l.a).det(b-a));
	}
	bool Segment_intersect(line l){//判断两线段是否相交
		double d1,d2,d3,d4;
		d1=(a-l.a).det(l.b-l.a);
		d2=(b-l.a).det(l.b-l.a);
		d3 = (l.a-a).det(b-a);;
		d4 = (l.b-a).det(b-a);
		if(((d1>0 && d2<0)||(d1<0 && d2>0)) && ((d3>0 && d4<0)||(d3<0&&d4>0)))
			return true;
		else if(d1==0 && a.on_segment(l.a,l.b))
			return true;
		else if(d2==0 && b.on_segment(l.a,l.b))
			return true;
		else if(d3==0 && l.a.on_segment(a,b))
			return true;
		else if(d4==0 && l.b.on_segment(a,b))
			return true;
		return false;
	}
};
//判断点p是不是在线段p1,p2上
bool On_seg(point p1,point p2,point p)
{
	return sgn((p1-p).det(p2-p))==0&&sgn((p1-p).dot(p2-p))<=0;
}
//求直线p1,p2,q1,q2的交点
point Intersection(point p1,point p2,point q1,point q2)
{
	return p1+(p2-p1)*((q2-q1).det(q1-p1)/(q2-q1).det(p2-p1));
}