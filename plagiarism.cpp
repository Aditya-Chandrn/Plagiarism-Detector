#include<bits/stdc++.h>
using namespace std;

void printLCS(vector<vector<int>>& dp, string& X, string& Y, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (X[i - 1] == Y[j - 1]) {
        printLCS(dp, X, Y, i - 1, j - 1);
        cout << X[i - 1];
    } else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
            printLCS(dp, X, Y, i - 1, j);
        } else {
            printLCS(dp, X, Y, i, j - 1);
        }
    }
}

int lcs(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    
    cout<<"\n\n   The plagiarised text is : \n";
    printLCS(L, X, Y, m, n);
    cout << endl;

    return L[m][n];
}

int main() {
    string s1, s2;
    cout<<"\n   Enter the first string: ";
    getline(cin, s1);
    cout<<"\n   Enter the second string: ";
    getline(cin, s2);

     // string f1,f2;
    // cout << "Enter the name of the first file: ";
    // cin >> f1;
    // cout << "Enter the name of the second file: ";
    // cin >> f2;

    // ifstream file1(f1); 
    // string s1; 
    
    // if(file1.is_open()) { 
    //     string line;
    //     while(getline(file1, line)) {
    //         s1 += line; 
    //     }
    //     file1.close(); 
    // }
    

    // ifstream file2(f2); 
    // string s2; 

    // if(file2.is_open()) { 
    //     string line;
    //     while(getline(file2, line)) {
    //         s2 += line; 
    //     }
    //     file2.close(); 
    // }

    int lcs_length = lcs(s1, s2);
    double similarity = (2.0 * lcs_length) / (s1.length() + s2.length()) * 100;
    printf("\n\n  Similarity between the two strings is %.2lf%%\n", similarity);

    return 0;
}