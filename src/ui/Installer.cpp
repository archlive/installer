#include "Installer.h"
#include "PageAccount.h"
#include "PageBootloader.h"
#include "PageDesktopMgr.h"
#include "PageDisplayMgr.h"
#include "PageDrive.h"
#include "PageKbLayout.h"
#include "PageKbModel.h"
#include "PageKbVariant.h"
#include "PageKernel.h"
#include "PageLocale.h"
#include "PagePartition.h"
#include "PageShell.h"
#include "PageSubZone.h"
#include "PageTime.h"
#include "PageUtils.h"
#include "PageVirtualBox.h"
#include "PageZone.h"

#include <QIcon>

Installer::Installer(QWidget *parent)
:
QWizard(parent)
{
    setOptions(QWizard::NoBackButtonOnStartPage);
    setWizardStyle(QWizard::ModernStyle);
    setWindowIcon(QIcon(":/icons/arch.png"));
    setWindowTitle(tr("Arch Installer"));
    resize(510, 480);

    setPage(idLocale,     new PageLocale(this));
    setPage(idPartition,  new PagePartition(this));
    setPage(idDrive,      new PageDrive(this));
    setPage(idKbModel,    new PageKbModel(this));
    setPage(idKbLayout,   new PageKbLayout(this));
    setPage(idKbVariant,  new PageKbVariant(this));
    setPage(idZone,       new PageZone(this));
    setPage(idSubZone,    new PageSubZone(this));
    setPage(idTime,       new PageTime(this));
    setPage(idAccount,    new PageAccount(this));
    setPage(idShell,      new PageShell(this));
    setPage(idKernel,     new PageKernel(this));
    setPage(idVirtualBox, new PageVirtualBox(this));
    setPage(idUtils,      new PageUtils(this));
    setPage(idDisplayMgr, new PageDisplayMgr(this));
    setPage(idDesktopMgr, new PageDesktopMgr(this));
    setPage(idBootloader, new PageBootloader(this));
}
Installer::~Installer()
{
}
int Installer::nextId() const
{
    int id = currentId();
    if (id == idLocale)
    {
        return idPartition;
    }
    else if (id == idPartition)
    {
        return idDrive;
    }
    else if (id == idDrive)
    {
        return idKbModel;
    }
    else if (id == idKbModel)
    {
        return idKbLayout;
    }
    else if (id == idKbLayout)
    {
        return idKbVariant;
    }
    else if (id == idKbVariant)
    {
        return idZone;
    }
    else if (id == idZone)
    {
        return idSubZone;
    }
    else if (id == idSubZone)
    {
        return idTime;
    }
    else if (id == idTime)
    {
        return idAccount;
    }
    else if (id == idAccount)
    {
        return idShell;
    }
    else if (id == idShell)
    {
        return idKernel;
    }
    else if (id == idKernel)
    {
        return idVirtualBox;
    }
    else if (id == idVirtualBox)
    {
        return idUtils;
    }
    else if (id == idUtils)
    {
        return idDisplayMgr;
    }
    else if (id == idDisplayMgr)
    {
        return idDesktopMgr;
    }
    else if (id == idDesktopMgr)
    {
        return idBootloader;
    }
//  else if (id == idBootloader)
    return -1;
}
