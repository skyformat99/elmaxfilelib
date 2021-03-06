#pragma once

#include <string>
#include <cstdio>

#include "../../Common/Enumeration.h"
#include "../../Common/Common.h"

namespace Elmax
{

class BaseTextWriter
{
public:
	BaseTextWriter(void);
	virtual ~BaseTextWriter(void);

	virtual bool Open(const std::wstring& file, FILE_OP op) = 0;
	void Close();

	virtual bool Write( const std::wstring& text ) = 0;

	virtual bool WriteLine( const std::wstring& text ) = 0;

	void Flush();

	int GetLastError(std::wstring& str);
	void ClearLastError();

protected:
	BaseTextWriter(const BaseTextWriter&) {}

	bool ContentsToFile( 
		const wchar_t* pszSource, 
		size_t nSource, 
		wchar_t*& pszDest,
		size_t& nDest	);

	bool ContainsNewline(const wchar_t* text, size_t len);

	bool IsBigEndian() {return isBigEndian;}

	bool WriteRaw(const wchar_t* arr, size_t size, bool writeBigEndian);
	bool WriteRaw(unsigned int* arr, size_t size, bool writeBigEndian);
	bool WriteRaw(unsigned short* arr, size_t size, bool writeBigEndian);

	FILE* fp;

	std::wstring err;
	int errNum;
	bool isBigEndian;
};

}
