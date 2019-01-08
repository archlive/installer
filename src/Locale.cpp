#include "Locale.h"

#include <QFile>
#include <QTextStream>

namespace Locale
{
QString languageCodeFromTag(const QString &name)
{
    return name.split('_').first();
}
QString countryCodeFromTag(const QString &name)
{
    QString
    country,
    filtered = name.split('.').first();     // Remove encoding
    filtered = filtered.split('@').first(); // Remove variant
    QStringList
        list = filtered.split('_');

    for (int i = 1; i < list.size(); ++i)
    {
        country = list.at(i);
        if (country.size() < 4) // If not script...
            return country;
    }
    return QString();
}
QString variantFromTag(const QString &name)
{
    QStringList list = name.split('@');
    if (list.size() > 1)
        return list.at(1);

    return QString();
}
Language::Language(const QString &id,      const QChar   &scope,  const QChar   &type,
                   const QString &refName, const QString &part2b, const QString &part2t,
                   const QString &part1/*, const QString &comment*/)
:
id_(id),
part2b_(part2b),
part2t_(part2t),
part1_(part1),
refName_(refName),
//comment_(comment),
scope_(scope),
type_(type)
{
}
Language::Language(const Language &other)
:
id_(other.id_),
part2b_(other.part2b_),
part2t_(other.part2t_),
part1_(other.part1_),
refName_(other.refName_),
//comment_(other.comment_),
scope_(other.scope_),
type_(other.type_)
{
}
Country::Country(const QString &name, const QString &code)
:
name_(name),
code_(code)
{
}
Country::Country(const Country &other)
:
name_(other.name_),
code_(other.code_)
{
}
DataBase::DataBase()
{
    initLanguages();
    initCountries();
}
DataBase::~DataBase()
{
}
void DataBase::initLanguages()
{
    QFile db(":/iso-639-3_20181015.db");
    if (db.open(QFile::ReadOnly))
    {
        QTextStream text(&db);
        text.setCodec("UTF-8");
        QStringList dataList;
        while (!text.atEnd())
        {
            dataList = text.readLine().split('\t');
            // TODO: "comment" is skipped, no comments in database currently.
            Language lang(dataList.at(0), dataList.at(4).at(0), dataList.at(5).at(0),
                          dataList.at(6), dataList.at(1), dataList.at(2), dataList.at(3));
            languages_.push_back(lang);
        }
        db.close();
    }
}
void DataBase::initCountries()
{
    QFile db(":/iso-3166-1_201212.db");
    if (db.open(QFile::ReadOnly))
    {
        QTextStream text(&db);
        text.setCodec("UTF-8");
        QStringList dataList;
        while (!text.atEnd())
        {
            dataList = text.readLine().split(',');
            Country country(dataList.at(0), dataList.at(1));
            countries_.push_back(country);
        }
        db.close();
    }
}
QString DataBase::languageFromCode(const QString &languageCode) const
{
    for (unsigned i = 0; i < languages_.size(); ++i)
    {
        if ((languages_.at(i).id()     == languageCode) ||
            (languages_.at(i).part2b() == languageCode) ||
            (languages_.at(i).part2t() == languageCode) ||
            (languages_.at(i).part1 () == languageCode))
        {
            return languages_.at(i).refName();
        }
    }
    return QString();
}
QString DataBase::countryFromCode(const QString &countryCode) const
{
    for (unsigned i = 0; i < countries_.size(); ++i)
    {
        if (countries_.at(i).code() == countryCode)
            return countries_.at(i).name();
    }
    return QString();
}
} // namespace Locale
