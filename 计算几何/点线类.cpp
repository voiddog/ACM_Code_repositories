#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
double EPS=1e-8;
//误差判断
int sgn(double x)
{
	return (x>EPS)-(x<-EPS);
}
//二维向量结构体
struct point
{
        double x,y;
        point(){}
        point(double xx,double yy):x(xx),y(yy){}
        point operator + (point p)
        {
                return point(x+p.x,y+p.y);
        }
        point operator - (point p)
        {
                return point(x-p.x,y-p.y);
        }
        point operator * (double d)
        {
                return point(x*d,y*d);
        }
        double dot(point p)//内积
        {
                return x*p.x+y*p.y;
        }
        double det(point p)//外积，叉乘
        {
                return x*p.y-y*p.x;
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