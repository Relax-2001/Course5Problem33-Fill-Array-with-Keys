#include <iostream>
#include <cstdlib>

using namespace std;

enum enRandomizeChoice { SmallLetter = 1, CapitalLetter = 2, SpecialCharecter = 3, RandomDigit = 4 };

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int RandomNumber(int From, int To)
{

	int RandomNum = rand() % (To - From + 1) + From;

	return RandomNum;
}

char GenerateCharecter(enRandomizeChoice CharType)
{

	switch (CharType)
	{
	case enRandomizeChoice::SmallLetter:
		return char(RandomNumber(97, 122));
		break;

	case enRandomizeChoice::CapitalLetter:
		return char(RandomNumber(65, 90));
		break;

	case enRandomizeChoice::SpecialCharecter:
		return char(RandomNumber(33, 47));
		break;

	case enRandomizeChoice::RandomDigit:
		return char(RandomNumber(48, 57));
	}
}

string GenerateWord(enRandomizeChoice CharType, int Length)
{
	string Word = "";

	for (int i = 1; i <= Length; i++)
	{
		Word += GenerateCharecter(CharType);
	}

	return Word;

}

string GenerateKey()
{

	string Key = "";

	Key = GenerateWord(enRandomizeChoice::CapitalLetter, 4) + "-";
	Key += GenerateWord(enRandomizeChoice::CapitalLetter, 4) + "-";
	Key += GenerateWord(enRandomizeChoice::CapitalLetter, 4) + "-";
	Key += GenerateWord(enRandomizeChoice::CapitalLetter, 4);

	return Key;
}

void FillArrayWithGeneratedKeys(string Arr[100], int& ArryLength)
{

	for (int i = 0; i < ArryLength; i++)
	{
		Arr[i] = GenerateKey();
	}

}

void PrintArray(string Arr[100], int ArrayLength)
{
	cout << "Array elements: \n\n";

	for (int i = 0; i <= ArrayLength - 1; i++)
		cout << "Arr[" << i << "] : " << Arr[i] << "\n";



	cout << "\n";
}



int main()
{
	srand((unsigned)time(NULL));

	int ArrLength = 0;
	string Arr[100];

	ArrLength = ReadPositiveNumber("Enter number of keys to generate");

	FillArrayWithGeneratedKeys(Arr, ArrLength);

	PrintArray(Arr, ArrLength);



}