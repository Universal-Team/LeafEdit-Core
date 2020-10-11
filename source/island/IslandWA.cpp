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

#include "IslandWA.hpp"

/*
	Return an Island Acre.

	u8 Acre: The Acre index.
*/
std::unique_ptr<Acre> IslandWA::acre(u8 Acre) const {
	if (Acre > 15) return nullptr;

	return std::make_unique<AcreWA>(this->IslandData, 0x06FEB8 + Acre * 2);
}

/*
	Return an Island Map item.

	u16 index: The map index.
*/
std::unique_ptr<Item> IslandWA::item(u16 index) const {
	if (index > 1023) return nullptr;

	return std::make_unique<ItemWA>(this->IslandData, 0x06FED8 + index * 4);
}