#ifndef PAGELOCALE_H
#define PAGELOCALE_H

#include "Locale.h"

#include <QMap>
#include <QWizardPage>

class QComboBox;
class QLabel;
class QListWidget;
class QListWidgetItem;
class QGridLayout;
class PageLocale : public QWizardPage
{
    Q_OBJECT

public:
    explicit PageLocale(QWidget *parent = nullptr);
    ~PageLocale();

    QString locale() const;

private:
    void initLanguages();
    void listLocaleNames();
    void updateLocaleName();
    void makeIconScript(); // Script to create the flag icons directory

    void onLanguageChanged(const QString &);
    void onCountryChanged(int);
    void onEncodingChanged(int);
    void onVariantChanged(int);

    QGridLayout *layLocale;
    QLabel      *lblCountry;
    QLabel      *lblEncoding;
    QLabel      *lblLanguage;
    QLabel      *lblLocale;
    QLabel      *lblLocaleTxt;
    QLabel      *lblVariant;
    QComboBox   *cbxCountry;
    QComboBox   *cbxEncoding;
    QComboBox   *cbxVariant;
    QListWidget *lstLanguage;

    QMap<QString, QString> localeNames; // /etc/locale.gen <locale> and <charset>s
    Locale::DataBase db;

    QString languageCode, countryCode, encoding, variant;
};

#endif // PAGELOCALE_H
