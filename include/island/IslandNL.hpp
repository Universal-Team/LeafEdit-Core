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

#ifndef _LEAFEDIT_CORE_ISLAND_NL_HPP
#define _LEAFEDIT_CORE_ISLAND_NL_HPP

#include "AcreNL.hpp"
#include "Island.hpp"
#include "ItemNL.hpp"
#include "types.hpp"
#include <memory>

class IslandNL : public Island {
protected:
	std::shared_ptr<u8[]> IslandData;
public:
	virtual ~IslandNL() { };
	IslandNL(std::shared_ptr<u8[]> islandData) :
		Island(islandData), IslandData(islandData) { };

	std::unique_ptr<Acre> acre(u8 Acre) const override;

	std::unique_ptr<Item> item(u16 index) const override;
private:
	u8 *islandPointer() const { return this->IslandData.get(); };
};

#endif