#include "PageZone.h"

#include <QVBoxLayout>

PageZone::PageZone(QWidget *parent)
:
QWizardPage(parent)
{
    layZone = new QVBoxLayout(this);
    layZone->setSizeConstraint(QLayout::SetNoConstraint);
    layZone->setContentsMargins(0, 0, 0, 0);
    setLayout(layZone);

    setTitle(tr("Country Zone"));
    setSubTitle(tr("Select your country / zone"));
}
PageZone::~PageZone()
{
}
