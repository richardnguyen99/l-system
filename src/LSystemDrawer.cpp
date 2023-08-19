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

LSystemDrawer::LSystemDrawer(QObject *parent) noexcept
    : QObject(parent)
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);

    this->m_state = LSystemDrawer::STATE::UNAVAILABLE;

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

LSystemDrawer::State LSystemDrawer::state() const noexcept
{
    return m_state;
}

QString LSystemDrawer::getStateString() const noexcept
{
    using namespace Qt::StringLiterals;

    switch (this->m_state) {
    case STATE::READY:
        return u"Ready"_s;
    case STATE::DRAWING:
        return u"Drawing"_s;
    case STATE::PAUSED:
        return u"Paused"_s;
    case STATE::DONE:
        return u"Done"_s;
    case STATE::UNAVAILABLE:
    default:
        return u"Unavailable"_s;
    }
}

void LSystemDrawer::load(QQuickItem *drawer)
{
    this->m_drawer = drawer;
    this->setState(STATE::READY);

    QJSValue context = drawer->property("context").value<QJSValue>();

    qDebug() << "[INFO] LSystemDrawer::load(" << drawer << ") successfully";
    qDebug() << "[INFO] LSystemDrawer::load(" << context.property("fillStyle").toString()
             << ") successfully";

    context.setProperty("lineWidth", QJSValue(2));
    context.setProperty("lineCap", QJSValue("round"));
    context.setProperty("strokeStyle", QJSValue("#000000"));

    context.property("beginPath").callWithInstance(context);

    context.property("moveTo").callWithInstance(context,
                                                QJSValueList({QJSValue(100), QJSValue(100)}));

    context.property("lineTo").callWithInstance(context,
                                                QJSValueList({QJSValue(200), QJSValue(200)}));

    context.property("closePath").callWithInstance(context);
    context.property("stroke").callWithInstance(context);
}

QString LSystemDrawer::queueToString() const noexcept
{
    using namespace Qt::StringLiterals;

    return u"Some string"_s;
}

void LSystemDrawer::setState(LSystemDrawer::State newState) noexcept
{
    if (m_state == newState)
        return;

    this->m_state = newState;
    emit stateChanged(this->m_state);
}
