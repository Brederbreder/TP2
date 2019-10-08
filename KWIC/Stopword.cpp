#include "StopwordLoader.h"
#include <bits/stdc++.h>

using namespace std;

void StopWords::GetStopWords()
{
    fstream file;
    string word;

    file.open("stopwords.txt");
    
    while(file >> word)
        this->stopwords.push_back(word);
}

void StopWords::AddStopWord()
{
    cout << "Digite a palavra a ser adicionada na lista de stopwords:\n";
    string word;
    cin >> word;

    ofstream file;
    file.open("stopwords.txt");
    file << word;
    file.close();
}