#ifndef PAGE_SUBZONE_H
#define PAGE_SUBZONE_H

#include <QWizardPage>

class QVBoxLayout;
class PageSubZone : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageSubZone(QWidget *parent = nullptr);
    ~PageSubZone();

private:
    QVBoxLayout *laySubZone;
};

#endif // PAGE_SUBZONE_H
