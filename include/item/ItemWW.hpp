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

#ifndef _LEAFEDIT_CORE_ITEM_WW_HPP
#define _LEAFEDIT_CORE_ITEM_WW_HPP

#include "Item.hpp"
#include <memory>

class ItemWW : public Item {
protected:
	std::shared_ptr<u8[]> ItemData;
	u32 Offset;
public:
	virtual ~ItemWW() { };
	ItemWW(std::shared_ptr<u8[]> itemData, u32 offset) :
		Item(itemData, offset), ItemData(itemData), Offset(offset) { };

	u32 maxItems() const override { return 0; };

	u16 id() const override;
	void id(u16 v) override;

	u16 flags() const override;
	void flags(u16 v) override;

	u8 flag1() const override;
	void flag1(u8 v) override;

	u8 flag2() const override;
	void flag2(u8 v) override;

	std::string name() const override;

	ItemType itemtype() const override;

	FurnitureDirection rotation() const override;
	void rotation(FurnitureDirection Direction) override;
private:
	u8 *itemPointer() const { return this->ItemData.get() + this->Offset; };
};

#endif