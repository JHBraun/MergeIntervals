#include "pch.h"
#include "interval.h"

interval::interval()
{
}

interval::interval(int newStart, int newEnd)
{
	this->start = newStart;
	this->end = newEnd;
}

interval::~interval()
{
}