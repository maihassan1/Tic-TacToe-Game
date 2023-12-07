
#include <bits/stdc++.h>


using namespace std;

int main() {

    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;

    ifstream file(filename);
    if (!file){
        cout << "Error opening file " << endl;
        return 0;
    }

    map<string, int> table;
    string word;
    while (file >> word){
        string clean = "";
        bool True = false;
        for (int i = 0; i < word.length(); i++){
            if (isalnum(word[i]) || word[i] == '-'){
                clean += tolower(word[i]);
                 True = true;
            }
        }
        if (True){
            table[clean]++;
        }
    }

    cout << "Frequency Table:: " << endl;
    for (const auto& [word, counter] : table) {
       cout << " "<<word << ": " << counter << endl;
    }

    return 0;
}
