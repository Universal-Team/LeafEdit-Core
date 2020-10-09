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
#include "SavNL.hpp"

/*
	Return a Player.

	int player: The player index.
*/
std::unique_ptr<Player> SavNL::player(int player) const {
	if (player > 3) return nullptr; // Player goes out of scope.

	return std::make_unique<PlayerNL>(this->SaveData, 0xA0 + (player * 0x9F10), player);
}

/*
	Return a Villager.

	int villager: The villager index.
*/
std::unique_ptr<Villager> SavNL::villager(int villager) const {
	if (villager > 9) return nullptr; // Villager goes out of scope.

	return std::make_unique<VillagerNL>(this->SaveData, 0x027d10 + (villager * 0x24f8));
}

/*
	Return the Town.
*/
std::unique_ptr<Town> SavNL::town() const { return std::make_unique<TownNL>(this->SaveData); }

/*
	Return the Island.
*/
std::unique_ptr<Island> SavNL::island() const { return std::make_unique<IslandNL>(this->SaveData); }

/*
	Return the shops.
*/
std::unique_ptr<Shop> SavNL::shop() const { return std::make_unique<ShopNL>(this->SaveData, 0); }

/*
	Last call before writing to file. Update Checksum.
*/
void SavNL::Finish(void) { Checksum::FixNLCRC32s(this->savePointer()); }