#include "regEdit.h"



bool regEdit::RegKeyExist(HKEY key, QString&& subKey)
{
	HKEY hKey;
	bool ret = (RegOpenKeyExW(key, subKey.toStdWString().c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS);
	if (ret)
	{
		RegCloseKey(hKey);
	}
	return	ret;
}
