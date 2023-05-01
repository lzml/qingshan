#pragma once
#include "afx.h"
#include "libMta/libMta.h"

class regEdit : public libMta::Singleton<regEdit>
{
public:

	bool RegKeyExist(HKEY key, QString&& subKey);
private:

};

