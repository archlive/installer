#ifndef LOCALEDB_H
#define LOCALEDB_H

#include <QString>
#include <vector>

/**
    Custom Locale functions and classes namespace.

    Currently QLocale has some limitations/non updated database,
    so here some text database based classes and functions to manipulate
    locale language tags, using ISO-639 language names, and ISO-3166 country names.
    ISO-15924 scripts management is missing.

    https://en.wikipedia.org/wiki/IETF_language_tag
    Language tags are (currently in this code, not following
    the https://tools.ietf.org/html/bcp47 standard as
    lang[-script][-country][-codeset][-modifier] but same
    as QLocale and used in /etc/locale-gen) formed by sub-tags as following:

@code
    lang[_script][_country][.codeset][@modifier]
@endcode

    lang:    ISO-639   2 or 3 lowercase letters code
    script:  ISO-15924 4 capitalized letters code
    country: ISO-3166  2 uppercase letters code

    E.g.: it_Ital_IT.UTF-8@latin

*/
namespace Locale
{
/**
    Returns an ISO639 2 letters language code from a BCP47/RFC5646 language tag
*/
    QString languageCodeFromTag(const QString &);
/**
    Returns an ISO3166 2 letters country code from a BCP47/RFC5646 language tag
*/
    QString countryCodeFromTag(const QString &);
/**
    Returns a language variant from a BCP47/RFC5646 language tag
    (e.g.: @valencia, excluding the '@')
*/
    QString variantFromTag(const QString &);
/**
    A class to store data from an ISO-693-3 table from
    https://iso639-3.sil.org/code_tables/download_tables

@code
CREATE TABLE [ISO_639-3] (
    Id      char(3) NOT NULL, -- The three-letter 639-3 identifier
    Part2B  char(3) NULL,     -- Equivalent 639-2 identifier of the bibliographic applications
                              -- code set, if there is one
    Part2T  char(3) NULL,     -- Equivalent 639-2 identifier of the terminology applications code
                              -- set, if there is one
    Part1   char(2) NULL,     -- Equivalent 639-1 identifier, if there is one
    Scope   char(1) NOT NULL, -- I(ndividual), M(acrolanguage), S(pecial)
    Type    char(1) NOT NULL, -- A(ncient), C(onstructed),
                              -- E(xtinct), H(istorical), L(iving), S(pecial)
    Ref_Name   varchar(150) NOT NULL, -- Reference language name
    Comment    varchar(150) NULL)     -- Comment relating to one or more of the columns
@endcode
*/
    class Language
    {
    public:
        Language(const QString &id, const QChar &scope, const QChar &type,
               const QString &refName,
               const QString &part2b  = QString(),
               const QString &part2t  = QString(),
               const QString &part1   = QString());
    //         const QString &comment = QString());
        Language(const Language &);
        ~Language(){}

        QString id()      const {return id_;}
        QString part2b()  const {return part2b_;}
        QString part2t()  const {return part2t_;}
        QString part1()   const {return part1_;}
        QString refName() const {return refName_;}
    //  QString comment() const {return comment_;}
        QChar   scope()   const {return scope_;}
        QChar   type()    const {return type_;}

    private:
        QString id_, part2b_, part2t_, part1_, refName_, comment_;
        QChar   scope_, type_;
    };
    class Country
    {
    public:
        Country(const QString &name, const QString &code);
        Country(const Country &);
        ~Country(){}

        QString name() const {return name_;}
        QString code() const {return code_;}

    private:
        QString name_, code_;
    };
    class DataBase
    {
    public:
        DataBase();
        ~DataBase();

        QString languageFromCode(const QString &) const;
        QString countryFromCode(const QString &) const;

    private:
        void initLanguages();
        void initCountries();

        std::vector<Language> languages_;
        std::vector<Country>  countries_;
    };
} // namespace Locale

#endif // LOCALEDB_H
