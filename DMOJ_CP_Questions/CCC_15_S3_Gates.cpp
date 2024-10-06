#include <bits/stdc++.h>
using namespace std;
int main()
{
    int G, P;
    cin >> G >> P;
    int Planes[P];
    for(int i = 0; i < P; i++)
    {
        cin >> Planes[i];
    }
    bool Gates[G+1];

    for(int i = 0; i < G+1; i++)
    {
        Gates[i] = false;
    }

    int C = 0;


    for(int i = 0; i < P; i++)
    {
        bool found = false;
        for(int g = Planes[i]; g >= 1; g--)
        {
            if(Gates[g] == false) //occupied = false
            {
                Gates[g] = true;
                C++; //C += 1;
                found = true;
                break;
            }
        }
        if(found == false)
            break;
    }
    cout << C << endl;
    return 0;
}
