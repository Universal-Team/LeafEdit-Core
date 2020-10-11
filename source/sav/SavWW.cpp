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

#include "checksum.hpp"
#include "SavWW.hpp"
#include <cstring>

/*
	Return a Player.

	u8 player: The player index.
*/
std::unique_ptr<Player> SavWW::player(u8 player) const {
	if (player > 3) return nullptr; // Player goes out of scope.

	switch (this->SaveRegion) {
		case WWRegion::EUR_USA:
			return std::make_unique<PlayerWW>(this->SaveData, 0x000C + (player * 0x228C), this->SaveRegion, player);

		case WWRegion::JPN:
			return std::make_unique<PlayerWW>(this->SaveData, 0x000C + (player * 0x1D10), this->SaveRegion, player);

		case WWRegion::KOR:
			return std::make_unique<PlayerWW>(this->SaveData, 0x0014 + (player * 0x249C), this->SaveRegion, player);
	}

	return nullptr;
}

/*
	Return a Villager.

	u8 villager: The villager index.
*/
std::unique_ptr<Villager> SavWW::villager(u8 villager) const {
	if (villager > 7) return nullptr; // Villager goes out of scope.

	switch (this->SaveRegion) {
		case WWRegion::EUR_USA:
			return std::make_unique<VillagerWW>(this->SaveData, 0x8A3C + (villager * 0x700), this->SaveRegion);

		case WWRegion::JPN:
			return std::make_unique<VillagerWW>(this->SaveData, 0x744C + (villager * 0x5C0), this->SaveRegion);

		case WWRegion::KOR:
			return std::make_unique<VillagerWW>(this->SaveData, 0x928C + (villager * 0x7EC), this->SaveRegion);
	}

	return nullptr; // Unknown region.
}

/*
	Return the Town.
*/
std::unique_ptr<Town> SavWW::town() const { return std::make_unique<TownWW>(this->SaveData, this->SaveRegion); }

/*
	Return the Island.
	Does not exist on Wild World.
*/
std::unique_ptr<Island> SavWW::island() const { return nullptr; }

/*
	Return the Shops.
*/
std::unique_ptr<Shop> SavWW::shop() const { return std::make_unique<ShopWW>(this->SaveData, 0, this->SaveRegion); }

/*
	Last call before writing to file. Update Checksum.
*/
void SavWW::Finish(void) {
	switch (this->SaveRegion) {
		case WWRegion::EUR_USA:
			Checksum::UpdateWWChecksum(this->SaveRegion, this->savePointer(), reinterpret_cast<u16 *>(this->savePointer()), 0x15FE0 / sizeof(u16));
			memcpy(this->savePointer() + 0x15FE0, this->savePointer(), 0x15FE0); // Copy SaveData to the second save copy.
			break;

		case WWRegion::JPN:
			Checksum::UpdateWWChecksum(this->SaveRegion, this->savePointer(), reinterpret_cast<u16 *>(this->savePointer()), 0x12224 / sizeof(u16));
			memcpy(this->savePointer() + 0x12224, this->savePointer(), 0x12224); // Copy SaveData to the second save copy.
			break;

		case WWRegion::KOR:
			Checksum::UpdateWWChecksum(this->SaveRegion, this->savePointer(), reinterpret_cast<u16 *>(this->savePointer()), 0x173FC / sizeof(u16));
			memcpy(this->savePointer() + 0x173FC, this->savePointer(), 0x173FC); // Copy SaveData to the second save copy.
			break;
	}
}