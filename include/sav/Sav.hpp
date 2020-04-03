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

#ifndef SAV_HPP
#define SAV_HPP

#include "Player.hpp"
#include "Town.hpp"
#include "types.hpp"
#include "Villager.hpp"

#include <memory>
#include <vector>

class Player;
class Town;
class Villager;
class Sav {
protected:
	// Protected stuff.
	std::shared_ptr<u8[]> saveData;
	u32 saveLength;
public:
	// Constructor, Destructor and stuff.
	virtual ~Sav() {}
	Sav(std::shared_ptr<u8[]> data, u32 length) : saveData(data), saveLength(length) {}
	Sav(const Sav& save) = delete;
	Sav& operator=(const Sav& save) = delete;

	// Get Sav Contents.
	virtual std::shared_ptr<Player> player(int player) = 0;
	virtual std::shared_ptr<Villager> villager(int villager) = 0;
	virtual std::shared_ptr<Town> town() = 0;
	
	// Call this when finished editing.
	virtual void Finish(void) = 0;
	// Call this when getting the SaveType.
	static std::unique_ptr<Sav> getSave(std::shared_ptr<u8[]> dt, size_t length);

	// return Sav stuff.
	u32 getLength() const { return saveLength; }
	std::shared_ptr<u8[]> rawData() const { return saveData; }
	virtual SaveType getType() = 0;
};

#endif