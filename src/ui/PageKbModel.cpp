#include "PageKbModel.h"

#include <QIcon>
#include <QVBoxLayout>

PageKbModel::PageKbModel(QWidget *parent)
:
QWizardPage(parent)
{
    layKbModel = new QVBoxLayout(this);
    layKbModel->setSizeConstraint(QLayout::SetNoConstraint);
    layKbModel->setContentsMargins(0, 0, 0, 0);
    setLayout(layKbModel);

    setTitle(tr("Keyboard Model"));
    setSubTitle(tr("Select your keyboard model"));
    setPixmap(QWizard::LogoPixmap, QIcon(":/icons/input-keyboard.png").pixmap(48, 48));
}
PageKbModel::~PageKbModel()
{
}
