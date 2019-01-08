#ifndef PAGE_KERNEL_H
#define PAGE_KERNEL_H

#include <QWizardPage>

class QLabel;
class QRadioButton;
class QSpacerItem;
class QVBoxLayout;
class PageKernel : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageKernel(QWidget *parent = nullptr);
    ~PageKernel();

private:
    QVBoxLayout  *layKernel;
    QLabel       *lblKernelDesc;
    QRadioButton *rbnLinux;
    QRadioButton *rbnLts;
    QRadioButton *rbnHardened;
    QSpacerItem  *vspKernel;
};

#endif // PAGE_KERNEL_H
