
#include "dlgmain.h"
#include "../win/regEdit.h"

DlgMain::DlgMain(QObject *parent)
    : QObject{parent}
{

}

bool DlgMain::isVisiblePicture()
{
    
    //regEdit::getInstance()->RegKeyExist(HKEY_CURRENT_USER, );

    return true;
}

