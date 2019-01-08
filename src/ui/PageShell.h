#ifndef PAGE_SHELL_H
#define PAGE_SHELL_H

#include <QWizardPage>

class QRadioButton;
class QSpacerItem;
class QVBoxLayout;
class PageShell : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageShell(QWidget *parent = nullptr);
    ~PageShell();

private:
    QVBoxLayout  *layShell;
    QRadioButton *rbnBash;
    QRadioButton *rbnZsh;
    QRadioButton *rbnFish;
    QSpacerItem  *vspShell;
};

#endif // PAGE_SHELL_H
