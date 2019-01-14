#include "PageVirtualBox.h"

#include <QLabel>
#include <QSpacerItem>
#include <QRadioButton>
#include <QVBoxLayout>

PageVirtualBox::PageVirtualBox(QWidget *parent)
:
QWizardPage(parent),
layVirtualBox(new QVBoxLayout(this)),
lblVboxInfo(new QLabel(this)),
rbnVboxYes(new QRadioButton(this)),
rbnVboxNo(new QRadioButton(this)),
vspVbox(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding))
{
    layVirtualBox->setSizeConstraint(QLayout::SetNoConstraint);
    layVirtualBox->setContentsMargins(0, 0, 0, 0);

    lblVboxInfo->setText("<!DOCTYPE html><html><head></head><body><p>" +
        tr("The Installer has detected that system is running in VirtualBox.<br>"
        "Would you like to install VirtualBox guest utilities to the installed system?") +
        "</p></body></html>");

    rbnVboxYes->setChecked(true);
    rbnVboxYes->setText(tr("Yes"));
    rbnVboxNo->setText(tr("No"));

    layVirtualBox->addWidget(lblVboxInfo);
    layVirtualBox->addWidget(rbnVboxYes);
    layVirtualBox->addWidget(rbnVboxNo);
    layVirtualBox->addItem(vspVbox);

    setLayout(layVirtualBox);
    setTitle(tr("VirtualBox"));
    setSubTitle(tr("Install VirtualBox guest utilities"));
    setPixmap(QWizard::LogoPixmap, QIcon(":/icons/virtualbox.png").pixmap(48, 48));
}
PageVirtualBox::~PageVirtualBox()
{
}
