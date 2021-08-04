#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
int FibonacciNumberByRecursion(int n) {
    if (n <= 0) return -1;
    if (n == 1) return 0;
    if (n == 2) return 1;
    return FibonacciNumberByRecursion(n-2) + FibonacciNumberByRecursion(n-1);
}*/

/*
int FibonacciNumberByIterative(int n) {
    if (n <= 0) return -1;
    int a = 0, b = 1;
    if (n == 1) return a;
    for (int i = 3; i <= n; ++i) {
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    return b;
}*/

//Task 1
int find_shorted_path(int distances[5][5]) {
    int minimalPathDistance = INT_MAX;
    int firstCity = 0;
    for (int secondCity = 1; secondCity <= 4; ++secondCity) {
        for (int thirdCity = 1; thirdCity <= 4; ++thirdCity) {
            for (int fourthCity = 1; fourthCity <= 4; ++fourthCity) {
                for (int fifthCity = 1; fifthCity <= 4; ++fifthCity) {
                    int orderOfCities[5] = {firstCity, secondCity, thirdCity, fourthCity, fifthCity};
                    bool citiesAreAllDifferent = true;
                    for (int first = 0; first < 5; ++first) {
                        for (int second = first + 1; second < 5; ++second) {
                            if (orderOfCities[first] == orderOfCities[second]) {
                                citiesAreAllDifferent = false;
                                break;
                            }
                        }
                    }
                    if (!citiesAreAllDifferent) continue;
                    else {
                        int currentDistance = 0;
                        currentDistance += distances[firstCity][secondCity];
                        currentDistance += distances[secondCity][thirdCity];
                        currentDistance += distances[thirdCity][fourthCity];
                        currentDistance += distances[fourthCity][fifthCity];
                        currentDistance += distances[fifthCity][firstCity];
                        if (currentDistance < minimalPathDistance) {
                            minimalPathDistance = currentDistance;
                        }
                    }
                }
            }
        }
    }
    return minimalPathDistance;
}

//Task 2
int find_shorted_path_by_next_permutation(const vector<vector<int> >& graph, int startVertex = 0) {
    int minimumPath = INT_MAX;
    int amountOfVertexes = graph.size();
    vector<int> vertexes(amountOfVertexes-1);
    for (int i = 0; i < amountOfVertexes-1; ++i) {
        if (i == startVertex)
            vertexes[i] = amountOfVertexes - 1;
        else
            vertexes[i] = i;
    }
    sort(vertexes.begin(), vertexes.end());
    do {
        int currentDistance = graph[startVertex][vertexes[0]];
        for (int i = 1; i < amountOfVertexes-1; ++i) {
            currentDistance += graph[vertexes[i-1]][vertexes[i]];
        }
        currentDistance += graph[vertexes[amountOfVertexes - 2]][startVertex];
        if (currentDistance < minimumPath)
            minimumPath = currentDistance;
    } while (next_permutation(vertexes.begin(), vertexes.end()));
    return minimumPath;
}

int main() {
    /*auto t1 = chrono::high_resolution_clock::now();
    FibonacciNumberByRecursion(40);
    auto t2 = chrono::high_resolution_clock::now();
    auto durationOfFibonacciNumberByRecursion = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
    auto t3 = chrono::high_resolution_clock::now();
    FibonacciNumberByIterative(400000000);
    auto t4 = chrono::high_resolution_clock::now();
    auto durationOfFibonacciNumberByIterative = chrono::duration_cast<chrono::nanoseconds>(t4 - t3).count();
    cout << durationOfFibonacciNumberByRecursion << "\n" << durationOfFibonacciNumberByIterative << "\n";*/
    /*int ra = 0;
    int size = 10;
    int a[size];
    for (int i = 0; i < size; ++i) {
        a[i] = rand();
    }
    for (auto el : a) {
        cout << el << " ";
    }*/
    //the example from presentation
    int towns[5][5];
    int n;
    cin >> n;
    vector<vector<int> >cities(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cities[i][j];
            towns[i][j] = cities[i][j];
        }
    }
    cout << find_shorted_path(towns) << " " << find_shorted_path_by_next_permutation(cities);
    return 0;
}
