#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include "Input.h"
#include "Keywords.h"
#include <bits/stdc++.h>

using namespace std;

class Output{
	public:
		vector<pair<string, int>> outtitles;

		void GetOutput(Input& Input, KeyWord& KeyWord);
		void FindTitles(Input& Input);
		void PrintOutput();
};

#endif