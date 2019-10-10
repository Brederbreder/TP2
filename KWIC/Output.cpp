#include "Output.h"
#include "Input.h"
#include "Keywords.h"
#include <bits/stdc++.h>

using namespace std;

void Output::GetOutput(Input& Input, KeyWord& KeyWord){
	auto kw = KeyWord.keywords;
	size_t bword = 0, eword = 0;

	for(unsigned int i = 0; i < kw.size(); i++){
		int index = kw[i].first;
		string s = kw[i].second;
		string titles = Input.titles[index];
		
		bword = titles.find(s);
		eword = s.length();
	
		titles.erase(bword, eword + 1);
		  
		if(titles[titles.length() - 1] == ' ')
			titles += "/" + s;
		else
			titles += " /" + s;

		this->outtitles.push_back(make_pair(titles, index));
	}
}

void Output::FindTitles(Input& Input){
	int count = 1;
	string key;

	cout << "->Digite uma chave de busca: ";
	cin >> key;

	for(unsigned int i = 0; i < this->outtitles.size(); i++){
		string titles = this->outtitles[i].first;
		size_t barra = titles.find('/');

		string word = titles.substr(barra+1, titles.length() - 1);

		if(word == key){
			cout << count << ". " <<  Input.titles[outtitles[i].second] << endl;
			count++;
		}
	}
}

void Output::PrintOutput(){
	for(auto x:outtitles)
		cout << x.first << endl;
}
