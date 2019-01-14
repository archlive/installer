#include "PageUtils.h"

#include <QCheckBox>
#include <QSpacerItem>
#include <QVBoxLayout>

PageUtils::PageUtils(QWidget *parent)
:
QWizardPage(parent),
layUtils(new QVBoxLayout(this)),
chkCups(new QCheckBox(this)),
chkFirefox(new QCheckBox(this)),
chkLibreoffice(new QCheckBox(this)),
vspUtils(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding))
{
    layUtils->setSizeConstraint(QLayout::SetNoConstraint);
    layUtils->setContentsMargins(0, 0, 0, 0);

    chkCups->setText(tr("Printer Support (cups)"));
    chkFirefox->setText(tr("Firefox Browser"));
    chkLibreoffice->setText(tr("LibreOffice"));

    layUtils->addWidget(chkCups);
    layUtils->addWidget(chkFirefox);
    layUtils->addWidget(chkLibreoffice);
    layUtils->addItem(vspUtils);

    setLayout(layUtils);
    setTitle(tr("Utilities"));
    setSubTitle(tr("Choose which support utilities to install"));
    setPixmap(QWizard::LogoPixmap, QIcon(":/icons/applications-utilities.png").pixmap(48, 48));
}
PageUtils::~PageUtils()
{
}
