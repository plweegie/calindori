#ifndef TIMEZONEPROXYMODEL_H
#define TIMEZONEPROXYMODEL_H

#include <QSortFilterProxyModel>

class TimeZoneProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit TimeZoneProxyModel(QObject* parent = nullptr);
    ~TimeZoneProxyModel() override;

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override;
};

#endif // TIMEZONEPROXYMODEL_H
