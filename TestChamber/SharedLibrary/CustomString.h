#pragma once
class CustomString
{
public:
	CustomString();
	CustomString(CustomString const& input);
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
	void Rename(char const& replacement);
	void ToUpper();
	void ToLower();
	void Capitalize(); 
	size_t GetSize();
	CustomString operator + (CustomString const& obj);
	CustomString operator=(CustomString const& obj);
	CustomString* Copy();
	char TryGetIndex(int index);

private:
	bool FindIndex(int index);
	int HelperPtrIndex = 0;
	char* HelperPtr = nullptr;
	char* Data = nullptr;
	int Length = 0;
	size_t Size = 0;
	void Fill(int begin, int length, const char* input);
	int GetLengthOfArray(const char* input);

};


