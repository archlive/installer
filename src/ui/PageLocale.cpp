#include "PageLocale.h"
#include "Locale.h"

#include <QComboBox>
#include <QLabel>
#include <QListWidget>
#include <QFormLayout>

#include <QFile>
#include <QLocale>
#include <QTextStream>

#include <algorithm>

PageLocale::PageLocale(QWidget *parent)
:
QWizardPage(parent),
layLocale(new QGridLayout(this)),
lblCountry(new QLabel(this)),
lblEncoding(new QLabel(this)),
lblLanguage(new QLabel(this)),
lblLocale(new QLabel(this)),
lblLanguageTag(new QLabel(this)),
lblVariant(new QLabel(this)),
cbxCountry(new QComboBox(this)),
cbxEncoding(new QComboBox(this)),
cbxVariant(new QComboBox(this)),
lstLanguage(new QListWidget(this)),
currentLanguage(nullptr)
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
    layLocale->addWidget(lblLanguageTag, 4, 1, 1, 1);

    lblCountry->setText(tr("Country"));
    lblLanguage->setText(tr("Language"));
    lblLocale->setText(tr("Locale"));
    lblEncoding->setText(tr("Encoding"));
    lblVariant->setText(tr("Variant"));

    setLayout(layLocale);
    setTitle(tr("Welcome"));
    setSubTitle(tr("Please choose your locale language"));
    setPixmap(QWizard::LogoPixmap, QIcon(":/icons/locale.png").pixmap(48, 48));

    loadLanguagesFromDB();
//  db.makeIconScript();

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
bool PageLocale::isComplete() const
{
    return !lblLanguageTag->text().isEmpty();
}
void PageLocale::onLanguageChanged(const QString &)
{
    using namespace Locale;

    cbxCountry->clear();

    QVariant variant;
    QString iconPath, countryName, countryId;
    currentLanguage =
            lstLanguage->currentItem()->data(Qt::UserRole).value<LanguagePtr>();

    for (CountryPtr country : currentLanguage->countries())
    {
        countryId   = country->id();
        countryName = db.countryNames().key(countryId);

        if (countryId.isEmpty())
            countryId = currentLanguage->id();

        iconPath = ":/icons/flags/" + countryId + ".png";
        variant.setValue(country);
        cbxCountry->addItem(QIcon(iconPath), countryName, variant);
    }
    cbxCountry->model()->sort(0);
//  updateCurrentLanguageTag() is called from onVariantChanged
}
void PageLocale::onCountryChanged(int index)
{
    if (index == -1)
        return;

    using namespace Locale;

    cbxEncoding->clear();

    QVariant variant;
    CountryPtr country = cbxCountry->currentData().value<CountryPtr>();

    for (EncodingPtr encoding : country->encodings())
    {
        variant.setValue(encoding);
        cbxEncoding->addItem(encoding->name(), variant);
    }
    cbxEncoding->model()->sort(0);
    cbxEncoding->setCurrentIndex(cbxEncoding->count() - 1);
}
void PageLocale::onEncodingChanged(int index)
{
    if (index == -1)
        return;

    using namespace Locale;

    cbxVariant->clear();

    QVariant variant;
    EncodingPtr encoding = cbxEncoding->currentData().value<EncodingPtr>();

    for (VariantPtr variantPtr : encoding->variants())
        cbxVariant->addItem(variantPtr->name, variantPtr->implicit);
}
void PageLocale::onVariantChanged(int index)
{
    if (index == -1)
        return;

    updateCurrentLanguageTag();
}
void PageLocale::loadLanguagesFromDB()
{
    QListWidgetItem *itmLanguage = nullptr;

    for (Locale::LanguagePtr language : db.languages())
    {
        itmLanguage = new QListWidgetItem(language->name(), lstLanguage);
        QVariant variant;
        variant.setValue(language);
        itmLanguage->setData(Qt::UserRole, variant);
        lstLanguage->addItem(itmLanguage);
    }
    lstLanguage->sortItems();
}
void PageLocale::updateCurrentLanguageTag()
{
    using namespace Locale;

    if (!currentLanguage)
        return;

    lblLanguageTag->clear();

    QVariant    variant;
    EncodingPtr encoding;

    QString text       = currentLanguage->id(),
            countryId  = QString(),
            variantId  = QString();

    if (cbxCountry->currentIndex() > -1)
    {
        countryId = cbxCountry->currentData().value<CountryPtr>()->id();
        if (!countryId.isEmpty())
            text += '_' + countryId;
    }
    if (cbxEncoding->currentIndex() > -1)
    {
        encoding = cbxEncoding->currentData().value<EncodingPtr>();
    }
    if (cbxVariant->currentIndex() > -1)
    {
        bool implicit = cbxVariant->currentData().toBool();
        if (encoding && !implicit)
            text += '.' + encoding->name();

        variantId = cbxVariant->currentText();
        if (!variantId.isEmpty())
            text += '@' + variantId;
    }
    lblLanguageTag->setText(text);

    emit completeChanged();
}
QString PageLocale::languageTag() const
{
    return lblLanguageTag->text();
}
