/*
CCC_2021_S1_Crazy_Fence.py
Joshua Xue
*/


#include <iostream>
#include <vector>

using namespace std;


main() {

int N;
cin >> N;

int h[N + 1];
int w[N];

for (int i = 0; i < N + 1; i++){
    cin >> h[i];
}
//cout << "after reading h";
for (int i = 0; i < N; i++){
    cin >> w[i];
}

//cout << "after reading";
double total = 0.0;
double a;

for (int i = 0; i < N; i++){
    a = ((double)((h[i] + h[i + 1]) * w[i]))/2.0;
    total += a;
}

cout << total;

}

//print (N, h, w)
/*
Input Specication
The rst line of the input will be a positive integer N, where N  10 000.
The second line of input will contain N + 1 space-separated integers h1; : : : ; hN+1 (1  hi 
100, 1  i  N + 1) describing the left and right heights of each piece of wood. Specically,
the left height of the ith piece of wood is hi and the right height of the ith piece of wood is
hi+1.
The third line of input will contain N space-separated integers wi (1  wi  100, 1  i  N)
describing the width of the ith piece of wood.
Output Specication
Output the total area of the fence.
Sample Input 1
3
2 3 6 2
4 1 1
Output for Sample Input 1
18.5
Explanation of Output for Sample Input 1
La version francaise gure a la suite de la version anglaise.
The fence looks like the following:
2
3
4
6
1
2
1
When looking from left to right, the individual areas of the pieces of wood are 10 = 4(2+3)=2,
4:5 = 1  (3 + 6)=2, and 4 = 1  (6 + 2)=2, for a total area of 18.5.
*/
