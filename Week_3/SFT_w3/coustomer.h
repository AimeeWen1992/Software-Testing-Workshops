#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef COUSTOMER_H
#define COUSTOMER_H


namespace aimeeProject {

	struct Coustomer
	{
		char firstName[30+1];
		char lastName[30 + 1];
		char address[100+1];
		char city[100+1];
		char province[100+1];
		char postalCode[100+1];
	};

	Coustomer readInfo();

	bool testPostalCode(char postalCode[]);

	bool testCharContainDigit(const char* string);

	bool testCharContainOthers(const char* string);

	void errorMessage();

	void display();

}


#endif // !COUSTOMER_H
