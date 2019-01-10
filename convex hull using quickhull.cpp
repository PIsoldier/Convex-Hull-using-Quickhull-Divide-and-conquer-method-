
#include<bits/stdc++.h>
#define LL long long
using namespace std;
typedef pair<int, int> PII;
set<PII> s;

int direction(PII point_1, PII point_2, PII point_0 )
{
    LL x, x1, x2, y, y1, y2, sign;
    x = point_0.second;
    x1 = point_1.second;
    x2 = point_2.second;

    y = point_0.first;
    y1 = point_1.first;
    y2 = point_2.first;

    sign = (x - x1) * (y2 - y1) - (x2 - x1) * (y - y1);

    if (sign > 0)
        return 1;
    else if (sign < 0)
        return -1;
    return 0;
}

int straight_line_dist(PII point_1, PII point_2, PII point_0)
{
    LL x, x1, x2, y, y1, y2, sign;
    x = point_0.second;
    x1 = point_1.second;
    x2 = point_2.second;

    y = point_0.first;
    y1 = point_1.first;
    y2 = point_2.first;

    sign = (x - x1) * (y2 - y1) - (x2 - x1) * (y - y1);

    return abs(sign);
}

void quicks(PII a[], int n, PII point_1, PII point_2, LL side)
{
    int p = -1;
    int max_dist = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = straight_line_dist(point_1, point_2, a[i]);
        if (direction(point_1, point_2, a[i]) == side && temp > max_dist)
        {
            p = i;
            max_dist = temp;
        }
    }

    if (p == -1)
    {
        s.insert(point_1);
        s.insert(point_2);
        return;
    }
    quicks(a, n, a[p], point_1, -direction(a[p], point_1, point_2));
    quicks(a, n, a[p], point_2, -direction(a[p], point_2, point_1));
}

void Convex(PII a[], LL n)
{
    int min_x = 0, max_x = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i].first < a[min_x].first)
            min_x = i;
        if (a[i].first > a[max_x].first)
            max_x = i;
    }
    quicks(a, n, a[min_x], a[max_x], 1);
    quicks(a, n, a[min_x], a[max_x], -1);
}
int main()
{
   // freopen("input.txt", "r", stdin);
    LL n;
    cout << "Enter the number of co-ordinates\n";
    cin >> n;
    if (n < 3)
    {
        cout << "Convex s not possible\n";
    }
    PII arr[n];
    cout << "Enter the co-ordinates values\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    Convex(arr, n);

    cout << "The points in maximum distance are:\n";
    while (!s.empty())
    {
        cout << "{" <<( *s.begin()).first << ", "
             << (*s.begin()).second << "}, ";
        s.erase(s.begin());
    }

}

