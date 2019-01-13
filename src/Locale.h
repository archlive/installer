#ifndef LOCALEDB_H
#define LOCALEDB_H

#include <QMap>
#include <QMetaType>
#include <QString>
#include <vector>
#include <memory>

/**
    Custom Locale functions and classes namespace.

    Currently QLocale has some limitations/non updated database,
    so here some text database based classes and functions to manipulate
    locale language tags, using ISO-639 language names, and ISO-3166 country names.

    https://en.wikipedia.org/wiki/IETF_language_tag
    Language tags are (currently in this code, not following
    the https://tools.ietf.org/html/bcp47 standard as
    lang[-script][-country][-codeset][-modifier] but same
    as QLocale and used in /etc/locale-gen) formed by sub-tags as following:

@code
     language[_country[.codeset]][@modifier]
@endcode

    language: ISO-639  2 or 3 lowercase letters code
    country:  ISO-3166 2 uppercase letters code
    codeset:  a character set or encoding identifier like ISO-8859-1 or UTF-8
    modifiers:

    These are effectively free-form, but the existing modifiers in glibc
    break down into:

    - a particular currency, e.g. en_IE@euro
    - a non-default script, e.g. uz_UZ@cyrillic, be_BY@latin
    - a dialect or variant of the language, e.g. aa_ER@saaho, ca_ES@valencia
    - a non-default collation rule, e.g. gez_ER@abegede
*/
namespace Locale
{
    struct Variant
    {
        bool implicit = false;
        QString name = "";
    };
    typedef std::shared_ptr<Variant> VariantPtr;

    class Encoding
    {
    public:
        Encoding();
        Encoding(const QString &name);
        Encoding(const Encoding &);
        ~Encoding(){}

        QString name() const {return name_;}
        std::vector<VariantPtr> variants() const {return variants_;}

        void addVariant(const VariantPtr &variant)
        {
            variants_.push_back(variant);
        }
        bool operator==(const Encoding &other) const
        {
            return (name_    == other.name_    &&
                    variants_== other.variants_);
        }
        bool operator!=(const Encoding &other) const
        {
            return !(*this == other);
        }
        Encoding & operator=(const Encoding &other)
        {
            name_    = other.name_;
            variants_= other.variants_;
            return *this;
        }

    private:
        QString name_;
        std::vector<VariantPtr> variants_;
    };
    typedef std::shared_ptr<Encoding> EncodingPtr;

    class Country
    {
    public:
        Country();
        Country(const QString &id);
        Country(const Country &);
        ~Country(){}

        QString id() const {return id_;}
        std::vector<EncodingPtr> encodings() const {return encodings_;}

        void addEncoding(const EncodingPtr &encoding)
        {
            encodings_.push_back(encoding);
        }
        bool operator==(const Country &other) const
        {
            return (id_== other.id_ && encodings_== other.encodings_);
        }
        bool operator!=(const Country &other) const
        {
            return !(*this == other);
        }
        Country & operator=(const Country &other)
        {
            id_       = other.id_;
            encodings_= other.encodings_;
            return *this;
        }

    private:
        QString id_;
        std::vector<EncodingPtr> encodings_;
    };
    typedef std::shared_ptr<Country> CountryPtr;
/**
    A class to store data from an ISO-693-3 table from
    https://iso639-3.sil.org/code_tables/download_tables
*/
    class Language
    {
    public:
        Language();
        Language(const QString &id);
        Language(const Language &);
        ~Language(){}

        QString id()   const {return id_;}
        QString name() const {return name_;}

        std::vector<CountryPtr> countries() const {return countries_;}

        void setName(const QString &name) {name_= name;}

        void addCountry(const CountryPtr &country)
        {
            countries_.push_back(country);
        }
        bool operator==(const Language &other) const
        {
            return (id_       == other.id_   &&
                    name_     == other.name_ &&
                    countries_== other.countries_);
        }
        bool operator!=(const Language &other) const
        {
            return !(*this == other);
        }
        Language & operator=(const Language &other)
        {
            id_       = other.id_;
            name_     = other.name_;
            countries_= other.countries_;
            return *this;
        }

    private:
        QString              id_;
        QString              name_;
        std::vector<CountryPtr> countries_;
    };
    typedef std::shared_ptr<Language> LanguagePtr;

    class DataBase
    {
    public:
        DataBase();
        ~DataBase();

        std::vector<LanguagePtr> languages()    const {return languages_;}
        QMap<QString, QString>   countryNames() const {return countryNames_;}
/**
    Utility to create a script to create the flag icons directory
    from the Flag Icons by GoSquared (http://www.gosquared.com/)
    flags-iso/flat/64 directory inside the flags.zip archive.
    The script must be moved manually in the unzipped directory and also some
    missing flag icon like eo.png should be added.
*/
        void makeIconScript();

    private:
        void registerLanguageTagsFromLocaleGen();

        QMap<QString, QStringList> parseLanguageDB();
        void parseCountryDB();

        std::vector<LanguagePtr> languages_;    // Languages tree
        QMap<QString, QString>   countryNames_; // <countryCode> <countryName>
    };
} // namespace Locale

Q_DECLARE_METATYPE(Locale::LanguagePtr);
Q_DECLARE_METATYPE(Locale::CountryPtr);
Q_DECLARE_METATYPE(Locale::EncodingPtr);

#endif // LOCALEDB_H
