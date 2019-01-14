#include "PageSubZone.h"

#include <QIcon>
#include <QVBoxLayout>

PageSubZone::PageSubZone(QWidget *parent)
:
QWizardPage(parent)
{
    laySubZone = new QVBoxLayout(this);
    laySubZone->setSizeConstraint(QLayout::SetNoConstraint);
    laySubZone->setContentsMargins(0, 0, 0, 0);
    setLayout(laySubZone);

    setTitle(tr("Sub Zone"));
    setSubTitle(tr("Select your sub-zone"));
    setPixmap(QWizard::LogoPixmap, QIcon(":/icons/locale.png").pixmap(48, 48));
}
PageSubZone::~PageSubZone()
{
}
