#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

// ASC
void sortAsc(vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

// DESC
void sortDesc(vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] < v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

// SUM
int sumOfElements(const vector<int>& v)
{
    int sum = 0;
    for (int x : v) sum += x;
    return sum;
}

// REMOVE DUPLICATES
void rmDuplicates(const vector<int>& v, vector<int>& unique)
{
    for (int x : v)
    {
        bool exists = false;

        for (int y : unique)
        {
            if (x == y)
            {
                exists = true;
                break;
            }
        }

        if (!exists)
            unique.push_back(x);
    }
}

// DIFFERENCE |V1 - V2|
void printDifference(const vector<int>& v1, const vector<int>& v2)
{
    for (int x : v1)
    {
        bool found = false;

        for (int y : v2)
        {
            if (x == y)
            {
                found = true;
                break;
            }
        }

        if (!found)
            cout << x << " ";
    }

    cout << endl;
}

// JSON
void JsonOut(ofstream& jout, int sum2, int sum3, int duplicatesCount,
             const vector<int>& v1, const vector<int>& v2)
{
    jout << "{\n";
    jout << "  \"S2\": " << sum2 << ",\n";
    jout << "  \"S3\": " << sum3 << ",\n";
    jout << "  \"S3 - S2\": " << sum3 - sum2 << ",\n";
    jout << "  \"duplicatesCount\": " << duplicatesCount << ",\n";

    jout << "  \"V1\": [";
    for (int i = 0; i < v1.size(); i++)
    {
        jout << v1[i];
        if (i != v1.size() - 1) jout << ", ";
    }
    jout << "],\n";

    jout << "  \"V2\": [";
    for (int i = 0; i < v2.size(); i++)
    {
        jout << v2[i];
        if (i != v2.size() - 1) jout << ", ";
    }
    jout << "]\n";

    jout << "}\n";
}