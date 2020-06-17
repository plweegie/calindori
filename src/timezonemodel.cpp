#include "timezonemodel.h"

#include <QTimeZone>

TimeZoneModel::TimeZoneModel(QObject* parent) :
    QAbstractListModel(parent),
    m_timezones {QTimeZone::availableTimeZoneIds()}
{
}

TimeZoneModel::~TimeZoneModel() = default;

int TimeZoneModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    if (parent.isValid())
    {
        return 0;
    }

    return m_timezones.count();
}

QVariant TimeZoneModel::data(const QModelIndex& index, int role) const
{

    if (index.isValid() && role == Roles::NameRole)
    {
        const QTimeZone& timeZone = QTimeZone(m_timezones[index.row()]);
        return QLocale::countryToString(timeZone.country()) + ", " +
                timeZone.displayName(QDateTime::currentDateTime(), QTimeZone::LongName);
    }

    return QVariant();
}

QHash<int, QByteArray> TimeZoneModel::roleNames() const
{
    return {
        {NameRole, "name"}
    };
}


