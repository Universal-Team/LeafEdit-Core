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

#ifndef SAVNL_HPP
#define SAVNL_HPP

#include "Player.hpp"
#include "PlayerNL.hpp"
#include "Sav.hpp"
#include "Town.hpp"
#include "TownNL.hpp"
#include "types.hpp"
#include "Villager.hpp"
#include "VillagerNL.hpp"

#include <string>

class Player;
class PlayerNL;
class Town;
class TownNL;
class Villager;
class VillagerNL;
class SavNL : public Sav {
protected:
	std::shared_ptr<u8[]> dataPointer;
public:
	// TODO: Decide what to set. Options: 0x7FA00 | 0x80000.
	SavNL(std::shared_ptr<u8[]> dt) : Sav(dt, 0x80000), dataPointer(dt) { }
	virtual ~SavNL() {}
	void Finish(void) override;
	std::shared_ptr<Player> player(int player) override;
	std::shared_ptr<Villager> villager(int villager) override;
	std::shared_ptr<Town> town() override;
	
	SaveType getType() override { return SaveType::NL; }
};

#endif