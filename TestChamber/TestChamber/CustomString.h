#pragma once
class CustomString
{
public:
	CustomString();
	CustomString(const char* input);
	~CustomString();
	void Insert(int index, const char* input);
	void Replace(int index, char replacement);
	void ReplaceRange(int begin, const char* replacement);
	char GetIndexAt(int index);
	char* Split(CustomString* str, char seperator);
	void Clear();
	char* End();
	char* Begin();
	void Print();
	int FindCharacterInString(char character);
	bool IsEmpty();
	void PrintHelper();
	char* GetFromIndex(int index);


private:
	int HelperPtrDistance;
	char* HelperPtr;
	char* Data;
	size_t Size;
	int Length;
	void Fill(int begin, int length, const char* input);
	int GetLengthOfArray(const char* input);

};


