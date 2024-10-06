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
    const int GATE_COUNT = 100001;
    bitset<GATE_COUNT> open;
    open.set();
    bool Gates[G+1];

    for(int i = 0; i < G+1; i++)
    {
        Gates[i] = false;
    }

    int C = 0;


    for(int i = 0; i < P; i++)
    {
        int found = open._Find_next(GATE_COUNT-Planes[i]-1);
        if (found >= GATE_COUNT)
            break;
        open.reset(found);
        C++;
        /*
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
        */
    }
    cout << C << endl;
    return 0;
}
