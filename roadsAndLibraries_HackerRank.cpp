/* 	Problem description on HackerRank (https://www.hackerrank.com/john_huynhhc).
*	Solved by John Huynh

Determine the minimum cost to provide library access to all citizens in 
different cities, considering costs to build roads and libraries. Cities 
can/cannot be connected by bidirectional roads.

Sample Input
STDIN       Function
-----       --------
2           q = 2
3 3 2 1     n = 3, cities[] size m = 3, c_lib = 2, c_road = 1
1 2         cities = [[1, 2], [3, 1], [2, 3]]
3 1
2 3
6 6 2 5     n = 6, cities[] size m = 6, c_lib = 2, c_road = 5
1 3         cities = [[1, 3], [3, 4],...]
3 4
2 4
1 2
2 3
5 6

Sample Output
4
12

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <stack>

using std::cout;
using std::endl;
using std::unordered_map;
using std::unordered_set;
using std::queue;
using std::ofstream;
using std::stack;

long roadsAndLibraries(int n, long c_lib, long c_road, vector<vector<int>> cities) {
    if (c_lib <= c_road) {
        return c_lib * n;
    }
    unordered_map<long long, unordered_set<long long>> adj;
    unordered_set<long long> ccCount;
    long long roads = 0;
    long long libraries = 0;
    long long cost = 0;
    stack<long long> s;
    long long current = 0;
    for (auto const& connected : cities) {
        if (connected[0] != connected[1]) {
            adj[connected[0]].insert(connected[1]);
            adj[connected[1]].insert(connected[0]);
        }
    }
    //for (int i = 1; i <= n; i++) {
    long long count = 0;
    for (auto const city : adj) {
        if (ccCount.count(city.first) == 0) {
            cout << "city: " << city.first << endl;
            stack<long long> s;
            s.push(city.first);
            ccCount.insert(city.first);
            //count = 0;
            count = 1;
            while (!s.empty()) {
                current = s.top();
                s.pop();
                //count += 1;
                for (auto const& neighbor : adj[current]) {
                    if (ccCount.count(neighbor) == 0) {
                        s.push(neighbor);
                        ccCount.insert(neighbor);
                        count += 1;
                    }
                }
            }
            //roads += count - 1;
            //libraries += 1;
            cost += (count - 1) * c_road;
            cost += c_lib;
        }
    }
    long long addition = 0;
    if (ccCount.size() < n) {
        addition = n - ccCount.size();
    }
    cost += addition * c_lib;
    //cost = (long long)roads * c_road + (long long)(libraries + addition) * c_lib;
    return cost;
}



