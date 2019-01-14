#include "PageShell.h"

#include <QVBoxLayout>
#include <QRadioButton>
#include <QSpacerItem>

PageShell::PageShell(QWidget *parent)
:
QWizardPage(parent),
layShell(new QVBoxLayout(this)),
rbnBash(new QRadioButton(this)),
rbnZsh(new QRadioButton(this)),
rbnFish(new QRadioButton(this)),
vspShell(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding))
{
    layShell->setSizeConstraint(QLayout::SetNoConstraint);
    layShell->setContentsMargins(0, 0, 0, 0);

    rbnBash->setChecked(true);

    rbnBash->setText("bash");
    rbnZsh->setText("zsh");
    rbnFish->setText("fish");

    layShell->addWidget(rbnBash);
    layShell->addWidget(rbnZsh);
    layShell->addWidget(rbnFish);
    layShell->addItem(vspShell);

    setLayout(layShell);
    setTitle(tr("Shell"));
    setSubTitle(tr("Chose one"));
    setPixmap(QWizard::LogoPixmap, QIcon(":/icons/utilities-terminal.png").pixmap(48, 48));
}
PageShell::~PageShell()
{
}
