#ifndef PAGE_VIRTUALBOX_H
#define PAGE_VIRTUALBOX_H

#include <QWizardPage>

class QLabel;
class QRadioButton;
class QSpacerItem;
class QVBoxLayout;
class PageVirtualBox : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageVirtualBox(QWidget *parent = nullptr);
    ~PageVirtualBox();

private:
    QVBoxLayout  *layVirtualBox;
    QLabel       *lblVboxInfo;
    QRadioButton *rbnVboxYes;
    QRadioButton *rbnVboxNo;
    QSpacerItem  *vspVbox;
};
#endif // PAGE_VIRTUALBOX_H
