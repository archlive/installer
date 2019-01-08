#ifndef PAGE_ACCOUNT_H
#define PAGE_ACCOUNT_H

#include <QWizardPage>

class QGridLayout;
class QLabel;
class QLineEdit;
class QRadioButton;
class PageAccount : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageAccount(QWidget *parent = nullptr);
    ~PageAccount();

private:
    QGridLayout  *layAccount;
    QLabel       *lblHostname;
    QLabel       *lblUsername;
    QLabel       *lblUserPw;
    QLabel       *lblUserPwConfirm;
    QLabel       *lblRootPw;
    QLabel       *lblRootPwConfirm;
    QLineEdit    *txtHostname;
    QLineEdit    *txtUsername;
    QLineEdit    *txtUserPw;
    QLineEdit    *txtUserPwConfirm;
    QLineEdit    *txtRootPw;
    QLineEdit    *txtRootPwConfirm;
    QRadioButton *rbnLoginAuto;
    QRadioButton *rbnLogin;
};
#endif // PAGE_ACCOUNT_H
