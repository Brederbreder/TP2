#include "StringManager.h"

#include <bits/stdc++.h>
using namespace std;

void getTitles(vector<string>& titles){
    fstream file;
    string title;

    file.open("titles.txt");
    while(getline(file, title)){
        titles.push_back(title);
    }
}

void printTitles(vector<string>& titles){
    for(int i=0; i<titles.size(); i++){
        cout << titles[i] << "\n";
    }
}