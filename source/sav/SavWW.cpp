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

#include "checksum.hpp"
#include "SavWW.hpp"

#include <cstring>

// Get Player data.
std::unique_ptr<Player> SavWW::player(int player, int index) {
	if (player > 3 || index > 3)	return nullptr;
	switch (this->region) {
		case WWRegion::EUR:
			return std::make_unique<PlayerWW>(dataPointer, 0x000C + (player * 0x228C), this->region, index);
		case WWRegion::JPN:
			return std::make_unique<PlayerWW>(dataPointer, 0x000C + (player * 0x1D10), this->region, index);
		case WWRegion::KOR:
			return nullptr; // TODO: Research.
	}
	return nullptr;
}

// Get Villager data.
std::unique_ptr<Villager> SavWW::villager(int villager) {
	if (villager > 7)	return nullptr;
	switch (this->region) {
		case WWRegion::EUR:
			return std::make_unique<VillagerWW>(dataPointer, 0x8A3C + (villager * 0x700), this->region);
		case WWRegion::JPN:
		case WWRegion::KOR:
			return nullptr; // TODO: Research.
	}
	return nullptr;
}

std::unique_ptr<Town> SavWW::town() {
	return std::make_unique<TownWW>(dataPointer, this->region);
}

std::unique_ptr<Island> SavWW::island() {
	return nullptr; // Does not exist.
}

void SavWW::Finish(void) {
	switch (this->region) {
		case WWRegion::EUR: // also USA.
			Checksum::UpdateWWChecksum(this->region, this->savePointer(), reinterpret_cast<u16*>(this->savePointer()), 0x15FE0 / sizeof(u16));
			memcpy(this->savePointer() + 0x15FE0, this->savePointer(), 0x15FE0); // Copy SaveData to the second save copy.
			break;
		case WWRegion::JPN:
			Checksum::UpdateWWChecksum(this->region, this->savePointer(), reinterpret_cast<u16*>(this->savePointer()), 0x12224 / sizeof(u16));
			memcpy(this->savePointer() + 0x12224, this->savePointer(), 0x12224); // Copy SaveData to the second save copy.
			break;
		case WWRegion::KOR:
			Checksum::UpdateWWChecksum(this->region, this->savePointer(), reinterpret_cast<u16*>(this->savePointer()), 0x173FC / sizeof(u16));
			memcpy(this->savePointer() + 0x173FC, this->savePointer(), 0x173FC); // Copy SaveData to the second save copy.
			break;
	}
}