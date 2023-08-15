/* name-akash yadav
email - ayadav35@myseneca.ca
studentID - 172566218
date - 17/01/2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	bool readTitle(char title[]);
	bool readYear(int* year);
	bool readMovieRating(char rating[]);
	bool readDuration(int* duration);
	bool readGenres(char genres[][11]);
	bool readConsumerRating(float* rating);
}

#endif

