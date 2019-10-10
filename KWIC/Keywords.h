#ifndef __KEYWORDS_H__
#define __KEYWORDS_H__

#include "Input.h"
#include "StopwordLoader.h"
#include <bits/stdc++.h>

using namespace std;

class KeyWord{
	public:
		vector<pair<int, string>> keywords;

		void GetKeywords(Input& Input);
        void Filter(StopWords& stopwords);
        void PrintKeywords(); 
};

#endif