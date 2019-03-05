# MergeIntervals
C++-application (windows console) to sort a list of intervals. If there are overlapping intervals, they will be merged.

## functionality
The core of the project is a function called merge(), which is able to take a list of intervals (e.g. [25,30] [2,19] [14, 23] [4,8]) and return a sorted merged list of these ([2,23] [25,30]). Therefore overlapping intervals will be merged into a single new interval. The unchanged intervals stay the same.

## concept
nicht alle miteinander -> sorted
verschiedene merge möglichkeiten

## installation and running the build
This project can be imported directly into visual studio and uses the windows sdk version 10.0.17763.0. 
