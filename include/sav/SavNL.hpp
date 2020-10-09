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

#ifndef _LEAFEDIT_CORE_SAV_NL_HPP
#define _LEAFEDIT_CORE_SAV_NL_HPP

#include "IslandNL.hpp"
#include "PlayerHHD.hpp"
#include "PlayerNL.hpp"
#include "Sav.hpp"
#include "ShopNL.hpp"
#include "TownNL.hpp"
#include "types.hpp"
#include "VillagerNL.hpp"
#include <string>

class SavNL : public Sav {
protected:
	std::shared_ptr<u8[]> SaveData;
	u32 SaveSize;
public:
	virtual ~SavNL() { };
	SavNL(std::shared_ptr<u8[]> data, u32 ssize) :
		Sav(data, ssize), SaveData(data), SaveSize(ssize) { };

	void Finish(void) override;

	/*
		Get main core class contents.
	*/
	std::unique_ptr<Player> player(int player) const override;
	std::unique_ptr<Villager> villager(int villager) const override;
	std::unique_ptr<Town> town() const override;
	std::unique_ptr<Island> island() const override;
	std::unique_ptr<Shop> shop() const override;

	/*
		Special Getter's for AC:HHD.
		Return nullptr on that for the main series.
	*/
	std::unique_ptr<PlayerHHD> playerhhd() const override { return nullptr; };

	SaveType getType() const override { return SaveType::NL; };
	WWRegion getRegion() const override { return WWRegion::EUR_USA; }; // Just return the first region from there, i guess.

	int maxVillager() const override { return 9; };
private:
	u8 *savePointer() const { return this->SaveData.get(); };
};

#endif