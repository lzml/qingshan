
#include "dlgmain.h"
#include "../win/regEdit.h"
#include "stringTable.h"

/*
文件夹的注册表操作来源：  https://github.com/ifooth/Remove-6-Extra-Folders-from-Windows-10-This-PC
*/




DlgMain::DlgMain(QObject *parent)
    : QObject{parent}
{
    initCheckFromReg();

}

void DlgMain::initCheckFromReg()
{
    QString subKey, valueName;
    subKey = subKey.fromUtf16(REG_pictures_path);
    valueName = valueName.fromUtf16(Reg_ThisPCPolicy);
    if (!regEdit::getInstance()->regKeyExist(
        HKEY_LOCAL_MACHINE, subKey))
    {
        m_checkPic = 2;
    }
    else
    {  
        QString strRet = regEdit::getInstance()->regReadStringValue(HKEY_LOCAL_MACHINE, subKey, valueName, 0);
        if (strRet.compare(str_Show, Qt::CaseInsensitive) == 0)
        {
            m_checkPic = 1;
        }
        else
        {
            m_checkPic = 0;
        }
    }
}

void DlgMain::setRegFromCheck()
{
    QString subKey, valueName;
    subKey = subKey.fromUtf16(REG_pictures_path);
    valueName = valueName.fromUtf16(Reg_ThisPCPolicy);
    if (!regEdit::getInstance()->regKeyExist(
        HKEY_LOCAL_MACHINE, subKey))
    {
        return;
    }
    else
    {
        if (m_checkPic)
        {
            regEdit::getInstance()->RegWriteStringValue(HKEY_LOCAL_MACHINE, subKey, valueName, QString().fromUtf16(str_Show));
        }
        else
        {
            regEdit::getInstance()->RegWriteStringValue(HKEY_LOCAL_MACHINE, subKey, valueName, QString().fromUtf16(str_Hide));
        }
        
    }
}



uint DlgMain::checkPic() const
{
    return m_checkPic;
}

void DlgMain::setCheckPic(uint newCheckPic)
{
    if (m_checkPic == newCheckPic)
        return;
    m_checkPic = newCheckPic;

    //修改注册表
    setRegFromCheck();

    emit checkPicChanged();
}

//bool DlgMain::isVisiblePicture()
//{
    
//	if (regEdit::getInstance()->regKeyExist(HKEY_CURRENT_USER, QString().fromUtf16(REG_pictures_path)))
//	{

//	}

//    return true;
//}


