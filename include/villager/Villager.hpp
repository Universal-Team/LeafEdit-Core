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

#ifndef _LEAFEDIT_CORE_VILLAGER_HPP
#define _LEAFEDIT_CORE_VILLAGER_HPP

#include "Item.hpp"
#include "types.hpp"
#include <memory>

class Villager {
protected:
	std::shared_ptr<u8[]> VillagerData;
	u32 Offset;
public:
	virtual ~Villager() { };
	Villager(std::shared_ptr<u8[]> villagerData, u32 villagerOffset) :
		VillagerData(villagerData), Offset(villagerOffset) { };
	Villager(const Villager& villager) = delete;
	Villager& operator=(const Villager& villager) = delete;
	virtual u32 getVillagerSize() const = 0;

	virtual u16 id() const = 0;
	virtual void id(u16 v) = 0;

	virtual bool exist() const = 0;

	virtual u8 personality() const = 0;
	virtual void personality(u8 v) = 0;

	/*
		Items.
	*/
	virtual std::unique_ptr<Item> song() const = 0;
	virtual std::unique_ptr<Item> shirt() const = 0;
	virtual std::unique_ptr<Item> wallpaper() const = 0;
	virtual std::unique_ptr<Item> carpet() const = 0;
	virtual std::unique_ptr<Item> umbrella() const = 0;

	/*
		AC:WW Indexes.
	*/
	virtual u8 songWW() const = 0;
	virtual void songWW(u8 sng) = 0;

	virtual u8 wallpaperWW() const = 0;
	virtual void wallpaperWW(u8 wlp) = 0;

	virtual u8 carpetWW() const = 0;
	virtual void carpetWW(u8 crp) = 0;

	virtual u8 umbrellaWW() const = 0;
	virtual void umbrellaWW(u8 umbr) = 0;

	virtual std::unique_ptr<Item> furniture(u8 slot) const = 0;
};

#endif