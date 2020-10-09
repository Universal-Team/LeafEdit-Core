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

#ifndef _LEAFEDIT_CORE_SAV_HPP
#define _LEAFEDIT_CORE_SAV_HPP

#include "Island.hpp"
#include "Player.hpp"
#include "PlayerHHD.hpp"
#include "Shop.hpp"
#include "stringUtils.hpp"
#include "Town.hpp"
#include "types.hpp"
#include "Villager.hpp"
#include <cstring>
#include <memory>
#include <vector>

class Sav {
protected:
	std::shared_ptr<u8[]> SaveData;
	u32 SaveLength;
public:
	virtual ~Sav() { };
	Sav(std::shared_ptr<u8[]> data, u32 length) :
		SaveData(data), SaveLength(length) { this->setChangesMade(false); };
	Sav(const Sav& save) = delete;
	Sav& operator=(const Sav& save) = delete;

	/*
		Get Sav Contents.
	*/
	virtual std::unique_ptr<Player> player(int player) const = 0;
	virtual std::unique_ptr<Villager> villager(int villager) const = 0;
	virtual std::unique_ptr<Town> town() const = 0;
	virtual std::unique_ptr<Island> island() const = 0;
	virtual std::unique_ptr<Shop> shop() const = 0;

	/*
		Special Getter's for AC:HHD.
	*/
	virtual std::unique_ptr<PlayerHHD> playerhhd() const = 0;

	/*
		Call this when finished editing.
	*/
	virtual void Finish(void) = 0;

	/*
		Call this when getting the SaveType.
	*/
	static std::unique_ptr<Sav> getSave(std::shared_ptr<u8[]> data, u32 length);
	static std::unique_ptr<Sav> check080000(std::shared_ptr<u8[]> data, u32 length);

	/*
		Get max Values.
	*/
	virtual int maxVillager() const = 0;

	/*
		return Sav stuff.
	*/
	u32 getLength() const { return this->SaveLength; };
	std::shared_ptr<u8[]> rawData() const { return this->SaveData; };

	virtual SaveType getType() const = 0;
	virtual WWRegion getRegion() const = 0;

	bool Changes = false;
	void setChangesMade(bool v = true) { if (v != this->Changes) this->Changes = v; };
	bool changesMade() const { return this->Changes; };

	u8 *savePointer() const { return this->SaveData.get(); };
};

#endif