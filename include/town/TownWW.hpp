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

#ifndef _LEAFEDIT_CORE_TOWN_WW_HPP
#define _LEAFEDIT_CORE_TOWN_WW_HPP

#include "AcreWW.hpp"
#include "ItemWW.hpp"
#include "PatternWW.hpp"
#include "Town.hpp"
#include "types.hpp"
#include <memory>

class TownWW : public Town {
protected:
	WWRegion SaveRegion;
	std::shared_ptr<u8[]> TownData;
public:
	virtual ~TownWW() { };
	TownWW(std::shared_ptr<u8[]> townData, WWRegion Region) :
		Town(townData), SaveRegion(Region), TownData(townData) { };

	u8 grasstype() const override;
	void grasstype(u8 v) override;

	std::u16string name() const override;
	void name(std::u16string v) override;

	std::unique_ptr<Acre> acre(int Acre) const override;

	std::unique_ptr<Item> item(u32 index) const override;

	bool exist() const override;

	u32 turnipPrices(bool isAM, int day) const override;
	void turnipPrices(bool isAM, int day, u32 v) override;

	std::unique_ptr<Pattern> townflag() const override;

	bool itemBuried(int index) const override;
	void itemBuried(int index, bool buried) override;

	std::unique_ptr<Item> recycleItem(int slot) const override;
	std::unique_ptr<Item> lostFoundItem(int slot) const override;
private:
	u8 *townPointer() const { return this->TownData.get(); };
};

#endif