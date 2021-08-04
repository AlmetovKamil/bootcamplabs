#include <iostream>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int factorialByRecursion(int n) {
    if (n <= 0) return -1;
    if (n == 1) return 1;
    return factorialByRecursion(n - 1) * n;
}

int factorialByIteration(int n) {
    if (n <= 0) return -1;
    int f = 1;
    for (int i = 1; i <= n; ++i) {
        f *= i;
    }
    return f;
}

//Task 2
int FibonacciNumberByRecursion(int n) {
    if (n <= 0) return -1;
    if (n == 1) return 0;
    if (n == 2) return 1;
    return FibonacciNumberByRecursion(n-2) + FibonacciNumberByRecursion(n-1);
}

//Task 1
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
}

int main() {
    /*int n;
    cin >> n;
    cout << "Is n a prime: " << isPrime(n) << "\n";
    cout << "n! == " << factorialByRecursion(n) << "\n";
    cout << "n! == " << factorialByIteration(n) << "\n";*/
    /*int i = 1;
    while (isPrime(i) == isPrime((1 << i) - 1)) i++;
    cout << i;*/
    /*for (int i = 1; i < 50; ++i) {
        cout << FibonacciNumberByRecursion(i) << " " << FibonacciNumberByIterative(i) << "\n";
    }*/
    //Extra Task
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j =- 0; j < n; ++j) {
            a[i][j] = 0;
        }

    }
    int k = n*n;
    int q = 1;
    int i = 0, j = 0;
    while (k > 0) {

        while (i < n && a[i][j] == 0) {
            a[i][j] = q;
            q++;
            k--;
            if (i < n-1 && a[i+1][j] == 0) i++;
        }
        j++;
        while (j < n && a[i][j] == 0) {
            a[i][j] = q;
            q++;
            k--;
            if (j < n-1 && a[i][j+1] == 0) j++;
        }
        i--;
        while (i >= 0 && a[i][j] == 0) {
            a[i][j] = q;
            q++;
            k--;
            if (i > 0 && a[i-1][j] == 0) i--;
        }
        j--;
        while (j >= 0 && a[i][j] == 0) {
            a[i][j] = q;
            q++;
            k--;
            if (j > 0 && a[i][j-1] == 0) j--;
        }
        i++;
    }


    for (int i = 0; i < n; ++i) {
        for (int j =- 0; j < n; ++j) {
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
