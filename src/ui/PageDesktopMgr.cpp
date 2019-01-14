#include "PageDesktopMgr.h"

#include <QRadioButton>
#include <QSpacerItem>
#include <QVBoxLayout>

PageDesktopMgr::PageDesktopMgr(QWidget *parent)
:
QWizardPage(parent),
layDesktopMgr(new QVBoxLayout(this)),
rbnGnome(new QRadioButton(this)),
rbnLxde(new QRadioButton(this)),
rbnLxqt(new QRadioButton(this)),
rbnOpenbox(new QRadioButton(this)),
rbnPlasma(new QRadioButton(this)),
rbnXfce4(new QRadioButton(this)),
vspDesktopMgr(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding))
{
    layDesktopMgr->setSizeConstraint(QLayout::SetNoConstraint);
    layDesktopMgr->setContentsMargins(0, 0, 0, 0);

    rbnLxde->setChecked(true);

    rbnGnome->setText("gnome");
    rbnLxde->setText("lxde");
    rbnLxqt->setText("lxqt");
    rbnOpenbox->setText("openbox");
    rbnPlasma->setText("plasma");
    rbnXfce4->setText("xfce4");

    layDesktopMgr->addWidget(rbnGnome);
    layDesktopMgr->addWidget(rbnLxde);
    layDesktopMgr->addWidget(rbnLxqt);
    layDesktopMgr->addWidget(rbnOpenbox);
    layDesktopMgr->addWidget(rbnPlasma);
    layDesktopMgr->addWidget(rbnXfce4);
    layDesktopMgr->addItem(vspDesktopMgr);

    setLayout(layDesktopMgr);
    setTitle(tr("Desktop Manager"));
    setSubTitle(tr("Choose which one to install"));
    setPixmap(QWizard::LogoPixmap, QIcon(":/icons/user-desktop.png").pixmap(48, 48));
}
PageDesktopMgr::~PageDesktopMgr()
{
}
