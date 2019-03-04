#pragma once

#include<vector>

class interval				//A interval contains a start and a end number
{
public:
	interval();
	interval(int, int);
	~interval();

	int start;
	int end;
};
