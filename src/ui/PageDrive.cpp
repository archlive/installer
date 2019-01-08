#include "PageDrive.h"

#include <QVBoxLayout>

PageDrive::PageDrive(QWidget *parent)
:
QWizardPage(parent)
{
    layDrive = new QVBoxLayout(this);
    layDrive->setSizeConstraint(QLayout::SetNoConstraint);
    layDrive->setContentsMargins(0, 0, 0, 0);
    setLayout(layDrive);

    setTitle(tr("Install media"));
    setSubTitle(tr("Select the drive you want to use for installation"));
}
PageDrive::~PageDrive()
{
}
