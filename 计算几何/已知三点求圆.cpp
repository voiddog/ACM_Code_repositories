void getR()//三点p[3],结果保存在x,y,r
{
    double a,b,c,d,e,f;
    a=2*(p[1].x-p[0].x);  
    b=2*(p[1].y-p[0].y);  
    c=p[1].x*p[1].x+p[1].y*p[1].y-p[0].x*p[0].x-p[0].y*p[0].y;  
    d=2*(p[2].x-p[1].x);  
    e=2*(p[2].y-p[1].y);  
    f=p[2].x*p[2].x+p[2].y*p[2].y-p[1].x*p[1].x-p[1].y*p[1].y;  
    x=(b*f-e*c)/(b*d-e*a);  
    y=(d*c-a*f)/(b*d-e*a);  
    r=sqrt((x-p[0].x)*(x-p[0].x)+(y-p[0].y)*(y-p[0].y));  
}
