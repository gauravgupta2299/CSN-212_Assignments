#include <iostream>
#include <stack>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
using namespace std;
 
struct Point
{
        float x;
        float y;
};
 
Point p0;
 
Point find2ndfromTop(stack<Point> &P)
{
    Point p = P.top();
    P.pop();
    Point ans = P.top();
    P.push(p);
    return ans;
}
 
int findOrientation(Point p, Point q, Point r)
{
    float sintheta = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (sintheta == 0)
        return 0; // collinear
    return (sintheta > 0) ? 1 : 2; // clockwise otherwise counterclock wise
}
 
int comparator(const void* cp1, const void* cp2)
{   
    Point *p1 = (Point *) cp1;
    Point *p2 = (Point *) cp2;
    int orient = findOrientation(p0, *p1, *p2);
    if (orient == 0)
        return ((pow(p0.x-(*p2).x,2)+pow(p0.y-(*p2).y,2))) >= (pow(p0.x-(*p1).x,2)+pow(p0.y-(*p1).y,2)) ? -1 : 1;
 
    return (orient == 2) ? -1 : 1;
}
 
void convexHull(Point points[], int n)
{
   
    float ylowest = points[0].y;int lowest = 0;
    for (int i = 1; i < n; i++)
    {
        float y = points[i].y;
 
        if ((y < ylowest) || (ylowest == y && points[i].x < points[lowest].x))
            ylowest = points[i].y, lowest = i;
    }
 
    Point temp = points[0];
    points[0] = points[lowest];
    points[lowest] = temp;
 
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), comparator);
    int z = 1; 
    for (int i=1; i<n; i++)
    {
        while (i < n-1 && findOrientation(p0, points[i],points[i+1]) == 0)i++;

        points[z] = points[i];
        z++; 
    }
    if (z < 3) return;

    stack<Point> P;
    P.push(points[0]);
    P.push(points[1]);
    P.push(points[2]);
 

    for (int i = 3; i < z; i++)
    {
        while (findOrientation(find2ndfromTop(P), P.top(), points[i]) != 2)
            P.pop();
        P.push(points[i]);
    }
 
    while (!P.empty())
    {
        Point p = P.top();
       // cout << p.x << " " << p.y<< endl;
        P.pop();
    }
}
 
int main()
{   int t;float x;float y;int n;
    cin>>t;
    while(t!=0){
        cin>>n;
        Point *points=new Point[n];
        for(int i=0;i<n;i++){
            cin>>x>>y;
            //cout<<x<<" "<<y;
            points[i].x=x;
            points[i].y=y;
           // cout<<points[i].x<<" "<<points[i].y<<i<<" ";

        }
       // cout<<"hi";
    clock_t startTime = clock();
  //  cout<<"Case #"<<t<<endl;
    convexHull(points, n);
    cout <<(n)<<" "<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        t--;

    }
return 0;
}