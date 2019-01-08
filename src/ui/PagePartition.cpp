#include "PagePartition.h"

#include <QVBoxLayout>
#include <QRadioButton>
#include <QSpacerItem>

PagePartition::PagePartition(QWidget *parent)
:
QWizardPage(parent),
layPartition(new QVBoxLayout(this)),
rbnAuto(new QRadioButton(this)),
rbnManual(new QRadioButton(this)),
vspPartition(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding))
{
    layPartition->setSizeConstraint(QLayout::SetNoConstraint);
    layPartition->setContentsMargins(0, 0, 0, 0);

    rbnAuto->setChecked(true);
    rbnAuto->setText(tr("Automatic"));

    rbnManual->setText(tr("Manual"));

    layPartition->addWidget(rbnAuto);
    layPartition->addWidget(rbnManual);
    layPartition->addItem(vspPartition);

    setLayout(layPartition);
    setTitle(tr("Partitioning"));
    setSubTitle(tr("Please choose a partition method.<br>"
                   "Automatic partitioning will completely erase the selected disk."));
}
PagePartition::~PagePartition()
{
}
