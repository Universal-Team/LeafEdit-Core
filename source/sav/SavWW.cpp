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

#include "SavWW.hpp"

// Get Player data.
std::shared_ptr<Player> SavWW::player(int player) {
	return std::make_shared<PlayerWW>(dataPointer, 0x000C + (player * 0x228C), this->isJapanese);
}

// Get Villager data.
std::shared_ptr<Villager> SavWW::villager(int villager) {
	return std::make_shared<VillagerWW>(dataPointer, 0x8A3C + (villager * 0x700));
}

std::shared_ptr<Town> SavWW::town() {
	return std::make_shared<TownWW>(dataPointer, this->isJapanese);
}

void SavWW::Finish(void) {
	// TODO: Write and save all WW Stuff.
}