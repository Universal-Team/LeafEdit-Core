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

#ifndef PLAYERNL_HPP
#define PLAYERNL_HPP

#include "Player.hpp"
#include "types.hpp"

#include <memory>
#include <vector>

class PlayerNL : public Player {
protected:
	std::shared_ptr<u8[]> data;
	u32 offset; // Offset to the Player.
public:
	virtual ~PlayerNL() {}
	PlayerNL(std::shared_ptr<u8[]> playerData, u32 playerOffset) : Player(playerData, playerOffset), data(playerData), offset(playerOffset) { }

	u8 face() override;
	void face(u8 v) override;
	u8 gender() override;
	void gender(u8 v) override;
	u16 tan() override;
	void tan(u16 v) override;
	u8 hairstyle() override;
	void hairstyle(u8 v) override;
	u8 haircolor() override;
	void haircolor(u8 v) override;
	u8 eyecolor() override;
	void eyecolor(u8 v) override;
	u8 badge(int badge) override;
	void badge(int badge, u8 v) override;
	u16 playerid() override;
	void playerid(u16 v) override;
	u16 townid() override;
	void townid(u16 v) override;
	bool exist() override;
	std::u16string name() override;
private:
	u8* playerPointer() const {
		return data.get() + offset;
	}
};

#endif