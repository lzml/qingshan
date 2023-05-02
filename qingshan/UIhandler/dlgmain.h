
#ifndef DLGMAIN_H
#define DLGMAIN_H


#include <QObject>


class DlgMain : public QObject
{
    Q_OBJECT
public:
    explicit DlgMain(QObject *parent = nullptr);

signals:
    void checkPicChanged();




public:
   // Q_INVOKABLE bool getPictureStatus();


    void initCheckFromReg();
    void setRegFromCheck();




    uint checkPic() const;
    void setCheckPic(uint newCheckPic);

private:
    uint m_checkPic;
    Q_PROPERTY(uint checkPic READ checkPic WRITE setCheckPic NOTIFY checkPicChanged)
};

#endif // DLGMAIN_H
