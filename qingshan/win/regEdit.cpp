#include "regEdit.h"



bool regEdit::regKeyExist(HKEY key, QString subKey)
{
	HKEY hKey;
	bool ret = (RegOpenKeyExW(key, subKey.toStdWString().c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS);
	if (ret)
	{
		RegCloseKey(hKey);
	}
	return	ret;
}

bool regEdit::regNewKey(HKEY key, QString subKey)
{
	HKEY hKey;
	bool bRet = (ERROR_SUCCESS == RegCreateKeyExW(key, subKey.toStdWString().c_str(), 0, 0, 0, 0, 0, &hKey, 0));
	if (bRet)
	{
		RegCloseKey(hKey);
	}
	return bRet;
}

QString regEdit::regReadStringValue(HKEY key, QString subKey, QString valueName, QString defaultRet, DWORD dwsamDesired)
{
	HKEY hKey;
	if (RegOpenKeyExW(key, subKey.toStdWString().c_str(), 0, dwsamDesired, &hKey) != ERROR_SUCCESS)
	{
		return defaultRet;
	}
	DWORD rtype, rsize;
	auto cleanUp = qScopeGuard([&] {
		::RegCloseKey(hKey);
		});
	Q_UNUSED(cleanUp);
	if (ERROR_SUCCESS == RegQueryValueExW(hKey, valueName.toStdWString().c_str(), 0, &rtype, NULL, &rsize))
	{
		if (REG_SZ != rtype)
		{
			return defaultRet;
		}

		wchar_t* ret = (wchar_t*)malloc(rsize + 2);
		memset(ret, 0, rsize + 2);
		auto cleanUp2 = QScopeGuard([&] {
			::free(ret);
			});
		Q_UNUSED(cleanUp2);
		if (ERROR_SUCCESS == RegQueryValueExW(hKey, valueName.toStdWString().c_str(), 0, &rtype, (LPBYTE)ret, &rsize))
		{
			QString sret;
			sret = sret.fromWCharArray(ret);
			return sret;
		}


	}
	return	defaultRet;
}



DWORD regEdit::RegReadDWORDValue(HKEY key, QString subkey, QString valuename, DWORD defaultret)
{
	HKEY hKey;
	auto cleanUp = qScopeGuard([&] {
		::RegCloseKey(hKey);
		});
	Q_UNUSED(cleanUp);

	if (RegOpenKeyExW(key,
		subkey.toStdWString().c_str(),
		0,
		KEY_READ,
		&hKey) != ERROR_SUCCESS
		)
	{
		return defaultret;
	}


	DWORD rtype, rsize, ret;
	if (ERROR_SUCCESS == RegQueryValueExW(hKey, valuename.toStdWString().c_str(), 0, &rtype, NULL, &rsize))
	{
		if (REG_DWORD != rtype)
			return defaultret;
		if (ERROR_SUCCESS == RegQueryValueExW(hKey, valuename.toStdWString().c_str(), 0, &rtype, (LPBYTE)(&ret), &rsize))
		{
			return ret;
		}
	}

	return defaultret;
}

bool regEdit::RegWriteStringValue(HKEY key, QString subkey, QString valuename, QString valuedata)
{
	HKEY hKey;
	auto cleanUp = qScopeGuard([&] { ::RegCloseKey(hKey); });
	Q_UNUSED(cleanUp);
	if (RegOpenKeyExW(key,
		subkey.toStdWString().c_str(),
		0,
		KEY_READ | KEY_WRITE,
		&hKey) != ERROR_SUCCESS
		)
		return false;
	return (ERROR_SUCCESS ==
		RegSetValueExW(hKey, valuename.toStdWString().c_str(), 0, REG_SZ,
			(const BYTE*)valuedata.toStdWString().c_str(), valuedata.length() * 2 + 4));
}

bool regEdit::RegWriteDWORDValue(HKEY key, QString subkey, QString valuename, DWORD valuedata)
{
	HKEY hKey;
	auto cleanUp = qScopeGuard([&] { ::RegCloseKey(hKey); });
	Q_UNUSED(cleanUp);
	if (RegOpenKeyExW(key,
		subkey.toStdWString().c_str(),
		0,
		KEY_READ | KEY_WRITE,
		&hKey) != ERROR_SUCCESS
		)
		return false;
	return (ERROR_SUCCESS ==
		RegSetValueExW(hKey, valuename.toStdWString().c_str(), 0, REG_DWORD, (const BYTE*)(&valuedata), sizeof(DWORD)));
}

