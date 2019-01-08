#ifndef PAGE_BOOTLOADER_H
#define PAGE_BOOTLOADER_H

#include <QWizardPage>

class QRadioButton;
class QVBoxLayout;
class QSpacerItem;
class PageBootloader : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageBootloader(QWidget *parent = nullptr);
    ~PageBootloader();

private:
    QVBoxLayout  *layBootloader;
    QRadioButton *rbnBLYes;
    QRadioButton *rbnBLNo;
    QSpacerItem  *vspBootloader;
};
#endif // PAGE_BOOTLOADER_H
