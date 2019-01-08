#ifndef PAGE_DESKTOPMGR_H
#define PAGE_DESKTOPMGR_H

#include <QWizardPage>

class QRadioButton;
class QSpacerItem;
class QVBoxLayout;
class PageDesktopMgr : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageDesktopMgr(QWidget *parent = nullptr);
    ~PageDesktopMgr();

private:
    QVBoxLayout  *layDesktopMgr;
    QRadioButton *rbnGnome;
    QRadioButton *rbnLxde;
    QRadioButton *rbnLxqt;
    QRadioButton *rbnOpenbox;
    QRadioButton *rbnPlasma;
    QRadioButton *rbnXfce4;
    QSpacerItem  *vspDesktopMgr;
};
#endif // PAGE_DESKTOPMGR_H
