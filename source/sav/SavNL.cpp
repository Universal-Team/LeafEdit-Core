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

#include "SavNL.hpp"

std::shared_ptr<Player> SavNL::player(int player) {
	return std::make_shared<PlayerNL>(dataPointer, 0xA0 + (player * 0x9F10));
}

std::shared_ptr<Villager> SavNL::villager(int villager) {
	return std::make_shared<VillagerNL>(dataPointer, 0x027d10 + (villager * 0x24f8));
}

std::shared_ptr<Town> SavNL::town() {
	return std::make_shared<TownNL>(dataPointer);
}

void SavNL::Finish(void) {
	// TODO: Write and save all NL Stuff.
}