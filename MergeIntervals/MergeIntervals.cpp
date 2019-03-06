//C++-application to sort a list of intervals. If there are overlapping intervals, they will be merged.

#include "pch.h"
#include "interval.h"		//A interval contains a start and a end number.
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compInterval(interval iv1, interval iv2) {			//compares 2 intervals by their start number
	return (iv1.start < iv2.start);						//needed for std::sort()
}

vector<interval> merge(vector<interval> &ivIPvector, int n) {			//function for merging overlapping intervals.
																		//takes a list of intervals (with count n) and returns a merged list.
	if (n <= 0) {														//list needs atleast one interval.
		cout << "Error: You need atleast one given interval for this setup.";
	}
	else
	{
		vector<interval> ivOPvector;									//create a new vector (output) including interval-objects.		

		sort(ivIPvector.begin(), ivIPvector.end(), compInterval);		//using library function std::sort to sort given intervals by their start number 
																		//(https://en.cppreference.com/w/cpp/algorithm/sort).
		ivOPvector.push_back(ivIPvector.front());						//push the first interval to the output vector.

		for (size_t i = 1; i < n; i++)									//takes the following intervals and merges if they overlap to the previous one.
		{
			interval current = ivOPvector.back();						//get the last interval of the output vector
			if (current.end < ivIPvector.at(i).start)					//and compares it to the following interval.
				ivOPvector.push_back(ivIPvector.at(i));					//if the following interval is not overlapping, push it to the output vector
			else if (current.end < ivIPvector.at(i).end) {				//else correct the end number and overwrite the interval.
				current.end = ivIPvector.at(i).end;
				ivOPvector.pop_back();
				ivOPvector.push_back(current);
			}
		}
		return ivOPvector;												//returns the merged output vector.
	}
}

int main()
{
	int n;														//user-input: number of needed intervals to merge.
	cout << "How many intervals do you want to merge?\t";
	cin >> n;
	if (n <= 0) {												//list needs atleast one interval to work properly.
		cout << "Error: You need atleast one given interval for this setup.";
		return 0;
	}
	vector<interval> ivIPvector;								//create a new vector (input) including interval-objects.

	cout << "Please enter your intervals. Example: '10 15' ('startnumber(space)endnumber').\n";					//user-input: needed intervals to merge.
	for (size_t i = 0; i < n; i++)
	{
		cout << "Interval " << i + 1 << ":\n";
		interval myInterval;
		cin >> myInterval.start;								//write start and end number to current interval-object.
		cin >> myInterval.end;
		if (myInterval.start > myInterval.end) {				//show a error message if the user puts in an invalid interval.
			cout << "Error: No valid input interval.";
			return 0;
		}
		ivIPvector.push_back(myInterval);						//push the user input to the created interval vector.
	}
	n = ivIPvector.size();										//number of intervals put in by the user.

	vector<interval> ivOPvector;								//create a new vector (output) including interval-objects
	ivOPvector = merge(ivIPvector, n);							//to save the return of the merge-function.

	cout << "\nMerged:\n";										//console output: merged intervals by increasing start number.
	for (size_t i = 0; i < ivOPvector.size(); i++)
	{
		cout << "[" << ivOPvector.at(i).start << ",";
		cout << ivOPvector.at(i).end << "]" << "\n";
	}
	return 0;
}

