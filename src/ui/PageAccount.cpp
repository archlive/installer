#include "PageAccount.h"

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>

PageAccount::PageAccount(QWidget *parent)
:
QWizardPage(parent),
layAccount(new QGridLayout(this)),
lblHostname(new QLabel(this)),
lblUsername(new QLabel(this)),
lblUserPw(new QLabel(this)),
lblUserPwConfirm(new QLabel(this)),
lblRootPw(new QLabel(this)),
lblRootPwConfirm(new QLabel(this)),
txtHostname(new QLineEdit(this)),
txtUsername(new QLineEdit(this)),
txtUserPw(new QLineEdit(this)),
txtUserPwConfirm(new QLineEdit(this)),
txtRootPw(new QLineEdit(this)),
txtRootPwConfirm(new QLineEdit(this)),
rbnLoginAuto(new QRadioButton(this)),
rbnLogin(new QRadioButton(this))
{
    layAccount->setSizeConstraint(QLayout::SetNoConstraint);
    layAccount->setContentsMargins(0, 0, 0, 0);

    txtUserPw->setEchoMode(QLineEdit::Password);
    txtRootPw->setEchoMode(QLineEdit::Password);
    txtUserPwConfirm->setEchoMode(QLineEdit::Password);
    txtRootPwConfirm->setEchoMode(QLineEdit::Password);

    rbnLogin->setChecked(true);

    lblHostname->setText(tr("Hostname:"));
    lblUsername->setText(tr("Username:"));
    lblUserPw->setText(tr("User password:"));
    lblUserPwConfirm->setText(tr("Confirm user password:"));
    lblRootPw->setText(tr("Root password:"));
    lblRootPwConfirm->setText(tr("Confirm root password:"));
    rbnLogin->setText(tr("Require password to log in"));
    rbnLoginAuto->setText(tr("Log in automatically"));

    layAccount->addWidget(lblHostname, 0, 1, 1, 1);
    layAccount->addWidget(txtHostname, 0, 2, 1, 1);
    layAccount->addWidget(lblUsername, 1, 1, 1, 1);
    layAccount->addWidget(txtUsername, 1, 2, 1, 1);
    layAccount->addWidget(lblUserPw, 2, 1, 1, 1);
    layAccount->addWidget(txtUserPw, 2, 2, 1, 1);
    layAccount->addWidget(lblUserPwConfirm, 3, 1, 1, 1);
    layAccount->addWidget(txtUserPwConfirm, 3, 2, 1, 1);
    layAccount->addWidget(lblRootPw, 4, 1, 1, 1);
    layAccount->addWidget(txtRootPw, 4, 2, 1, 1);
    layAccount->addWidget(lblRootPwConfirm, 5, 1, 1, 1);
    layAccount->addWidget(txtRootPwConfirm, 5, 2, 1, 1);
    layAccount->addWidget(rbnLogin, 6, 2, 1, 1);
    layAccount->addWidget(rbnLoginAuto, 7, 2, 1, 1);

    setLayout(layAccount);
    setTitle(tr("Login Details"));
    setSubTitle(tr("Enter hostname, username and passwords for the system"));
}
PageAccount::~PageAccount()
{
}
