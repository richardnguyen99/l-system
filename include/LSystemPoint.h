/*!
 * Header containing utilities that control coordinates and directions
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

#ifndef _LSYSTEM_POINT_H_
#define _LSYSTEM_POINT_H_ 1

#include <LSystemCore.h>

class LSystemPoint
{
public:
    constexpr LSystemPoint() noexcept = default;
    constexpr explicit LSystemPoint(qreal initX, qreal initY) noexcept;
    constexpr explicit LSystemPoint(const QPointF &p) noexcept;
    constexpr LSystemPoint(const LSystemPoint &other) noexcept;

    constexpr inline qreal getX() const noexcept;
    constexpr inline qreal getY() const noexcept;
    constexpr inline qreal getR() const noexcept;
    constexpr inline qreal getTheta() const noexcept;
    inline QString toString() const noexcept;

    constexpr inline void setX(qreal newX) noexcept;
    constexpr inline void setY(qreal newY) noexcept;
    constexpr inline void setXY(qreal newX, qreal newY) noexcept;
    constexpr inline void setR(qreal newR) noexcept;
    constexpr inline void setTheta(qreal newTheta) noexcept;
    constexpr inline void setRTheta(qreal newR, qreal newTheta) noexcept;

    constexpr inline qreal distance(const LSystemPoint &other) const noexcept;
    constexpr inline qreal distance(qreal x, qreal y) const noexcept;

    constexpr static inline qreal distance(const LSystemPoint &p1, const LSystemPoint &p2) noexcept;
    constexpr static inline qreal distance(qreal x1, qreal y1, qreal x2, qreal y2) noexcept;
    constexpr static inline LSystemPoint fromPolar(qreal distance, qreal angle) noexcept;

    friend constexpr inline bool operator==(const LSystemPoint &p1, const LSystemPoint &p2);
    friend constexpr inline bool operator!=(const LSystemPoint &p1, const LSystemPoint &p2);

private:
    QPointF m_point;
};

QDataStream &operator<<(QDataStream &out, const LSystemPoint &point);

#endif /* _LSYSTEM_POINT_H_ */
