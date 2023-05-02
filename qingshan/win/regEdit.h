#pragma once
#include "afx.h"
#include "libMta/libMta.h"

class regEdit : public libMta::Singleton<regEdit>
{
public:

	bool regKeyExist(HKEY key, QString subKey);
	bool regNewKey(HKEY key, QString subKey);

	QString regReadStringValue(HKEY key, QString subKey, QString valueName, QString defaultRet, DWORD dwsamDesired = KEY_READ);

	DWORD RegReadDWORDValue(HKEY key, QString subkey, QString valuename, DWORD defaultret);

	bool RegWriteStringValue(HKEY key, QString subkey, QString valuename, QString valuedata);

	bool RegWriteDWORDValue(HKEY key, QString subkey, QString valuename, DWORD valuedata);
};

