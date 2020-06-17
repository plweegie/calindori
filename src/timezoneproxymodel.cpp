#include "timezoneproxymodel.h"

#include <QTimeZone>

TimeZoneProxyModel::TimeZoneProxyModel(QObject* parent) :
    QSortFilterProxyModel(parent)
{
}

TimeZoneProxyModel::~TimeZoneProxyModel() = default;

bool TimeZoneProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
    return !sourceModel()->data(index).toString().startsWith("Default");
}
