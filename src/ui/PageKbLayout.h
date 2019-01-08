#ifndef PAGE_KBLAYOUT_H
#define PAGE_KBLAYOUT_H

#include <QWizardPage>

class QVBoxLayout;
class PageKbLayout : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageKbLayout(QWidget *parent = nullptr);
    ~PageKbLayout();

private:
    QVBoxLayout *layKbLayout;
};

#endif // PAGE_KBLAYOUT_H
