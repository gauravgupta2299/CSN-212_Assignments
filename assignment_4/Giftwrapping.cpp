#include <iostream>
#include <limits.h>
using namespace std;

struct Point
{
        float x;
        float y;
};
 
int findOrientation(Point a, Point b, Point c)
{
    float sintheta = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);//cross product
 
    if (sintheta == 0)
        return 0; // colinear
    return (sintheta > 0) ? 1 : 2; // clockwise or counterclock wise
}
 
void convexHull(Point points[], int n)
{
    if (n < 3)
        return;

    float result[n];
    for (int i = 0; i < n; i++)
        result[i] = -1;
 
    // Find the leftmost point
    int left = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[left].x)
            left = i;
 
    int p = left, q;
    do
    {
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (findOrientation(points[p], points[i], points[q]) == 2)
                q = i;
 
        result[p] = q;
        p = q;
    }while (p != left);
 
    for (int i = 0; i < n; i++)
    {
        if (result[i] != -1){
            //cout << "(" << points[i].x << ", " << points[i].y << ")\n";
        }
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
          //  cout<<points[i].x<<" "<<points[i].y<<i<<" ";

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