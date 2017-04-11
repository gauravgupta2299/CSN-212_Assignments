#include <bits/stdc++.h>
#include <vector>
 using namespace std;

struct Point{
    float x;
    float y;
};
int findOrientation(Point A, Point B, Point P)
{
    float sintheta = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
    if (sintheta > 0)
        return 1;
    return sintheta==0?0:-1;
}

void hullSet(Point A, Point B, vector<Point> &set,
        vector<Point> &hull); 
vector<Point> quickHull(vector<Point> points)
{
    vector<Point> result;
    if (points.size() < 3)
        return result;

    int leftPoint = -1,rightPoint = -1;
    float minX = 1.0*INT_MAX;
    float maxX = 1.0*INT_MIN;
    for (int i = 0; i < points.size(); i++)
    {
        if (points[i].x < minX)
        {
            minX = points[i].x;
            leftPoint = i;
        }
        if (points[i].x > maxX)
        {
            maxX = points[i].x;
            rightPoint = i;
        }
    }
    Point A = points[leftPoint];
    Point B = points[rightPoint];
    result.push_back(A);
    result.push_back(B);
    points.erase(points.begin()+leftPoint);
    points.erase(points.begin()+rightPoint);

    vector<Point> leftSet;
    vector<Point> rightSet;

    for (int i = 0; i < points.size(); i++)
    {
        Point p = points[i];
        if (findOrientation(A, B, p) == -1)
            leftSet.push_back(p);
        else if (findOrientation(A, B, p) == 1)
            rightSet.push_back(p);
    }
    hullSet(A, B, rightSet, result);
    hullSet(B, A, leftSet, result);

    return result;
}
 float distance(Point A, Point B, Point C)
{
    float vx = B.x - A.x;
    float vy = B.y - A.y;
    float val = vx * (A.y - C.y) - vy * (A.x - C.x);
    if (val < 0)
        val = -val;
    return val;
}

void hullSet(Point A, Point B, vector<Point> &set,
        vector<Point> &hull)
{   auto insertPosition = find_if(hull.begin(), hull.end(), [B](const Point& C){return (C.x == B.x && C.y==B.y);})-hull.begin();
    if (set.size() == 0)
        return;
    if (set.size() == 1)
    {
        Point p = set[0];
        set.erase(set.begin());
        hull.insert(hull.begin()+insertPosition,p);
        return;
    }
    float dist = 1.0*INT_MIN;
    int furthestPoint = -1;
    for (int i = 0; i < set.size(); i++)
    {
        Point p = set[i];
        float distan = distance(A, B, p);
        if (distan > dist)
        {
            dist = distan;
            furthestPoint = i;
        }
    }
    Point P = set[furthestPoint];
    set.erase(set.begin()+furthestPoint);
    hull.insert(hull.begin()+insertPosition, P);


    vector<Point> leftSetAP;
    for (int i = 0; i < set.size(); i++)
    {
        Point M = set[i];
        if (findOrientation(A, P, M) == 1)
        {
            leftSetAP.push_back(M);
        }
    }


    vector<Point> leftSetPB;
    for (int i = 0; i < set.size(); i++)
    {
        Point M = set[i];
        if (findOrientation(P, B, M) == 1)
        {
            leftSetPB.push_back(M);
        }
    }
    hullSet(A, P, leftSetAP, hull);
    hullSet(P, B, leftSetPB, hull);

}



 
int main()
{   int t;float x;float y;int n;
    cin>>t;
    while(t!=0){
        cin>>n;
        vector<Point> points(n);
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
    vector<Point> res=quickHull(points);
    cout <<(n)<<" "<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds. " <<res.size()<< endl;
        t--;

    }
return 0;
}