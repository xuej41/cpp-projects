#include <bits/stdc++.h>

using namespace std;

int main(){

    int friends ;
    int smallest=100000, biggest =0, location, distance, time =0;

    cin >> friends ;

    int position[friends], speed[friends], hearing[friends] ;

    for (int i =0; i <friends; i++){
        cin >> position[i] >> speed[i] >> hearing[i] ;
        if (position[i]> biggest){
            biggest = position[i] ;

        }
        if (position[i]< smallest){
            smallest = position[i] ;
        }
    }


    int mintime =10000 ;

    for (int x = smallest; x <= biggest; x++){
        location = x ;
        time =0;
        for (int i =0; i <friends; i++){
            distance = abs(location - position[i]);
            if (distance > hearing[i]){
                time += (distance - hearing[i]) * speed[i] ;
            }
        }
        if (time < mintime){
            mintime = time;
        }
    }
    cout << mintime;

    return 0 ;
}
