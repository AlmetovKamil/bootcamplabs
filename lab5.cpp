#include <iostream>
#include <vector>
//matrices
//works only with square matrices

using namespace std;

void input_matrix(vector<vector<int>>& a) {
    for (auto & i : a) {
        for (int & j : i) {
            cin >> j;
        }
    }
}

void print_matrix(vector<vector<int>>& a) {
    for (auto & i : a) {
        for (int & j : i) {
            cout << j << "\t";
        }
        cout << "\n";
    }
}

vector<vector<int>> summarize_matrices(vector<vector<int>>& a,vector<vector<int>>& b) {
    int n = a.size();
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i][j] = a[i][j] + b[i][j];
        }
    }
    return ans;
}

vector<vector<int>> subtract_matrices(vector<vector<int>>& a,vector<vector<int>>& b) {
    int n = a.size();
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i][j] = a[i][j] - b[i][j];
        }
    }
    return ans;
}

int determinant_of_2x2_matrix(vector<vector<int>>& a) {
    return a[0][0]*a[1][1] - a[0][1]*a[1][0];
}

int determinant_of_3x3_matrix(vector<vector<int>>& a) {
    return a[0][0]*a[1][1]*a[2][2] + a[0][1]*a[1][2]*a[2][0] + a[1][0]*a[2][1]*a[0][2] - a[0][2]*a[1][1]*a[2][0] -
    a[0][0]*a[2][1]*a[1][2] - a[1][0]*a[0][1]*a[2][2];
}


int main() {
    //1
    int n = 2;
    vector<vector<int>> a(n, vector<int>(n));
    input_matrix(a);
    //2
    int m = 3;
    vector<vector<int>> b(m, vector<int>(m));
    input_matrix(b);
    //3
    print_matrix(a);
    print_matrix(b);
    //4
    vector<vector<int>> a2(n, vector<int>(n));
    vector<vector<int>> b2(m, vector<int>(m));
    input_matrix(a2);
    input_matrix(b2);
    vector<vector<int>> sum1 = summarize_matrices(a, a2);
    vector<vector<int>> sum2 = summarize_matrices(b, b2);
    print_matrix(sum1);
    print_matrix(sum2);
    //5
    vector<vector<int>> subtr1 = subtract_matrices(a, a2);
    vector<vector<int>> subtr2 = subtract_matrices(b, b2);
    print_matrix(subtr1);
    print_matrix(subtr2);
    //6
    cout << determinant_of_2x2_matrix(a) << "\n" << determinant_of_3x3_matrix(b) << "\n";
    return 0;
}

