#ifndef __StopwordLoader_H__
#define __StopwordLoader_H__

#include <bits/stdc++.h>

using namespace std;

class StopWords{
    public:
        list<string> stopwords;

    private:
        void GetStopWords();
        void AddStopWord();

};

#endif