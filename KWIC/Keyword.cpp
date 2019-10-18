#include "Keywords.h"
#include "Input.h"
#include "StopwordLoader.h"
#include <bits/stdc++.h>

using namespace std;

void KeyWord::GetKeywords(Input& Input){
	auto shifts = Input.shifts;
	size_t pos = 0;
	string delimeter = " ";

	for(unsigned int i = 0; i < shifts.size(); i++){
		while((pos = shifts[i].find(delimeter)) != string::npos){
			string word = shifts[i].substr(0, pos);
			this->keywords.push_back(make_pair(i, word));
			shifts[i].erase(0, pos + delimeter.length());
		}
	
		this->keywords.push_back(make_pair(i, shifts[i]));
	}	
}

void KeyWord::Filter(StopWords& Stopword){
	auto sw = Stopword.stopwords;
	auto kw = this->keywords;

	for(unsigned int i = 0; i < kw.size(); i++){
		string s = kw[i].second;
		s[0] = tolower(s[0]);
		
		if(find(sw.begin(), sw.end(), s) != sw.end()){
			kw.erase(kw.begin() + i);
			i--;
		}
	}

	this->keywords = kw;
}

void KeyWord::PrintKeywords(){
	set<string> all_keys;

	for(int i = 0; i < this->keywords.size(); i++){
    	all_keys.insert(this->keywords[i].second);
    }

    for(string s:all_keys){
    	cout << s << "->" <<  << endl;
    }
}