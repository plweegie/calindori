/*
 * SPDX-FileCopyrightText: 2019 Dimitris Kardarakos <dimkard@posteo.net>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <QObject>

#ifndef EVENTCONTROLLER_H
#define EVENTCONTROLLER_H

#include <QObject>
#include <QVariantMap>

class LocalCalendar;

class EventController : public QObject
{
    Q_OBJECT

public:
    explicit EventController(QObject* parent = nullptr);
    ~EventController() override;

    Q_INVOKABLE void remove(LocalCalendar *calendar, const QVariantMap &event);
    Q_INVOKABLE void addEdit(LocalCalendar *calendar, const QVariantMap &event);
};
#endif
