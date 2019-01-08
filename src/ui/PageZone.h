#ifndef PAGE_ZONE_H
#define PAGE_ZONE_H

#include <QWizardPage>

class QVBoxLayout;
class PageZone : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageZone(QWidget *parent = nullptr);
    ~PageZone();

private:
    QVBoxLayout *layZone;
};

#endif // PAGE_ZONE_H
