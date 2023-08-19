/*!
 * Implementation for the coordination and direction utilities
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

constexpr LSystemPoint::LSystemPoint(qreal initX, qreal initY) noexcept
{
    this->m_point.setX(initX);
    this->m_point.setY(initY);
}

constexpr LSystemPoint::LSystemPoint(const QPointF &point) noexcept
{
    this->m_point.setX(point.x());
    this->m_point.setY(point.y());
}

constexpr LSystemPoint::LSystemPoint(const LSystemPoint &other) noexcept
{
    this->m_point = QPoint(other.m_point.x(), other.m_point.y());
}

constexpr inline qreal LSystemPoint::getX() const noexcept
{
    return this->m_point.x();
}

constexpr inline qreal LSystemPoint::getY() const noexcept
{
    return this->m_point.y();
}

constexpr inline qreal LSystemPoint::getR() const noexcept
{
    qreal px = this->m_point.x();
    qreal py = this->m_point.y();

    return qSqrt(px * px + py * py);
}

constexpr inline qreal LSystemPoint::getTheta() const noexcept
{
    qreal px = this->m_point.x();
    qreal py = this->m_point.y();

    return qAtan2(py, px);
}

inline QString LSystemPoint::toString() const noexcept
{
    qreal px = this->m_point.x();
    qreal py = this->m_point.y();

    return QStringLiteral("Point(%1, %2)").arg(px, py);
}

constexpr inline void LSystemPoint::setX(qreal newX) noexcept
{
    this->m_point.setX(newX);
}

constexpr inline void LSystemPoint::setY(qreal newY) noexcept
{
    this->m_point.setY(newY);
}

constexpr inline void LSystemPoint::setXY(qreal newX, qreal newY) noexcept
{
    this->m_point.setX(newX);
    this->m_point.setY(newY);
}

constexpr inline void LSystemPoint::setR(qreal newR) noexcept
{
    qreal theta = this->getTheta();
    qreal newX = newR * qCos(theta);
    qreal newY = newR * qSin(theta);

    this->setXY(newX, newY);
}

constexpr inline void LSystemPoint::setTheta(qreal newTheta) noexcept
{
    qreal r = this->getR();
    qreal newX = r * qCos(newTheta);
    qreal newY = r * qSin(newTheta);
}

constexpr inline void LSystemPoint::setRTheta(qreal newR, qreal newTheta) noexcept
{
    this->setR(newR);
    this->setTheta(newTheta);
}

constexpr inline qreal LSystemPoint::distance(const LSystemPoint &other) const noexcept
{
    qreal otherX = other.getX();
    qreal otherY = other.getY();

    qreal dx = otherX - this->getX();
    qreal dy = otherY - this->getY();

    return qSqrt(dx * dx + dy * dy);
}

constexpr inline qreal LSystemPoint::distance(qreal x, qreal y) const noexcept
{
    qreal dx = x - this->getX();
    qreal dy = y - this->getY();

    return qSqrt(dx * dx + dy * dy);
}

constexpr inline qreal LSystemPoint::distance(const LSystemPoint &p1,
                                              const LSystemPoint &p2) noexcept
{
    return p1.distance(p2);
}

constexpr inline qreal LSystemPoint::distance(qreal x1, qreal y1, qreal x2, qreal y2) noexcept
{
    LSystemPoint p1(x1, y1);
    LSystemPoint p2(x2, y2);

    return LSystemPoint::distance(p1, p2);
}

constexpr inline LSystemPoint LSystemPoint::fromPolar(qreal distance, qreal angle) noexcept
{
    LSystemPoint p;

    p.setR(distance);
    p.setTheta(angle);

    return p;
}

constexpr inline bool operator==(const LSystemPoint &p1, const LSystemPoint &p2)
{
    return p1.m_point == p2.m_point;
}

constexpr inline bool operator!=(const LSystemPoint &p1, const LSystemPoint &p2)
{
    return !(p1 == p2);
}

QDataStream &operator<<(QDataStream &out, const LSystemPoint &point)
{
    out << point.toString();
}
