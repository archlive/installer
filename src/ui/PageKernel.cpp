#include "PageKernel.h"

#include <QLabel>
#include <QRadioButton>
#include <QSpacerItem>
#include <QVBoxLayout>

PageKernel::PageKernel(QWidget *parent)
:
QWizardPage(parent),
layKernel(new QVBoxLayout(this)),
lblKernelDesc(new QLabel(this)),
rbnLinux(new QRadioButton(this)),
rbnLts(new QRadioButton(this)),
rbnHardened(new QRadioButton(this)),
vspKernel(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding))
{
    layKernel->setSizeConstraint(QLayout::SetNoConstraint);
    layKernel->setContentsMargins(0, 0, 0, 0);

    lblKernelDesc->setText("<!DOCTYPE html><html><head></head><body><p>"
        + tr("There are several kernels available for the system.<br><br>"
        "The most common is the current linux kernel.<br>"
        "This kernel is the most up to date, providing the best hardware support.<br>"
        "However, there could be possible bugs in this kernel, despite testing.<br><br>"
        "The linux-lts kernel provides a focus on stability.<br>"
        "It is based on an older kernel, so it may lack some newer features.<br><br>"
        "The linux-hardened kernel is focused on security<br>"
        "It contains the Grsecurity Patchset and PaX for increased security.") +
        "</p></body></html>");

    rbnLinux->setChecked(true);
    rbnLinux->setText("linux");
    rbnLts->setText("linux-lts");
    rbnHardened->setText("linux-hardened");

    layKernel->addWidget(lblKernelDesc);
    layKernel->addWidget(rbnLinux);
    layKernel->addWidget(rbnLts);
    layKernel->addWidget(rbnHardened);

    setLayout(layKernel);
    setTitle(tr("Kernel"));
    setSubTitle(tr("Choose a suitable kernel for your system"));
}
PageKernel::~PageKernel()
{
}
