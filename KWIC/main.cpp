#include <bits/stdc++.h>
#include "StopwordLoader.h"
#include "StringManager.h"

using namespace std;

int main(){

    vector<string> stopwords;
    vector<string> titles;

    getStopwords(stopwords);
    printStopwords(stopwords);

    getTitles(titles);
    printTitles(titles);
}