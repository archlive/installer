#ifndef INSTALLER_H
#define INSTALLER_H

#include <QWizard>

class Installer : public QWizard
{
    Q_OBJECT

enum {idLocale, idPartition, idDrive, idKbModel, idKbLayout, idKbVariant,
     idZone, idSubZone, idTime, idAccount, idShell, idKernel, idVirtualBox,
     idUtils, idDisplayMgr, idDesktopMgr, idBootloader};

public:
    explicit Installer(QWidget *parent = nullptr);
    ~Installer();

    int nextId() const;

private:

};
#endif // INSTALLER_H
