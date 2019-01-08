#ifndef PAGE_DRIVE_H
#define PAGE_DRIVE_H

#include <QWizardPage>

class QVBoxLayout;
class PageDrive : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageDrive(QWidget *parent = nullptr);
    ~PageDrive();

private:
    QVBoxLayout *layDrive;
};

#endif // PAGE_DRIVE_H
