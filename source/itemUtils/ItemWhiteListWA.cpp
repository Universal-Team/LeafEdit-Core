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

#include "ItemWhiteListWA.hpp"

bool ItemWhiteListWA::validHat(u16 itemID) const {
	return (itemID > 0x280A && itemID < 0x28F4);
}

bool ItemWhiteListWA::validAccessoires(u16 itemID) const {
	return (itemID > 0x28F4 && itemID < 0x295C);
}

bool ItemWhiteListWA::validShirt(u16 itemID) const {
	return (itemID > 0x2492 && itemID < 0x26F6);
}

bool ItemWhiteListWA::validPants(u16 itemID) const {
	return (itemID > 0x26F7 && itemID < 0x2777);
}

bool ItemWhiteListWA::validSocks(u16 itemID) const {
	return (itemID > 0x2776 && itemID < 0x279F);
}

bool ItemWhiteListWA::validShoes(u16 itemID) const {
	return (itemID > 0x279E && itemID < 0x27E6);
}

bool ItemWhiteListWA::validTools(u16 itemID) const {
	return (itemID == 0x2001 || (itemID == 0x3729) || (itemID > 0x334B && itemID < 0x33A3));
}

bool ItemWhiteListWA::validMusic(u16 itemID) const {
	if (itemID < 0xFFF) {
		if (itemID > 0x0DB && itemID < 0x10B) return false;
			return true;
		}

	return false;
}

bool ItemWhiteListWA::validItem(u16 itemID) const {
	/* TODO. */
	return false;
}