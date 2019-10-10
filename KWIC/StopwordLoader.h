#ifndef __StopwordLoader_H__
#define __StopwordLoader_H__

#include <bits/stdc++.h>

using namespace std;

class StopWords{
    public:
    	vector<string> stopwords;

        void GetStopWords();
        void AddStopWord();
        void PrintStopWords();
};

#endif