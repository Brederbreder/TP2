#include "StopwordLoader.h"
#include <bits/stdc++.h>

using namespace std;

void StopWords::GetStopWords(){
    fstream file;
    string word;

    file.open("stopwords.txt");
    
    while(file >> word)
        this->stopwords.push_back(word);
}

void StopWords::AddStopWord(){
    cout << "->Digite a palavra a ser adicionada na lista de stopwords: ";
    string word;
    cin >> word;

    ofstream file;
    file.open("stopwords.txt", ios_base::app);
    file << endl << word;
    file.close();
}

void StopWords::PrintStopWords(){
    for(int i = 0; i < this->stopwords.size(); i++){
        cout << i+1 << ". " << this->stopwords[i] << endl;
    }
}