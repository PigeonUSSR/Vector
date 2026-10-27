/******************************************
* Автор: Прохоров В.В.                    *
* Дата: 27.10.2026                        *
* Название: Строки, векторы и словари     *
* Вариант: 22                             *
******************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    string line, word;
    size_t start, i, len;

    cout << "Part A\n";
    if (!getline(cin, line)) {
        cout << "EMPTY\n";
        return 0;
    }

    vector<string> result;
    i = 0;
    len = line.size();

    while (i < len) {
        while (i < len && (line[i] == ' ' || line[i] == '\t')) ++i;
        if (i >= len) break;
        start = i;
        while (i < len && line[i] != ' ' && line[i] != '\t') ++i;
        word = line.substr(start, i - start);
        unsigned char ch = static_cast<unsigned char>(word[0]);
        if (ch >= 'A' && ch <= 'Z')
            result.push_back(word);
    }

    if (result.empty()) {
        cout << "EMPTY\n";
        return 0;
    }

    for (size_t k = 0; k < result.size(); ++k) {
        cout << result[k] << ' ';
    }

    cout << "Part B\n"; // Part B
    int numbers;
    cin >> numbers;

    if (numbers < 0 || numbers > 100) {
        cout << "INVALID\n";
        return 0;
    }

    vector<int> a(numbers);
    for (int i = 0; i < numbers; ++i) {
        cin >> a[i];
        if (a[i] < -1000 || a[i] > 1000) {
            cout << "INVALID\n";
            return 0;
        }
    }

    if (numbers == 0) {
        cout << "EMPTY\n";
        return 0;
    }

    for (int i = 1; i < numbers; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }

    for (int i = 0; i < numbers; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }

    cout << "Part C\n"; // Part C
    int threshold, value;
    cin >> threshold;

    if (threshold < -1000 || threshold > 1000) {
        cout << "INVALID\n";
        return 0;
    }

    map<string, int> src;
    for (int i = 0; i < 4; ++i) {
        string key;
        cin >> key >> value;
        src[key] = value;
    }

    map<string, int> filtered;
    for (map<string, int>::const_iterator it = src.begin(); it != src.end(); ++it) {
        if (it->second >= threshold)
            filtered[it->first] = it->second;
    }

    if (filtered.empty()) {
        cout << "EMPTY\n";
        return 0;
    }

    for (map<string, int>::const_iterator it = filtered.begin(); it != filtered.end(); ++it) {
        cout << it->first << ' ' << it->second << '\n';
    }
    cout << "Part D\n"; // Part D
    int n;
    cin >> n;

    if (n < 0) {
        cout << "INVALID\n";
        return 0;
    }

    if (n == 0) {
        cout << "EMPTY\n";
        return 0;
    }

    string dummy;
    getline(cin, dummy);          // съедаем '\n' после числа n

    vector<string> out;

    for (int i = 0; i < n; ++i) {
        string sender, text;
        getline(cin, sender);
        getline(cin, text);

        if (sender.empty()) {
            cout << "INVALID\n";
            return 0;
        }

        if (text.size() > 20) {
            out.push_back(sender + " " + to_string(text.size()));
        }
    }

    if (out.empty()) {
        cout << "EMPTY\n";
        return 0;
    }

    for (size_t index = 0; index < out.size(); ++index)
        cout << out[index] << '\n';

    cout << '\n';
    return 0;
}
