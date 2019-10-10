#include "Input.h"
#include "StopwordLoader.h"
#include <bits/stdc++.h>

using namespace std;

void Input::GetTitles(){
    fstream file;
    string line;
    string word;

    file.open("titles.txt");
    
    while(getline(file, line)){
        this->titles.push_back(line);
        this->shifts.push_back(line);
    }
}

void Input::PrintTitles(){
    for(string x:this->titles){
        cout << x << endl;
    }
}
