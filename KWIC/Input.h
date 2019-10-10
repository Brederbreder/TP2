#ifndef __Input_H__
#define __Input_H__

#include "StopwordLoader.h"
#include <bits/stdc++.h>

using namespace std;

class Input{
	public:
	    vector<string> titles;
		vector<string> shifts;

    	void GetTitles();
    	void PrintTitles();  
};

#endif