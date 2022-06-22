#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int rightAnswer() {

    ifstream fin("input.txt");
    ofstream fout("output1.txt");


    string first, second;
    fin >> first >> second;
    int n, m;
    int num1, num2;
    if (first == "edges") {
        if (second == "mat") {
            fin >> n >> m;
            vector<vector<int>> arr(n, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    arr[i][j] = 0;
                }
            }
            for (int i = 0; i < m; i++) {
                fin >> num1 >> num2;
                num1--;
                num2--;
                arr[num1][num2] = 1;
            }
            fout << n << '\n';
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    fout << arr[i][j] << " ";
                }
                fout << '\n';
            }
        }
        else if (second == "lists") {
            fin >> n >> m;
            vector<vector<int>> mas(n);
            for (int i = 0; i < m; i++) {
                fin >> num1 >> num2;
                num1--;
                mas[num1].push_back(num2);

            }
            for (int i = 0; i < mas.size(); i++)
                sort(mas[i].begin(), mas[i].end());
            fout << mas.size() << '\n';

            for (int i = 0; i < n; i++) {
                fout << mas[i].size() << " ";
                for (int j = 0; j < mas[i].size(); j++) {

                    fout << mas[i][j] << " ";
                }
                fout << '\n';
            }
        }
        else {
            int a;
            fin >> n >> m;
            fout << n << " " << m << '\n';
            for (int i = 0; i < m; i++) {
                fin >> a;
                fout << a << " ";
                fin >> a;
                fout << a << '\n';

            }
        }
    }
    else if (first == "mat") {
        fin >> num1;
        int a;
        vector<vector<int>> mas(num1);
        if (second == "lists") {
            for (int i = 0; i < num1; i++) {
                for (int j = 0; j < num1; j++) {
                    fin >> a;
                    if (a) {
                        mas[i].push_back(j + 1);
                    }
                }
            }
            fout << num1 << '\n';
            for (int i = 0; i < mas.size(); i++)
                sort(mas[i].begin(), mas[i].end());

            for (int i = 0; i < num1; i++) {
                fout << mas[i].size() << " ";
                for (int j = 0; j < mas[i].size(); j++) {

                    fout << mas[i][j] << " ";
                }
                fout << '\n';
            }
        }
        else if (second == "edges") {
            vector<int> vec;
            for (int i = 0; i < num1; i++) {
                for (int j = 0; j < num1; j++) {
                    fin >> a;
                    if (a == 1) {
                        vec.push_back(i + 1);
                        vec.push_back(j + 1);
                    }
                }
            }
            fout << num1 << " " << vec.size() / 2 << '\n';
            for (int i = 0; i < vec.size(); i += 2) {
                fout << vec[i] << " " << vec[i + 1] << '\n';
            }
        }
        else {
            fout << num1 << '\n';
            for (int i = 0; i < num1; i++) {
                for (int j = 0; j < num1; j++) {
                    fin >> a;
                    fout << a << " ";
                }
                fout << '\n';
            }
        }
    }
    else if (first == "lists") {
        bool flag = true;
        int a;
        fin >> num1;
        vector<vector<int>> mas(num1, vector<int>(num1));
        if (second == "mat") {
            fout << num1 << '\n';
            for (int i = 0; i < num1; i++) {
                int size;
                fin >> size;
                for (int j = 0; j < num1; j++) {
                    if (flag && size != 0) {
                        fin >> a;
                        flag = false;
                        size--;
                    }
                    if (j == a - 1) {
                        flag = true;
                        mas[i][j] = 1;
                        a = -1;
                    }
                    else
                        mas[i][j] = 0;

                    fout << mas[i][j] << " ";
                }
                fout << '\n';
            }
        }
        else if (second == "edges") {
            int size;
            vector<int> vec;
            for (int i = 0; i < num1; i++) {
                fin >> size;
                for (int j = 0; j < size; j++) {
                    fin >> a;
                    vec.push_back(i + 1);
                    vec.push_back(a);

                }
            }
            fout << num1 << " " << vec.size() / 2 << '\n';
            for (int i = 0; i < vec.size(); i += 2) {
                fout << vec[i] << " " << vec[i + 1] << '\n';
            }
        }
        else {
            fout << num1 << '\n';
            int size;
            for (int j = 0; j < num1; j++) {
                fin >> size;
                fout << size << " ";
                for (int i = 0; i < size; i++) {
                    fin >> a;
                    fout << a << " ";
                }
                fout << '\n';
            }
        }
    }

    return 0;
}
