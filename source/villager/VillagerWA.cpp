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

#include "saveUtils.hpp"
#include "VillagerWA.hpp"

/*
	Get and Set the Villager ID.
*/
u16 VillagerWA::id() const { return SaveUtils::Read<u16>(this->villagerPointer(), 0x0); };
void VillagerWA::id(u16 v) { SaveUtils::Write<u16>(this->villagerPointer(), 0x0, v); };

/*
	Return if the Villager exist.
*/
bool VillagerWA::exist() const {
	if (this->id() == 0xFFFF) return false;
	return true;
}

/*
	Get and Set for the Villager Personality.
*/
u8 VillagerWA::personality() const { return this->villagerPointer()[0x2]; };
void VillagerWA::personality(u8 v) { SaveUtils::Write<u8>(this->villagerPointer(), 0x2, v); };

/*
	Return the Villager Song.
*/
std::unique_ptr<Item> VillagerWA::song() const { return std::make_unique<ItemWA>(this->VillagerData, this->Offset + 0x2472); };

/*
	Return the Villager Shirt.
*/
std::unique_ptr<Item> VillagerWA::shirt() const { return std::make_unique<ItemWA>(this->VillagerData, this->Offset + 0x246E); };

/*
	Return the Villager Wallpaper.
*/
std::unique_ptr<Item> VillagerWA::wallpaper() const { return std::make_unique<ItemWA>(this->VillagerData, this->Offset + 0x2476); };

/*
	Return the Villager Carpet.
*/
std::unique_ptr<Item> VillagerWA::carpet() const { return std::make_unique<ItemWA>(this->VillagerData, this->Offset + 0x247A); };

/*
	Return the Villager Umbrella.
*/
std::unique_ptr<Item> VillagerWA::umbrella() const { return std::make_unique<ItemWA>(this->VillagerData, this->Offset + 0x247E); };

/*
	Return the Villager Furniture.

	u8 slot: The Furniture index.
*/
std::unique_ptr<Item> VillagerWA::furniture(u8 slot) const {
	if (slot > 15) return nullptr;

	return std::make_unique<ItemWA>(this->VillagerData, this->Offset + 0x2482 + slot * 4);
}