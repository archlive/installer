#ifndef PAGE_PARTITION_H
#define PAGE_PARTITION_H

#include <QWizardPage>

class QRadioButton;
class QSpacerItem;
class QVBoxLayout;
class PagePartition : public QWizardPage
{
    Q_OBJECT

public:
    explicit PagePartition(QWidget *parent = nullptr);
    ~PagePartition();

private:
    QVBoxLayout *layPartition;
    QRadioButton *rbnAuto;
    QRadioButton *rbnManual;
    QSpacerItem  *vspPartition;
};

#endif // PAGE_PARTITION_H
