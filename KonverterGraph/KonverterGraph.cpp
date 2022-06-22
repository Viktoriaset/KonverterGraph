#include <iostream>
#include <vector>
#include <string>
#include <fstream>

extern int rightAnswer();

void inputMat(std::ifstream &inp, std::vector<std::vector<int>>& g, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            int temp;
            inp >> temp;
            g[i][j] = temp;
        }
    }
}

void inputEdges(std::ifstream &inp, std::vector<std::vector<int>>& g, int len) {
    for (int i = 0; i < len; i++) {
        int left, right;
        inp >> left >> right;
        g[left-1][right-1] = 1;
    }
}

void inputList(std::ifstream &inp, std::vector<std::vector<int>>& g, int len) {
    for (int i = 0; i < len; i++) {
        int edges;
        inp >> edges;
        for (int j = 0; j < edges; j++) {
            int temp;
            inp >> temp;
            g[i][temp-1] = 1;
        }
    }
}

void outputMat(std::ofstream& out, std::vector<std::vector<int>>g, int len) {
    out << len << std::endl;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            out << g[i][j] << ' ';
        }
        out << std::endl;
    }
}

int countEdges(std::vector<std::vector<int>> g) {
    int counter = 0;
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g.size(); j++) {
            counter += g[i][j];
        }
    }
    return counter;
}

void outputEdges(std::ofstream& out, std::vector<std::vector<int>>g) {
    int len = countEdges(g);
    out << g.size() << ' ' << len << std::endl;
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g.size(); j++) {
            if (g[i][j] == 1) {
                out << i+1 << ' ' << j+1 << std::endl;
            }
        }
    }
}

void outputList(std::ofstream& out, std::vector<std::vector<int>>g) {
    out << g.size() << std::endl;
    for (int i = 0; i < g.size(); i++) {
        std::vector<int>temp;
        for (int j = 0; j < g.size(); j++) {
            if (g[i][j] == 1) {
                temp.push_back(j);
            }
        }
        out << temp.size() << ' ';
        for (int j = 0; j < temp.size(); j++) {
            out << temp[j] + 1 << ' ';
        }
        out << std::endl;
    }
}

int main()
{
    std::ifstream inp("input.txt");
    std::ofstream out("output.txt");

    std::string start, finish;
    int n, h;
    inp >> start >> finish;
    inp >> n;

    std::vector<std::vector<int>> g;
    for (int i = 0; i < n; i++) {
        g.push_back(std::vector<int>(n));
    }

    if (start == "edges") { 
        inp >> h;
        inputEdges(inp, g, h);
    }
    else if (start == "lists") {
        inputList(inp, g, n);
    }
    else {
        inputMat(inp, g, n);
    }

    if (finish == "edges") {
        outputEdges(out, g);
    }
    else if (finish == "lists") {
        outputList(out, g);
    }
    else {
        outputMat(out, g, n);
    }

    rightAnswer();
}
