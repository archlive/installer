#ifndef PAGE_KBVARIANT_H
#define PAGE_KBVARIANT_H

#include <QWizardPage>

class QVBoxLayout;
class PageKbVariant : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageKbVariant(QWidget *parent = nullptr);
    ~PageKbVariant();

private:
    QVBoxLayout *layKbVariant;
};

#endif // PAGE_KBVARIANT_H
