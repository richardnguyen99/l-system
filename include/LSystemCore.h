/*!
 * Core header for the L-System rewriting software
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

#ifndef _LSYSTEM_CORE_INCLUDED_
#define _LSYSTEM_CORE_INCLUDED_ 1

enum LSystemCommand { FORWARD, FORWARD2, IGNORE, RIGHT, LEFT, PUSH, POP };

class LSystemDrawer;
class LSystemPoint;
class LSystemQueue;
class LSystemStack;
class LSystemRewriter;

/* Qt Core Libraries */
#include <QDebug>
#include <QGuiApplication>
#include <QJsonObject>
#include <QMetaObject>
#include <QPoint>
#include <QQmlApplicationEngine>
#include <QQueue>
#include <QQuickItem>
#include <QStack>
#include <QString>
#include <QStringBuilder>
#include <QVariant>
#include <QtMath>

// clang-format off

/* Core drawer engines */
#include <LSystemPoint.h>
#include <LSystemQueue.h>
#include <LSystemStack.h>
#include <LSystemRewriter.h>
#include <LSystemDrawer.h>

#endif /* _LSYSTEM_CORE_INCLUDED_ */
