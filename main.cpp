#include "functions.h"

int main()
{
    srand(time(0));

    ofstream out("e.txt");
    ofstream jout("data.json");

    int size;
    int n;

    cout << "Enter size of array: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Size must be > 0";
        return 0;
    }

    vector<int> v1(size);
    vector<int> v2;

    // Заповнення масиву
    for (int i = 0; i < size; i++)
    {
        v1[i] = rand() % 99 + 1;
    }

    // Зберігаємо початковий масив
    vector<int> originalV1 = v1;

    // Вивід
    cout << "Array V1: ";
    for (int x : v1) cout << x << " ";
    cout << endl;

    cout << "Enter n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "n must be > 0";
        return 0;
    }

    // ГРУПИ І S2
    out << "Summed numbers:\n";

    int sum2 = 0;

    for (int i = 0; i < v1.size(); i += n)
    {
        int sum = 0;

        for (int j = 0; j < n && i + j < v1.size(); j++)
        {
            sum += v1[i + j];
        }

        out << sum << endl;
        sum2 += sum; // ✅ правильний S2
    }

    // SORT ASC
    sortAsc(v1);

    cout << "\nSorted ASC: ";
    for (int x : v1) cout << x << " ";

    cout << "\nSum ASC: " << sumOfElements(v1) << endl;

    // SORT DESC
    sortDesc(v1);

    cout << "\nSorted DESC: ";
    for (int x : v1) cout << x << " ";

    cout << "\nSum DESC: " << sumOfElements(v1) << endl;

    // REMOVE DUPLICATES
    rmDuplicates(originalV1, v2);

    int sum3 = sumOfElements(v2);

    // РІЗНИЦЯ
    cout << "\nS3 - S2: " << sum3 - sum2 << endl;

    // КІЛЬКІСТЬ ДУБЛІКАТІВ
    int duplicatesCount = v1.size() - v2.size();

    // РІЗНИЦЯ МАСИВІВ
    cout << "\n|V1 - V2|: ";
    printDifference(v1, v2);

    // JSON
    JsonOut(jout, sum2, sum3, duplicatesCount, originalV1, v2);

    out.close();
    jout.close();
}