#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cctype>
#include "coustomer.h"

using namespace std;


namespace aimeeProject {

	Coustomer coustomer;

	Coustomer readInfo()
	{

		bool flagForfitst = true;
		while (flagForfitst)
		{
			string inputFirst;
			cout << "Enter your first name : ";
			getline(cin, inputFirst);

			for (int i = 0; i < 31; i++)
			{
				coustomer.firstName[i] = inputFirst[i];
				if (inputFirst[i] == '\0')
				{
					break;
				}
			}

			if (testCharContainDigit(coustomer.firstName)||testCharContainOthers(coustomer.firstName))
			{
				errorMessage();
			}
			else
			{
				flagForfitst = false;
			}
		}

		bool flagForLast = true;
		while (flagForLast)
		{
			string inputLast;
			cout << "Enter your last name : ";
			getline(cin, inputLast);

			for (int i = 0; i < 31; i++)
			{
				coustomer.lastName[i] = inputLast[i];
				if (inputLast[i] == '\0')
				{
					break;
				}
			}
			if (testCharContainDigit(coustomer.lastName)|| testCharContainOthers(coustomer.lastName))
			{
				errorMessage();
			}
			else
			{
				flagForLast = false;
			}
		}

		string inputAdd;
		cout << "Enter your address : ";
		getline(cin, inputAdd);
		
		for (int i = 0; i < 100; i++)
		{
			coustomer.address[i] = inputAdd[i];
			if (inputAdd[i] == '\0')
			{
				break;
			}
		}

		bool flagForCity = true;
		while (flagForCity)
		{
			string inputCity;
			cout << "Enter your city : ";
			getline(cin, inputCity);

			for (int i = 0; i < 100; i++)
			{
				coustomer.city[i] = inputCity[i];
				if (inputCity[i] == '\0')
				{
					break;
				}
			}

			if (testCharContainDigit(coustomer.city)|| testCharContainOthers(coustomer.city))
			{
				errorMessage();
			}
			else
			{
				flagForCity = false;
			}
		}

		bool flagForProvince = true;
		while (flagForProvince)
		{
			string inputProvince;
			cout << "Enter your provience : ";
			getline(cin, inputProvince);

			for (int i = 0; i < 100; i++)
			{
				coustomer.province[i] = inputProvince[i];
				if (inputProvince[i] == '\0')
				{
					break;
				}
			}

			if (testCharContainDigit(coustomer.province)||testCharContainOthers(coustomer.province))
			{
				errorMessage();
			}
			else
			{
				flagForProvince = false;
			}
		}

		bool flagForPpostalCode = true;

		while (flagForPpostalCode)
		{
			string inputPostalCode;
			cout << "Enter your postal code : ";

			getline(cin, inputPostalCode);

			for (int i = 0; i < 100; i++)
			{
				coustomer.postalCode[i] = inputPostalCode[i];
				if (inputPostalCode[i] == '\0')
				{
					break;
				}
			}

			if (!testPostalCode(coustomer.postalCode))
			{
				errorMessage();
			}
			else
			{
				flagForPpostalCode = false;
			}
		}	

		return coustomer;
	}

	bool testPostalCode(char postalCode[])
	{
		bool outcome = true;
		int index = 0;
		int i;
		char tempPostalCode[8] = { 0 };

		for (i = 0; i < 3 && outcome; i++)
		{
			if (postalCode[index] == '\0' ||
				postalCode[index] == ' ' ||
				postalCode[index] == '\t')
			{
				outcome = false;
			}
			else
			{
				tempPostalCode[i] = toupper(postalCode[index]);
				index++;
			}
		}

		if (outcome)
		{
			if (postalCode[index] != ' ' && postalCode[index] != '\t')
			{
				outcome = false;
			}
			else
			{
				tempPostalCode[3] = ' ';

				do
				{
					index++;

				} while (postalCode[index] == ' ' || postalCode[index] == '\t');


				if (postalCode[index] == '\0')
				{

					outcome = false;
				}
				else
				{
					for (i = 0; i < 3 && outcome; i++)
					{
						if (postalCode[index + i] == '\0' ||
							postalCode[index + i] == ' ' ||
							postalCode[index + i] == '\t')
						{
							outcome = false;
						}
						else
						{
							tempPostalCode[4 + i] = toupper(postalCode[index + i]);
						}
					}

					if (outcome)
					{
						if (postalCode[index + i] != '\0')
						{
							outcome = false;
						}
						else
						{
							tempPostalCode[7] = '\0';
							strcpy(postalCode, tempPostalCode);
						}
					}
				}
			}
		}
		return outcome;
	}

	bool testCharContainDigit(const char* string)
	{
		bool outcome = false;
		int count = 0;
		for (int i = 0; i < strlen(string); i++)
		{
			
			if (isdigit(string[i]))
			{
				count++;
			}
		}
		if (count > 0)
		{
			outcome = true;
		}
		return outcome;
	}

	bool testCharContainOthers(const char* string) 
	{

		bool outcome = false;
		int count = 0;

		for (int i = 0; i < strlen(string); i++)
		{
			if (string[i] == '\0' || string[i] == ' ' || string[i] == '\t')
			{
				count++;
			}
		}
		if (count>0)
		{
			outcome = true;
		}

		return outcome;
	
	}
	
	void errorMessage()
	{
	
		cout << "Invalid Entry: " << endl;
	}

	void display() 
	{
	
		cout << "You entered:" << endl;
		cout << coustomer.firstName << " " << coustomer.lastName << endl;
		cout << coustomer.address<<"," << endl;
		cout << coustomer.city << "," << coustomer.province << "," << endl;
		cout << coustomer.postalCode << endl;
	
	}

}