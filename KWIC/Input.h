#ifndef __Input_H__
#define __Input_H__

#include <bits/stdc++.h>

using namespace std;

class Input{
    public:
        list<string> titles;
    
    private:
        void GetTitles();
        void Filter(list<string> stopwords);
};

#endif