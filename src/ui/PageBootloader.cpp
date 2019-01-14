#include "PageBootloader.h"

#include <QRadioButton>
#include <QSpacerItem>
#include <QVBoxLayout>

PageBootloader::PageBootloader(QWidget *parent)
:
QWizardPage(parent),
layBootloader(new QVBoxLayout(this)),
rbnBLYes(new QRadioButton(this)),
rbnBLNo(new QRadioButton(this)),
vspBootloader(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding))
{
    layBootloader->setSizeConstraint(QLayout::SetNoConstraint);
    layBootloader->setContentsMargins(0, 0, 0, 0);

    rbnBLYes->setChecked(true);
    rbnBLYes->setText(tr("Yes"));
    rbnBLNo->setText(tr("No"));

    layBootloader->addWidget(rbnBLYes);
    layBootloader->addWidget(rbnBLNo);
    layBootloader->addItem(vspBootloader);

    setLayout(layBootloader);
    setTitle(tr("Boot Loader"));
    setSubTitle(tr("Choose whether to install the bootloader"));
    setPixmap(QWizard::LogoPixmap, QIcon(":/icons/bootloader.png").pixmap(48, 48));
}
PageBootloader::~PageBootloader()
{
}
