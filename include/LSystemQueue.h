/*!
 * Header for Queue utilities used by the Rewriting component in L-System
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

#ifndef _LSYSTEM_QUEUE_H_
#define _LSYSTEM_QUEUE_H_ 1

#include <LSystemCore.h>

class LSystemQueue
{
public:
    LSystemQueue() noexcept;

private:
    QQueue<LSystemCommand> m_queue;
};

#endif /* _LSYSTEM_QUEUE_H_ */
