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
/**
    Returns the current language tag for the choosen locale.
*/
    QString languageTag() const;

private:
    bool isComplete() const;

    void loadLanguagesFromDB();
    void updateCurrentLanguageTag();

    void onLanguageChanged(const QString &);
    void onCountryChanged(int);
    void onEncodingChanged(int);
    void onVariantChanged(int);

    QGridLayout *layLocale;
    QLabel      *lblCountry;
    QLabel      *lblEncoding;
    QLabel      *lblLanguage;
    QLabel      *lblLocale;
    QLabel      *lblLanguageTag;
    QLabel      *lblVariant;
    QComboBox   *cbxCountry;
    QComboBox   *cbxEncoding;
    QComboBox   *cbxVariant;
    QListWidget *lstLanguage;

    Locale::DataBase    db;
    Locale::LanguagePtr currentLanguage;
};

#endif // PAGELOCALE_H
