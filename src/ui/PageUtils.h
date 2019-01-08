#ifndef PAGE_UTILS_H
#define PAGE_UTILS_H

#include <QWizardPage>

class QCheckBox;
class QSpacerItem;
class QVBoxLayout;
class PageUtils : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageUtils(QWidget *parent = nullptr);
    ~PageUtils();

private:
    QVBoxLayout *layUtils;
    QCheckBox   *chkCups;
    QCheckBox   *chkFirefox;
    QCheckBox   *chkLibreoffice;
    QSpacerItem *vspUtils;
};
#endif // PAGE_UTILS_H
