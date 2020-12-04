#pragma once
/* File: BaseballPlayer.h
   Program 5: Abi Kunkle
*/

using namespace std;
#include <iostream>			
#include <string>			

#define HITS_DATA_LENGTH 8   

class BaseballPlayer {
	typedef enum { ATBATS, SINGLES, DOUBLES, TRIPLES, HOMERS, WALKS, HBP, APPEARANCES } mBattingIndex;


	string mLastName;					// last name of a baseball player	
	string mFirstName;					// player's first name

	int  mHitting[HITS_DATA_LENGTH];	// an array to store the raw hitting stats for the player.
										// these stats include number of singles, doubles, etc.

	double mBattingAverage;				// batting average as computed from the statistics
	double mOnBasePercentage;			// on base percentage as a function of plate appearances
	double mSluggingPercentage;         // slugging percentage computation
	double mOPS;						// on base + slugging

public:
	BaseballPlayer();					// default constructor - sets all data to empty/default values

	void read(istream& input);			// read a player's stats from an input stream (file or keyboard)
	void computeStats();				// instructs the class object to compute its stats based on raw data

	// other interface methods required for get/set as needed
	string getFullName();
	string getFirstName();
	string getLastName();
	double getBattingAverage();
	double getOnBasePercentage();
	double getSluggingPercentage();
	double getOPS();
	void display(ostream& output);


};

