#include "PageTime.h"

#include <QVBoxLayout>
#include <QRadioButton>
#include <QSpacerItem>

PageTime::PageTime(QWidget *parent)
:
QWizardPage(parent)
{
    layTime = new QVBoxLayout(this);
    layTime->setSizeConstraint(QLayout::SetNoConstraint);
    layTime->setContentsMargins(0, 0, 0, 0);

    rbnUtc = new QRadioButton(this);
    rbnUtc->setChecked(true);
    rbnUtc->setText("utc");

    rbnLocalTime = new QRadioButton(this);
    rbnLocalTime->setText("localtime");

    vspTime = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    layTime->addWidget(rbnUtc);
    layTime->addWidget(rbnLocalTime);
    layTime->addItem(vspTime);

    setLayout(layTime);
    setTitle(tr("Time"));
    setSubTitle(tr("Choose between UTC or Local Time.<br>"
                   "UTC is recommended unless you are dual booting with Windows."));
    setPixmap(QWizard::LogoPixmap, QIcon(":/icons/clock.png").pixmap(48, 48));
}
PageTime::~PageTime()
{
}
