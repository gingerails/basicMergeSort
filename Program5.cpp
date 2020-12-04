/*
file: PlayerTest.cpp
Author: Abi Kunkle
Date: 12/3/2020
IDE: Visual Studio 2019

This program will sort an array of Players using Mergesort.
For this problem, you will order the players by batting average insteadof their names.
Read up to 100 players into asimplearray that can hold Player objects. playersin a file, from 1 through 100.


*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "BaseballPlayer.h"
#define MAX_SIZE 100

//function prototypes for merging and such
void merge(BaseballPlayer* , int, int, int, int, BaseballPlayer* );
void mergeSort(BaseballPlayer* , int, int, BaseballPlayer* );
void printArray(BaseballPlayer* , int); //prints to console to make testing easier


int main(void) {
	string inFileName, outFileName;
	BaseballPlayer sortArr[MAX_SIZE]; //array of BaseballPlayer objects
	BaseballPlayer tempArr[MAX_SIZE];
	int i = 0, arrSize = 0;

	ifstream inputFile;						// input file handle
	ofstream outputFile;					// output file handle

	BaseballPlayer p1;					// a temporary  object = the current player being read or printed
	cout << "Welcome to the player statistics calculator test program.  I am going to\n";
	cout << "read players from an input data file.  You will tell me the names of\n";
	cout << "your input and output files.  I will store all of the players in a list, \n";
	cout << "compute each player's average and then write the resulting team report \n";
	cout << "to your output file.\n\n";

	cout << "\n\n";


	cout << "Enter the name of your input file:  ";  cin >> inFileName;
	cout << "Enter the name of your output file: ";  cin >> outFileName;

	// opening data files
	inputFile.open(inFileName.c_str());
	if (inputFile.fail()) {
		cout << "Sorry. I could not open your input file - " << inFileName << "-\n";
		cout << "Exiting the program.\n";  return 1;
	}
	outputFile.open(outFileName.c_str());
	if (outputFile.fail()) {
		cout << "Sorry. I could not open your output file - " << outFileName << "-\n";
		cout << "Exiting the program.\n";  return 1;
	}
	cout << "Reading Players from " << inFileName << endl;
	int count = 0;   // tbd later
	while (!inputFile.eof() && arrSize < MAX_SIZE) {
		p1.read(inputFile);
		p1.computeStats();
		sortArr[arrSize] = p1; // adds this player to the array
		arrSize++;
	}

	outputFile << "BASEBALL TEAM REPORT --- " << arrSize << " PLAYERS FOUND IN FILE\n";
	outputFile << endl << endl;

	mergeSort(sortArr, 0, arrSize - 1, tempArr); //sorts array in order of batting average
	printArray(sortArr, arrSize);				


	outputFile << "    PLAYER NAME      :    AVERAGE    OPS\n";
	outputFile << "----------------------------------------------\n";
	//p1.display(outputFile);
	for (i = 0; i < arrSize; i++) {
		sortArr[i].display(outputFile);
		outputFile << endl;
	}
	outputFile.close();

}

void merge(BaseballPlayer sortArr[], int leftFirst, int leftLast, int rightFirst, int rightLast, BaseballPlayer tempArr[])
{
	int i = leftFirst;
	int save = leftFirst;

	
	while (leftFirst <= leftLast && rightFirst <= rightLast)
	{
		double leftCompare = sortArr[leftFirst].getBattingAverage();	//this took me way too long to figure out. grabbing the battingAverage for each side to compare
		double rightCompare = sortArr[rightFirst].getBattingAverage();
		if (leftCompare > rightCompare)						//if the value for battingAverage on the leftside is more than the rightside
		{
			tempArr[i] = sortArr[leftFirst];								//set temp at i = to the value of sortArr at leftFirst
			leftFirst++;
		}
		else														 
		{
			tempArr[i] = sortArr[rightFirst];								//set temp at i = to the value of sortArr at rightFirst
			rightFirst++;
		}
		i++;
	}
	while (leftFirst <= leftLast)										//while leftFirst is less than leftLast, set temp[i] = leftFirst and iterate both lefFirst and i
	{
		tempArr[i] = sortArr[leftFirst];
		leftFirst++;
		i++;
	}
	while (rightFirst <= rightLast)										//while rightFirst is less than rightLast, set temp[i] = rightFirst and iterate both rightFirst and i
	{
		tempArr[i] = sortArr[rightFirst];
		rightFirst++;
		i++;
	}
	for (i = save; i <= rightLast; i++)									//copies tempArr into SortArr
		sortArr[i] = tempArr[i];
}

void mergeSort(BaseballPlayer sortArr[], int leftSide1, int rightSide2, BaseballPlayer tempArr[])
{
	int middle;
	if (leftSide1 < rightSide2)
	{
		middle = (leftSide1 + rightSide2) / 2;			//finds the middle of the array

		mergeSort(sortArr, leftSide1, middle, tempArr);		//calls mergesort for the left side
		mergeSort(sortArr, middle + 1, rightSide2, tempArr);	//calls mergesort for the right side

		//calls merge to sort the array
		merge(sortArr, leftSide1, middle, middle + 1, rightSide2, tempArr);

	}
}

//prints array to console, not required but just made testing easier
void printArray(BaseballPlayer sortArr[], int size)
{
	cout << "Sorted with Mergesort: \n";
	int i = 0;
	while (i < size)
	{
		sortArr[i].display(cout);
		i++;
	}
}