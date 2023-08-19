/*!
 * Implementation for the Core L-System rewriting header file
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

#include <LSystemCore.h>

Q_GLOBAL_STATIC(LSystemDrawer, __LSystemDrawerSingleton)

LSystemDrawer::LSystemDrawer(QObject *parent)
    : QObject(parent)
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);

    this->m_state = LSystemDrawer::STATE::READY;

    qDebug() << "[INFO] LSystemDrawer::LSystemDrawer(" << parent << ") successfully";
}

LSystemDrawer::~LSystemDrawer()
{
    qDebug() << "[INFO] LSystemDrawer::~LSystemDrawer() successfully";
}

QObject *LSystemDrawer::qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return __LSystemDrawerSingleton();
}

LSystemDrawer::State LSystemDrawer::state() const
{
    return m_state;
}

QString LSystemDrawer::getStateString() const
{
    switch (this->m_state) {
    case STATE::READY:
        return "Ready";
    case STATE::DRAWING:
        return "Drawing";
    case STATE::PAUSED:
        return "Paused";
    case STATE::DONE:
        return "Done";
    case STATE::UNAVAILABLE:
    default:
        return "Unavailable";
    }
}

void LSystemDrawer::setState(LSystemDrawer::State newState)
{
    if (m_state == newState)
        return;

    this->m_state = newState;
    emit stateChanged(this->m_state);
}
