#include "PageKbModel.h"

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
}
PageKbModel::~PageKbModel()
{
}
