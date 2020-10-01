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

#ifndef _LEAFEDIT_CORE_ITEM_WHITELIST_WW_HPP
#define _LEAFEDIT_CORE_ITEM_WHITELIST_WW_HPP

#include "ItemWhiteList.hpp"
#include "types.hpp"

class ItemWhiteListWW : public ItemWhiteList {
public:
	bool validHat(u16 itemID) const override;
	bool validAccessoires(u16 itemID) const override;
	bool validShirt(u16 itemID) const override;
	bool validPants(u16 itemID) const override;
	bool validSocks(u16 itemID) const override;
	bool validShoes(u16 itemID) const override;
	bool validTools(u16 itemID) const override;
	bool validMusic(u16 itemID) const override;
	bool validItem(u16 itemID) const override;

	std::unique_ptr<ItemKind> GetItemKind() const override { return nullptr; };
};

#endif