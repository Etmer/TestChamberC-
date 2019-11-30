#include "CustomString.h"
#include <iostream>

int HelperPtrIndex = 0;
char* HelperPtr = nullptr;
char* Data = nullptr;
int Length = 0;
size_t Size = 0;

CustomString::CustomString()
{
}

CustomString::CustomString(const char* input)
{
	Length = GetLengthOfArray(input);
	Size = Length + 1;
	Data = new char[Size * 2];
	Fill(0, Length, input);
	Data[Size - 1] = '\0';
	HelperPtr = Begin();

}

CustomString::~CustomString()
{
}

void CustomString::Insert(int index, const char* input)
{
	int inputLength = GetLengthOfArray(input);
	int dataLength = GetLengthOfArray(Data);
	int beginningPoint = dataLength + inputLength;

	for (int i = beginningPoint - 1; i > index; --i)
	{
		char replacementChar = Data[i - inputLength];
		Data[i] = replacementChar;
	}
	Fill(index, inputLength, input);
	int endIndex = dataLength + inputLength;
	Data[endIndex] = '\0';
}

void CustomString::Replace(int index, char replacement)
{
	Data[index] = replacement;
}

void CustomString::ReplaceRange(int begin, const char* replacement)
{
	int inputLength = GetLengthOfArray(replacement);
	if (Length + inputLength > Size)
	{

	}
	int itr = 0;

	for (int i = begin; i < begin + inputLength; ++i)
	{
		Data[i] = replacement[itr];
		++itr;
	}
}

char CustomString::GetIndexAt(int index)
{  
	try 
	{
		TryGetIndex(index);
	}
	catch (const char* msg) 
	{
		std::cout << msg << std::endl;
	}
	return Data[index];
}

char* CustomString::Split(CustomString* str, char seperator)
{
	if (str != nullptr)
	{
		int itr = 0;
		while (Data[itr] != '\0')
		{
			if (Data[itr] == seperator)
			{
				HelperPtrIndex = itr + 1;
				Data[itr] = '\0';
				HelperPtr = Begin() + HelperPtrIndex;
				return Data;
			}
			++itr;
		}
	}
	else 
	{

		HelperPtr = Begin() + HelperPtrIndex;
		int itr = 0;
		while (HelperPtr[itr] != '\0')
		{
			if (HelperPtr[itr] == seperator)
			{
				HelperPtrIndex = HelperPtrIndex + itr + 1;
				HelperPtr[itr] = '\0';
				return HelperPtr;
			}
			++itr;
		}
		HelperPtrIndex = HelperPtrIndex + itr;
		if (HelperPtr != End()) 
		{
			HelperPtrIndex = HelperPtrIndex + 1;
			return HelperPtr;
		}
		return nullptr;
	}
}

void CustomString::Clear()
{
	delete Data;
	Data = new char[1];
	Length = 0;
	Size = Length + 1;
	Data[Size - 1] = '\0';
}

char* CustomString::End()
{
	return Data + Size;
}

char* CustomString::Begin()
{
	return Data;
}

void CustomString::Print()
{
	std::cout << Data << std::endl;
}

int CustomString::FindCharacterInString(char character)
{
	int itr = 0;
	int amount = 0;
	while (Data[itr] != '\0')
	{
		if (Data[itr] == character)
		{
			++amount;
		}
	}
	return amount;
}

void CustomString::Fill(int begin, int length, const char* input)
{
	int index = 0;
	for (int i = begin; i != begin + length; ++i)
	{
		Data[i] = input[index];
		++index;
	}
}

int CustomString::GetLengthOfArray(const char* input)
{
	int itr = 0;
	while (input[itr] != '\0')
	{
		++itr;
	}

	return itr;
}


bool CustomString::IsEmpty()
{
	return Length == 0;
}

void CustomString::PrintHelper()
{
	std::cout << HelperPtr << std::endl;
}

char* CustomString::GetFromIndex(int index)
{
	return Begin() + index;
}

void CustomString::Rename(const char* replacement)
{

}

void CustomString::ToUpper()
{
	int itr = 0;
	while (Data[itr]) 
	{
		if (isalpha(Data[itr])) 
		{
			Data[itr] = Data[itr] &~ 32;
		}
		++itr;
	}
}

void CustomString::ToLower()
{
	int itr = 0;
	while (Data[itr])
	{
		if (isalpha(Data[itr]))
		{
			Data[itr] = Data[itr] | 32;
		}
		++itr;
	}
}

void CustomString::Capitalize()
{
	if (Length > 0) 
	{
		Data[0] = Data[0] & ~32;
	}
}

size_t CustomString::GetSize()
{
	return Size;
}

CustomString CustomString::operator+(CustomString const& obj)
{ 
	size_t bufferSize = (Length + obj.Length) + 1;
	char* buffer = new char[bufferSize];

	int index = 0;
	for (int i = 0; i < Length;++i) 
	{
		buffer[index] = Data[i];
		++index;
	}
	
	for (int i = 0; i < obj.Length; ++i)
	{
		buffer[index] = obj.Data[i];
		++index;
	}
	buffer[bufferSize -1] = '\0';

	return CustomString(buffer);
}

char CustomString::TryGetIndex(int index)
{
	if (index >= Length) 
	{
		throw "Index out of bounds Exception";
	}
	return Data[index];
}

