#pragma once
class CustomString
{
public:
	CustomString();
	CustomString(CustomString& input);
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
	char& operator[](int index);
	int FindAmountOfCharactersInString(char character);
	bool IsEmpty();
	void PrintHelper();
	char* GetFromIndex(int index);
	void Rename(const char* replacement);
	void ToUpper();
	void ToLower();
	void Capitalize(); 
	size_t GetSize();
	CustomString operator + (CustomString const& obj);
	CustomString* Copy();

private:
	bool FindIndex(int index);
	char TryGetIndex(int index);
	int HelperPtrDistance;
	char* HelperPtr; 
	char* Data;
	size_t Size;
	int Length;
	void Fill(int begin, int length, const char* input);
	int GetLengthOfArray(const char* input);

};


