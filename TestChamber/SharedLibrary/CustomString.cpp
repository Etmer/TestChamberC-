#include "pch.h"

#include "CustomString.h"
#include <iostream>

CustomString::CustomString()
{
	Length = 0;
	Size = Length;
}

CustomString::CustomString(CustomString const& input)
{
	Length = GetLengthOfArray(input.Data);
	size_t buffer = 10;
	Size = Length + 1;
	Data = new char[buffer + Size];
	Fill(0, Length, input.Data);
	Data[Size - 1] = '\0';
	HelperPtr = Begin();
}

CustomString::CustomString(const char* input)
{
	Length = GetLengthOfArray(input);
	size_t buffer = 10;
	Size =  Length + 1;
	Data = new char[buffer + Size];
	Fill(0, Length, input);
	Data[Size - 1] = '\0';
	HelperPtr = Begin();

}

CustomString::~CustomString()
{
	delete[] Data;
}

void CustomString::Insert(int index, const char* input)
{
	int inputLength = GetLengthOfArray(input);
	int dataLength = GetLengthOfArray(Data);
	int beginningPoint = dataLength + inputLength;

	if (inputLength >= Length)
	{
		size_t tempSize = (Length + inputLength) * 2;
		char* c = new char[tempSize + 1];
		int itr = 0;
		while (Data[itr] != '\0')
		{
			c[itr] = Data[itr];
			++itr;
		}
		delete[] Data;
		Data = c;

	}
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
	if (begin + inputLength > Size)
	{
		size_t tempSize = (begin + inputLength) * 2;
		char* c = new char[tempSize + 1];
		int itr = 0;
		while (Data[itr] != '\0')
		{
			c[itr] = Data[itr];
			++itr;
		}
		delete[] Data;
		Data = c;
	}
	int itr = 0;

	for (int i = begin; i < begin + inputLength; ++i)
	{
		Data[i] = replacement[itr];
		++itr;
	}

	int endIndex = begin + inputLength;
	Data[endIndex] = '\0';
}

char CustomString::GetIndexAt(int index)
{
	if (index >= Length)
	{
		throw "Index out of bounds Exception";
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
	return nullptr;
}

void CustomString::Clear()
{
	delete[] Data;
	Length = 0;
	Size = 0;
	HelperPtr = nullptr;
	Data = nullptr;
}

char* CustomString::End()
{
	if (Length == 0)
	{
		return nullptr;
	}
	return Data + Size;
}

char* CustomString::Begin()
{
	if (Length == 0) 
	{
		return nullptr;
	}
	return Data;
}

void CustomString::Print()
{
	std::cout << Data << std::endl;
}
char &CustomString::operator [](int index)
{
	return Data[index];
}

int CustomString::FindAmountOfCharactersInString(char character)
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


void CustomString::Rename(char const& replacement)
{
	size_t tempSize = sizeof(replacement);
	int i = 0;
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

	CustomString c(buffer);

	delete[]buffer;

	return c;
}
CustomString CustomString::operator=(CustomString const& obj)
{
	if (Begin() != nullptr)
	{
		Clear();
	}	
	Length = GetLengthOfArray(obj.Data);
	size_t buffer = 10;
	Size = Length + 1;
	Data = new char[buffer + Size];
	Fill(0, Length, obj.Data);
	Data[Size - 1] = '\0';
	HelperPtr = Begin();
	return *this;
}

CustomString* CustomString::Copy()
{
	return new CustomString(Data);
}

bool CustomString::FindIndex(int index)
{
	if (index >= Length)
	{
		throw "Index out of bounds Exception";
	}
	return true;
}

char CustomString::TryGetIndex(int index)
{
	try
	{
		GetIndexAt(index);
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
		return Data[0];
	}
	return Data[index];
}

