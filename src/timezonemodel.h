#ifndef TIMEZONEMODEL_H
#define TIMEZONEMODEL_H

#include <QByteArray>
#include <QList>
#include <QAbstractListModel>

class TimeZoneModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit TimeZoneModel(QObject* parent = nullptr);
    ~TimeZoneModel() override;

    enum Roles {
        NameRole
    };

    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<QByteArray> m_timezones;
};

#endif
