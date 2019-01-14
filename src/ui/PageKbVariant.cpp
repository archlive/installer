#include "PageKbVariant.h"

#include <QIcon>
#include <QVBoxLayout>

PageKbVariant::PageKbVariant(QWidget *parent)
:
QWizardPage(parent)
{
    layKbVariant = new QVBoxLayout(this);
    layKbVariant->setSizeConstraint(QLayout::SetNoConstraint);
    layKbVariant->setContentsMargins(0, 0, 0, 0);
    setLayout(layKbVariant);

    setTitle(tr("Keyboard Variant"));
    setSubTitle(tr("Select your preferred keyboard variant"));
    setPixmap(QWizard::LogoPixmap, QIcon(":/icons/input-keyboard.png").pixmap(48, 48));
}
PageKbVariant::~PageKbVariant()
{
}
