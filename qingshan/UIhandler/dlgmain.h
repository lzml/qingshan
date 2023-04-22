
#ifndef DLGMAIN_H
#define DLGMAIN_H


#include <QObject>


class DlgMain : public QObject
{
    Q_OBJECT
public:
    explicit DlgMain(QObject *parent = nullptr);

signals:


public:
    Q_INVOKABLE bool isVisiblePicture();

};

#endif // DLGMAIN_H
