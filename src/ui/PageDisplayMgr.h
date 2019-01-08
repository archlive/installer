#ifndef PAGE_DISPLAYMGR_H
#define PAGE_DISPLAYMGR_H

#include <QWizardPage>

class QRadioButton;
class QSpacerItem;
class QVBoxLayout;
class PageDisplayMgr : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageDisplayMgr(QWidget *parent = nullptr);
    ~PageDisplayMgr();

private:
    QVBoxLayout  *layDisplayMgr;
    QRadioButton *rbnDefaultDm;
    QRadioButton *rbnGdm;
    QRadioButton *rbnLightdm;
    QRadioButton *rbnLxdm;
    QRadioButton *rbnSddm;
    QSpacerItem  *vspDisplayMgr;
};
#endif // PAGE_DISPLAYMGR_H
