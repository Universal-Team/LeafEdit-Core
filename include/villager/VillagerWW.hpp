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

#ifndef _LEAFEDIT_CORE_VILLAGER_WW_HPP
#define _LEAFEDIT_CORE_VILLAGER_WW_HPP

#include "ItemWW.hpp"
#include "Villager.hpp"
#include "types.hpp"
#include <memory>

class VillagerWW : public Villager {
protected:
	std::shared_ptr<u8[]> VillagerData;
	u32 Offset;
	WWRegion SaveRegion;
public:
	virtual ~VillagerWW() { };
	VillagerWW(std::shared_ptr<u8[]> villagerData, u32 villagerOffset, WWRegion Region) :
			Villager(villagerData, villagerOffset), VillagerData(villagerData), Offset(villagerOffset), SaveRegion(Region) { };

	u32 getVillagerSize() const override {
		switch(this->SaveRegion) {
			case WWRegion::EUR_USA:
				return 0x700;

			case WWRegion::JPN:
				return 0x5C0;

			case WWRegion::KOR:
				return 0x7EC;
		}

		return 0;
	};

	u16 id() const override;
	void id(u16 v) override;

	bool exist() const override;

	u8 personality() const override;
	void personality(u8 v) override;

	/*
		Items.
		NOTE: Carpet, Wallpaper, Umbrella & Song is an uint8_t index. [u8]
	*/
	std::unique_ptr<Item> song() const override { return nullptr; };
	std::unique_ptr<Item> shirt() const override;
	std::unique_ptr<Item> wallpaper() const override { return nullptr; };
	std::unique_ptr<Item> carpet() const override { return nullptr; };
	std::unique_ptr<Item> umbrella() const override { return nullptr; };

	u8 songWW() const override;
	void songWW(u8 sng) override;

	u8 wallpaperWW() const override;
	void wallpaperWW(u8 wlp) override;

	u8 carpetWW() const override;
	void carpetWW(u8 crp) override;

	u8 umbrellaWW() const override;
	void umbrellaWW(u8 umbr) override;

	std::unique_ptr<Item> furniture(int slot) const override;
private:
	u8 *villagerPointer() const { return this->VillagerData.get() + this->Offset; };
};

#endif