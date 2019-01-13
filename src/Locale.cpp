#include "Locale.h"

#include <QFile>
#include <QTextStream>
#include <algorithm>

namespace Locale
{
Encoding::Encoding()
:
name_(QString())
{
}
Encoding::Encoding(const QString &name)
:
name_(name)
{
}
Encoding::Encoding(const Encoding &other)
:
name_(other.name_),
variants_(other.variants_)
{
}
Country::Country()
:
id_(QString())
{
}
Country::Country(const QString &id)
:
id_(id)
{
}
Country::Country(const Country &other)
:
id_(other.id_),
encodings_(other.encodings_)
{
}
Language::Language()
:
id_(QString()),
name_(QString())
{
}
Language::Language(const QString &id)
:
id_(id),
name_(QString())
{
}
Language::Language(const Language &other)
:
id_(other.id_),
name_(other.name_),
countries_(other.countries_)
{
}
DataBase::DataBase()
{
    registerLanguageTagsFromLocaleGen();
}
DataBase::~DataBase()
{
}
void DataBase::registerLanguageTagsFromLocaleGen()
{
    QFile inputFile("/etc/locale.gen");
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        in.setCodec("UTF-8");
        QString line;

        parseCountryDB();
        QMap<QString, QStringList> mapLanguageNames = parseLanguageDB();

        while (!in.atEnd())
        {
            line = in.readLine().trimmed();
            if ((line.size() > 7) && (line.left(2) != "# "))
            {
                line.remove(QChar('#'));
                QStringList languageIds,
                            tagEncPair = line.split(' ');

                QString languageId,
                        encodingName = tagEncPair.at(1);
                QStringList tagList  = tagEncPair.at(0).split('@');
                QString tagString    = tagList.at(0);

                VariantPtr variantPtr(new Variant());
                if (tagList.size() > 1)
                    variantPtr->name = tagList.at(1);

                variantPtr->implicit = !tagString.contains('.');

                tagList   = tagString.split('.');
                tagString = tagList.at(0); // lang + country

                tagList   = tagString.split('_');
                languageId = tagList.at(0);

                QString countryId;
                if (tagList.size() > 1)
                    countryId= tagList.at(1);

                LanguagePtr languagePtr(new Language(languageId));
                CountryPtr  countryPtr (new Country(countryId));
                EncodingPtr encodingPtr(new Encoding(encodingName));

//              Find if the language with languageId is already present in vector
                auto languageItr = std::find_if(languages_.begin(), languages_.end(),
                    [&languageId](const LanguagePtr &language)
                {
                    return language->id() == languageId;
                });
                if (languageItr != languages_.end())
                {
                    languagePtr = *languageItr;
                }
                else
                {
                    for (QString languageName : mapLanguageNames.keys())
                    {
                        languageIds = mapLanguageNames.value(languageName);
                        if (languageIds.contains(languageId))
                        {
                            languagePtr->setName(languageName);
                            break;
                        }
                    }
                    languages_.push_back(languagePtr);
                }
//              Same for language countries vector
                auto countries = languagePtr->countries();
                auto countryItr = std::find_if(countries.begin(), countries.end(),
                    [&countryId](const CountryPtr &country)
                {
                    return country->id() == countryId;
                });
                if (countryItr != countries.end())
                    countryPtr = *countryItr;
                else
                    languagePtr->addCountry(countryPtr);

                auto encodings = countryPtr->encodings();
                auto encodingItr = std::find_if(encodings.begin(), encodings.end(),
                    [&encodingName](const EncodingPtr &encoding)
                {
                    return encoding->name() == encodingName;
                });
                if (encodingItr != encodings.end())
                    encodingPtr = *encodingItr;
                else
                    countryPtr->addEncoding(encodingPtr);

                encodingPtr->addVariant(variantPtr);
            }
        }
        inputFile.close();
    }
}
QMap<QString, QStringList> DataBase::parseLanguageDB()
{
    QFile db(":/iso-639-3_20181015.db");
    QMap<QString, QStringList> languages;

    if (db.open(QFile::ReadOnly))
    {
        QTextStream text(&db);
        text.setCodec("UTF-8");
        QStringList dataList, ids;

        while (!text.atEnd())
        {
//          dataList.at(0 to 3) is the code, 4 is type, 5 is scope, 6 the name
//          and 7 the comment which is ignored since not useful
            dataList = text.readLine().split('\t');

            for (int i = 0; i < 4; ++i)
                ids.append(dataList.at(i));

            languages.insert(dataList.at(6), ids);

            ids.clear();
        }
        db.close();
    }
    return languages;
}
void DataBase::parseCountryDB()
{
    QFile db(":/iso-3166-1_201212.db");

    if (db.open(QFile::ReadOnly))
    {
        QTextStream text(&db);
        text.setCodec("UTF-8");
        QStringList dataList;

        while (!text.atEnd())
        {
            dataList = text.readLine().split('|');
            countryNames_.insert(dataList.at(0), dataList.at(1));
        }
        db.close();
    }
}
void DataBase::makeIconScript()
{
    QFile outFile("./icons.sh");
    outFile.remove();
    if (outFile.open(QFile::ReadWrite))
    {
/*
        In order to get an ordered tagList with unique elements I use QMap with a
        dummy value instead of using an unordered, unique elements QSet to
        convert to QList and call .sort() to get it also ordered.
        Order is not required here, but useful for comparing.
*/
        QMap<QString, int> countryIds;
        QTextStream out(&outFile);
        out << "mkdir -p flags\n";

        for (LanguagePtr language : languages_)
        {
            for (CountryPtr country : language->countries())
            {
                QString countryId = country->id();
                if (countryId.isEmpty())
                    countryId = language->id();

                countryIds.insert(countryId, 0);
            }
        }
        for (QString countryId : countryIds.keys())
            out << "mv " << countryId << ".png ./flags\n";
/*
        Need to add all permissions even if e.g. ReadOther means anyone, so also
        owner and group, it tagString to a correct 755 instead of a wrong 205.
*/
        outFile.setPermissions(QFile::ReadOwner|QFile::ExeOwner|QFile::WriteOwner|
                               QFile::ReadGroup|QFile::ExeGroup|
                               QFile::ReadOther|QFile::ExeOther);
        outFile.close();
    }
}
} // namespace Locale
