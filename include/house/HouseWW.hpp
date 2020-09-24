/*
*   This file is part of LeafEdit-Core
*   Copyright (C) 2020 LeafEdit-Core-Contributors
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

#ifndef _LEAFEDIT_CORE_HOUSE_WW_HPP
#define _LEAFEDIT_CORE_HOUSE_WW_HPP

#include "House.hpp"

#include <memory>

class RoomWW : public Room {
protected:
	u32 Offset;
	std::shared_ptr<u8[]> data;
public:
	virtual ~RoomWW() { }
	RoomWW(std::shared_ptr<u8[]> roomData, u32 offset) :
		Room(roomData, offset), Offset(offset), data(roomData) { }
private:
	u8* roomPointer() const {
		return data.get() + Offset;
	}
};

class HouseWW : public House {
protected:
	u32 Offset;
	std::shared_ptr<u8[]> data;
public:
	virtual ~HouseWW() { }
	HouseWW(std::shared_ptr<u8[]> houseData, u32 offset) :
		House(houseData, offset), Offset(offset), data(houseData) { }

	std::unique_ptr<Room> room(int room) const override;
private:
	u8* housePointer() const {
		return data.get() + Offset;
	}
};

#endif