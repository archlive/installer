#include "PageLocale.h"
#include "Locale.h"

#include <QComboBox>
#include <QLabel>
#include <QListWidget>
#include <QFormLayout>

#include <QFile>
#include <QLocale>
#include <QTextStream>

PageLocale::PageLocale(QWidget *parent)
:
QWizardPage(parent),
layLocale(new QGridLayout(this)),
lblCountry(new QLabel(this)),
lblEncoding(new QLabel(this)),
lblLanguage(new QLabel(this)),
lblLocale(new QLabel(this)),
lblLocaleTxt(new QLabel(this)),
lblVariant(new QLabel(this)),
cbxCountry(new QComboBox(this)),
cbxEncoding(new QComboBox(this)),
cbxVariant(new QComboBox(this)),
lstLanguage(new QListWidget(this))
{
    layLocale->setSizeConstraint(QLayout::SetNoConstraint);
    layLocale->setContentsMargins(0, 0, 0, 0);

    layLocale->addWidget(lblLanguage, 0, 0, 1, 1);
    layLocale->addWidget(lstLanguage, 0, 1, 1, 1);
    layLocale->addWidget(lblCountry, 1, 0, 1, 1);
    layLocale->addWidget(cbxCountry, 1, 1, 1, 1);
    layLocale->addWidget(lblEncoding, 2, 0, 1, 1);
    layLocale->addWidget(cbxEncoding, 2, 1, 1, 1);
    layLocale->addWidget(lblVariant, 3, 0, 1, 1);
    layLocale->addWidget(cbxVariant, 3, 1, 1, 1);
    layLocale->addWidget(lblLocale, 4, 0, 1, 1);
    layLocale->addWidget(lblLocaleTxt, 4, 1, 1, 1);

    lblCountry->setText(tr("Country"));
    lblLanguage->setText(tr("Language"));
    lblLocale->setText(tr("Locale"));
    lblEncoding->setText(tr("Encoding"));
    lblVariant->setText(tr("Variant"));

    cbxCountry->setDisabled(true);
    cbxEncoding->setDisabled(true);
    cbxVariant->setDisabled(true);

    setLayout(layLocale);
    setTitle(tr("Welcome"));
    setSubTitle(tr("Please choose your locale language"));

    listLocaleNames();
//  makeIconScript();
    initLanguages();

    connect(lstLanguage, &QListWidget::currentTextChanged, this,
            &PageLocale::onLanguageChanged);

    connect(cbxCountry, QOverload<int>::of(&QComboBox::currentIndexChanged), this,
            &PageLocale::onCountryChanged);

    connect(cbxEncoding, QOverload<int>::of(&QComboBox::currentIndexChanged), this,
            &PageLocale::onEncodingChanged);

    connect(cbxVariant, QOverload<int>::of(&QComboBox::currentIndexChanged), this,
            &PageLocale::onVariantChanged);
}
PageLocale::~PageLocale()
{
}
void PageLocale::onLanguageChanged(const QString &language)
{
    cbxCountry->setEnabled(true);
    cbxCountry->clear();

    QMap<QString, QString> countries;

    QString localeLangCode, localeLanguage, country, countryCode_;

    foreach (QString localeName, localeNames.keys())
    {
        localeLangCode = Locale::languageCodeFromTag(localeName);
        localeLanguage = db.languageFromCode(localeLangCode);
        if (localeLanguage == language)
        {
            languageCode = lstLanguage->currentItem()->data(Qt::UserRole).toString();
            countryCode_= Locale::countryCodeFromTag(localeName);
            country = db.countryFromCode(countryCode_);
            countries.insert(country, countryCode_);
        }
    }
    foreach (QString country, countries.keys())
    {
        countryCode_= countries.value(country);
        QString iconPath = ":/icons/flags/" + countryCode_+ ".png";
        cbxCountry->addItem(QIcon(iconPath), country, countryCode_);
    }
    updateLocaleName();
}
void PageLocale::onCountryChanged(int index)
{
    cbxEncoding->setEnabled(true);
    cbxEncoding->clear();

    cbxVariant->setEnabled(true);
    cbxVariant->clear();

    countryCode = cbxCountry->itemData(index).toString();
    updateLocaleName();

    QMap<QString, bool> encodings;
    QMap<QString, bool> variants;

    QString temp, localeCode = lblLocaleTxt->text();
    int size = localeCode.size();

    foreach (QString localeName, localeNames.keys())
    {
        if (localeName.left(size) == localeCode)
        {
            if (localeName.contains('@'))
                variants.insert(localeName.split('@').last(), false);
            else
                variants.insert("", false);

//          Some tags does not includes the codeset tag and assumes it as implicit
//          so add it to the language tag only if specified
            bool hasEncodingTag = false;
            if (localeName.contains('.'))
                hasEncodingTag = true;

            encodings.insert(localeNames.value(localeName), hasEncodingTag);
        }
    }
    foreach (QString enc, encodings.keys())
    {
        bool hasEncodingTag = encodings.value(enc);
        cbxEncoding->blockSignals(true);
        cbxEncoding->addItem(enc, hasEncodingTag);
        cbxEncoding->blockSignals(false);
    }
    foreach (QString var, variants.keys())
    {
        cbxVariant->blockSignals(true);
        cbxVariant->addItem(var);
        cbxVariant->blockSignals(false);
    }
}
void PageLocale::onEncodingChanged(int index)
{
    if (index == -1)
        return;

    bool hasEncodingTag = cbxEncoding->itemData(index).toBool();
    if (hasEncodingTag)
        encoding = cbxEncoding->currentText();
    else
        encoding = "";

    updateLocaleName();
}
void PageLocale::onVariantChanged(int)
{
    variant = cbxVariant->currentText();
    updateLocaleName();
}
void PageLocale::initLanguages()
{
    QString language, langCode;
    QListWidgetItem *itmLanguage = nullptr;
    QMap<QString, QString> languages;

    foreach (QString localeName, localeNames.keys())
    {
        langCode = Locale::languageCodeFromTag(localeName);
        language = db.languageFromCode(langCode);
        languages.insert(language, langCode);
    }
    foreach (QString lang, languages.keys())
    {
        itmLanguage = new QListWidgetItem(lang, lstLanguage);
        itmLanguage->setData(Qt::UserRole, languages.value(lang));
        lstLanguage->addItem(itmLanguage);
    }
}
void PageLocale::listLocaleNames()
{
    QFile inputFile("/etc/locale.gen");
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        in.setCodec("UTF-8");
        QString line;
        QStringList pair; // <locale> and <charset>

        while (!in.atEnd())
        {
            line = in.readLine().trimmed();
            if ((line.size() > 10) && (line.left(2) != "# "))
            {
                line.remove(QChar('#'));
                pair = line.split(' ');
                localeNames.insert(pair.at(0), pair.at(1));
            }
        }
        inputFile.close();
    }
}
void PageLocale::updateLocaleName()
{
    lblLocaleTxt->clear();
    QString text = languageCode;

    if (!countryCode.isEmpty())
        text.append('_' + countryCode);

    if (!encoding.isEmpty())
        text.append('.' + encoding);

    if (!variant.isEmpty())
        text.append('@' + variant);

    lblLocaleTxt->setText(text);
}
void PageLocale::makeIconScript()
{
    QFile outFile("./icons.sh");
    outFile.remove();
    if (outFile.open(QIODevice::ReadWrite))
    {
/*
        In order to get an ordered and unique list I use QMap with a dummy value
        instead of using an unordered, unique elements QSet to convert to QList
        to get it also ordered.
        Order is not required here, just a reminder.
*/
        QMap<QString, int> countryCodes;
        QTextStream out(&outFile);
        out << "mkdir -p flags\n";

        foreach (QString localeName, localeNames.keys())
            countryCodes.insert(Locale::countryCodeFromTag(localeName), 0);

        foreach (QString countryCode, countryCodes.keys())
            out << "mv " << countryCode << ".png ./flags\n";
/*
        Need to add all permissions even if e.g. ReadOther means anyone, so also
        owner and group, it result to a correct 755 instead of a wrong 205.
*/
        outFile.setPermissions(QFile::ReadOwner|QFile::WriteOwner|QFile::ExeOwner|
                               QFile::ReadGroup|QFile::ExeGroup|QFile::ReadOther|QFile::ExeOther);
        outFile.close();
    }
}
QString PageLocale::locale() const
{
    return lblLocaleTxt->text();
}
