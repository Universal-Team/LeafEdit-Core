/*
*   This file is part of LeafEdit-Core
*   Copyright (C) 2020 DeadPhoenix8091, Epicpkmn11, Flame, RocketRobz, StackZ, TotallyNotGuy
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#ifndef TOWN_HPP
#define TOWN_HPP

#include "types.hpp"

#include <memory>
#include <vector>

class Town {
protected:
	std::shared_ptr<u8[]> data;
	u32 offset; // Offset to the Town.
public:
	virtual ~Town() {}
	Town(std::shared_ptr<u8[]> townData, u32 townOffset) : data(townData), offset(townOffset) {}
	Town(const Town& town) = delete;
	Town& operator=(const Town& town) = delete;

	virtual u8 grasstype() = 0;
	virtual void grasstype(u8 v) = 0;
};

#endif