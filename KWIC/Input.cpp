#include "Input.h"
#include "StopwordLoader.h"
#include <bits/stdc++.h>

using namespace std;

void Input::GetTitles(){
    fstream file;
    string line;

    file.open("titles.txt");
    
    while(getline(file, line)){
        this->titles.push_back(line);
    }
}

void Input::Filter(list<string> stopwords){
    

    for(auto x:this->titles){
        
    }
}