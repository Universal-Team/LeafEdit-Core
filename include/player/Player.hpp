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

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "types.hpp"

#include <memory>
#include <vector>

class Player {
protected:
	std::shared_ptr<u8[]> data;
	u32 offset; // Offset to the Player.
public:
	virtual ~Player() {}
	Player(std::shared_ptr<u8[]> playerData, u32 playerOffset) : data(playerData), offset(playerOffset) {}
	Player(const Player& player) = delete;
	Player& operator=(const Player& player) = delete;

	virtual u8 face() = 0;
	virtual void face(u8 v) = 0;
	virtual u8 gender() = 0;
	virtual void gender(u8 v) = 0;
	virtual u16 tan() = 0;
	virtual void tan(u16 v) = 0;
	virtual u8 hairstyle() = 0;
	virtual void hairstyle(u8 v) = 0;
	virtual u8 haircolor() = 0;
	virtual void haircolor(u8 v) = 0;
	virtual u8 eyecolor() = 0;
	virtual void eyecolor(u8 v) = 0;
	virtual u8 badge(int badge) = 0;
	virtual void badge(int badge, u8 v) = 0;
	virtual u16 playerid() = 0;
	virtual void playerid(u16 v) = 0;
	virtual u16 townid() = 0;
	virtual void townid(u16 v) = 0;
	virtual bool exist() = 0;
};

#endif