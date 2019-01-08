#ifndef PAGE_KBMODEL_H
#define PAGE_KBMODEL_H

#include <QWizardPage>

class QVBoxLayout;
class PageKbModel : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageKbModel(QWidget *parent = nullptr);
    ~PageKbModel();

private:
    QVBoxLayout *layKbModel;
};

#endif // PAGE_KBMODEL_H
