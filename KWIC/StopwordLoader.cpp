#include <bits/stdc++.h>
#include "StopwordLoader.h"

using namespace std;

void getStopwords(vector<string>& stopwords){
    fstream file;
    string word;

    file.open("stopwords.txt");

    while(file >> word){
        stopwords.push_back(word);
    }
}

void printStopwords(vector<string>& stopwords){
    for(int i=0; i<stopwords.size(); i++){
        cout << stopwords[i] << " ";
    }
}