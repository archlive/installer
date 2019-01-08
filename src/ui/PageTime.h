#ifndef PAGE_TIME_H
#define PAGE_TIME_H

#include <QWizardPage>

class QVBoxLayout;
class QRadioButton;
class QSpacerItem;
class QVBoxLayout;
class PageTime : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageTime(QWidget *parent = nullptr);
    ~PageTime();

private:
    QVBoxLayout  *layTime;
    QRadioButton *rbnUtc;
    QRadioButton *rbnLocalTime;
    QSpacerItem  *vspTime;
};

#endif // PAGE_TIME_H
