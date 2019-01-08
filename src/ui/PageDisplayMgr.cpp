#include "PageDisplayMgr.h"

#include <QRadioButton>
#include <QSpacerItem>
#include <QVBoxLayout>

PageDisplayMgr::PageDisplayMgr(QWidget *parent)
:
QWizardPage(parent),
layDisplayMgr(new QVBoxLayout(this)),
rbnDefaultDm(new QRadioButton(this)),
rbnGdm(new QRadioButton(this)),
rbnLightdm(new QRadioButton(this)),
rbnLxdm(new QRadioButton(this)),
rbnSddm(new QRadioButton(this)),
vspDisplayMgr(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding))
{
    layDisplayMgr->setSizeConstraint(QLayout::SetNoConstraint);
    layDisplayMgr->setContentsMargins(0, 0, 0, 0);

    rbnDefaultDm->setChecked(true);
    rbnDefaultDm->setText("default");
    rbnGdm->setText("gdm");
    rbnLightdm->setText("lightdm");
    rbnLxdm->setText("lxdm");
    rbnSddm->setText("sddm");

    layDisplayMgr->addWidget(rbnDefaultDm);
    layDisplayMgr->addWidget(rbnGdm);
    layDisplayMgr->addWidget(rbnLightdm);
    layDisplayMgr->addWidget(rbnLxdm);
    layDisplayMgr->addWidget(rbnSddm);
    layDisplayMgr->addItem(vspDisplayMgr);

    setLayout(layDisplayMgr);
    setTitle(tr("Display Manager"));
    setSubTitle(tr("Choose which one to use"));
}
PageDisplayMgr::~PageDisplayMgr()
{
}
