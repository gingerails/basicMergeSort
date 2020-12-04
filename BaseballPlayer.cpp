/* File: BaseballPlayer.cpp
   Program 5: Abi Kunkle
*/
#include "BaseballPlayer.h"
#include <iomanip>

//-----------------------------------------------------------------------------------------------//
// Default Constructor
// Sets numberic values to zeros, and other values to either empty strings or default values
//-----------------------------------------------------------------------------------------------//
BaseballPlayer::BaseballPlayer() {

	mFirstName = "unknown";
	mLastName = "unknown";
	for (int i = 0; i <= APPEARANCES; i++)
		mHitting[i] = 0;

}

//-----------------------------------------------------------------------------------------------//
// read(input)
// reads in plate apperances before the hits data, and the walks and HBP
//-----------------------------------------------------------------------------------------------//
void BaseballPlayer::read(istream& input) {
	input >> mFirstName >> mLastName;
	input >> mHitting[APPEARANCES];   // i am storing the first value at the end of my data array
	for (int i = ATBATS; i <= HBP; i++)
		input >> mHitting[i];				// read in each stat from input stream

}


//-----------------------------------------------------------------------------------------------//
// computeStats
// This function currently computes the player's batting average based on the hitting data.
// Later revisions will compute additional player statistics.
//-----------------------------------------------------------------------------------------------//
void BaseballPlayer::computeStats() {
	mBattingAverage = 0.0;
	mSluggingPercentage = 0.0;

	for (int i = SINGLES; i <= HOMERS; i++) {// step through the hitting values and sum them
		mBattingAverage = mBattingAverage + mHitting[i];
		mSluggingPercentage = mSluggingPercentage + (i * mHitting[i]);
	}
	if (mHitting[ATBATS] > 0) {
		mBattingAverage = mBattingAverage / mHitting[ATBATS];
		mSluggingPercentage = mSluggingPercentage / mHitting[ATBATS];
	}
	else {
		mBattingAverage = 0.0;		// if there was a 0 in the at bats, we can't divide by it
		mSluggingPercentage = 0.0;
	}

	// compute on base percentage too
	mOnBasePercentage = 0.0;
	for (int i = SINGLES; i <= HBP; i++) {
		mOnBasePercentage = mOnBasePercentage + mHitting[i];
	}
	if (mHitting[APPEARANCES] > 0)
		mOnBasePercentage = mOnBasePercentage / mHitting[APPEARANCES];
	else
		mOnBasePercentage = 0.0;

	mOPS = mOnBasePercentage + mSluggingPercentage;
}



//-----------------------------------------------------------------------------------------------//
// getFullName()
// This get method is used to get the player's full name built as a single string from the
// names stored in the class.
//-----------------------------------------------------------------------------------------------//
string BaseballPlayer::getFullName() {
	string tempStorage;
	tempStorage = mLastName + ", " + mFirstName;
	return tempStorage;
}
//-----------------------------------------------------------------------------------------------//
// getFirstName()
// This get method is used to get the player's first name
//-----------------------------------------------------------------------------------------------//
string BaseballPlayer::getFirstName() {
	return mFirstName;
}
//-----------------------------------------------------------------------------------------------//
// getLastName()
// This get method is used to get the player's last name 
//-----------------------------------------------------------------------------------------------//
string BaseballPlayer::getLastName() {
	return mLastName;
}

//-----------------------------------------------------------------------------------------------//
// getBattingAverage()
// Used to retrieve the batting average for this player after it has been computed.
//-----------------------------------------------------------------------------------------------//
double BaseballPlayer::getBattingAverage() {
	return mBattingAverage;
}
//-----------------------------------------------------------------------------------------------//
// getSluggingPercentage()
// Used to retrieve the slugging average for this player after it has been computed.
//-----------------------------------------------------------------------------------------------//
double BaseballPlayer::getSluggingPercentage() {
	return mSluggingPercentage;
}
//-----------------------------------------------------------------------------------------------//
// getOnBasePercentage()
// Used to retrieve the on base average for this player after it has been computed.
//-----------------------------------------------------------------------------------------------//
double BaseballPlayer::getOnBasePercentage() {
	return mOnBasePercentage;
}
//-----------------------------------------------------------------------------------------------//
// getOPS()
// Used to retrieve the OPS for this player after it has been computed.
//-----------------------------------------------------------------------------------------------//
double BaseballPlayer::getOPS() {
	return mOPS;
}

//display our player array to a file
void BaseballPlayer::display(ostream& output)
{

	output << setw(20) << getLastName() + ", " + getFirstName();
	output << " :    " << setw(6) << setprecision(3) << getBattingAverage();
	output << "   " << setw(6) << setprecision(3) << getOPS();
	output << endl;

}
