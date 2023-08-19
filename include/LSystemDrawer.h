/*!
 * Drawer engine that parses an L-System Grammar and draws based on the rules
 * Copyright (C) 2023 Richard H. Nguyen
 * 
 * This file is a part of the L-System Project
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Written by Richard H. Nguyen <richard@richardhnguyen.com>
 */

#ifndef _LSYSTEM_DRAWER_H_
#define _LSYSTEM_DRAWER_H_ 1

#include <LSystemCore.h>

class LSystemDrawer : public QObject
{
public:
    /* Control the state of the drawer */
    enum STATE {
        UNAVAILABLE,
        READY,
        DRAWING,
        PAUSED,
        DONE,
    };

    using State = STATE;

    Q_OBJECT
    Q_PROPERTY(State state READ state WRITE setState NOTIFY stateChanged FINAL)
    Q_ENUM(STATE)

    Q_DISABLE_COPY(LSystemDrawer)

public:
    explicit LSystemDrawer(QObject *parent = nullptr);
    ~LSystemDrawer() override;

    static QObject *qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine);

    State state() const;

    Q_INVOKABLE QString getStateString() const;

public slots:
    void setState(State newState);

signals:
    void stateChanged(State newState);

private:
    State m_state;
};

#endif /* _LSYSTEM_DRAWER_H */
