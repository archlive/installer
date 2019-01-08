#include "PageKbLayout.h"

#include <QVBoxLayout>

PageKbLayout::PageKbLayout(QWidget *parent)
:
QWizardPage(parent)
{
    layKbLayout = new QVBoxLayout(this);
    layKbLayout->setSizeConstraint(QLayout::SetNoConstraint);
    layKbLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(layKbLayout);

    setTitle(tr("Keyboard Layout"));
    setSubTitle(tr("Select your keyboard layout"));
}
PageKbLayout::~PageKbLayout()
{
}
