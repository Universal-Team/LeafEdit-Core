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

#include "itemKindWA.hpp"
#ifndef _CORE_CONFIGURED
	#include "leafedit_core.hpp"
#endif

ItemKindWA::ItemKindWA() { this->loadItemBins(); };
ItemKindWA::~ItemKindWA() { this->closeItemBins(); };

/*
	Load the Item Bin's.
*/
void ItemKindWA::loadItemBins() {
	this->ItemBin = fopen(_ITEM_BIN_PATH "/ItemWA.bin", "rb");
	this->ItemKindBin = fopen(_ITEM_BIN_PATH "/KindWA.bin", "rb");
}

/*
	Close the Item Bin's.. if not closed.
*/
void ItemKindWA::closeItemBins() {
	if (this->ItemBin) fclose(this->ItemBin);
	if (this->ItemKindBin) fclose(this->ItemKindBin);
}

/*
	Return, if it's a "normal" item.

	u16 itemID: The Item ID.
*/
s32 ItemKindWA::IsNormalItem(u16 itemID) {
	u16 ID = itemID & 0x7FFF;
	s32 chk = ID - 0x2000; // To cover items lower than 0x2000 (Enviroment Items).

	if (chk >= 0 && chk < this->maxID) return chk;

	else return -1;
}

/*
	Return the ItemBin's struct from an ItemID.

	u16 ItemID: The Item ID.
*/
ItemKindWA::ItemBin_s *ItemKindWA::GetItemBinSlot(u16 ItemID) {
	ItemKindWA::ItemBin_s *ItemSlot = new ItemKindWA::ItemBin_s;
	s32 chk = this->IsNormalItem(ItemID);

	if (chk < 0 || chk > maxID) {
		delete ItemSlot;
		return nullptr;

	} else if (this->GetItemBin()) {
		/* chk <= maxID. */
		fseek(this->GetItemBin(), sizeof(ItemKindWA::ItemBin_s) * chk, SEEK_SET);

		if ((int)(fread(reinterpret_cast<void *>(ItemSlot), 1, sizeof(ItemKindWA::ItemBin_s), this->GetItemBin())) >= 0) {
			return ItemSlot;
		}
	}

	delete ItemSlot;
	return nullptr;
}

/*
	Return the ItemKind's struct from an ItemID.

	u16 ItemID: The Item ID.
*/
ItemKind_s *ItemKindWA::GetItemKindSlot(u16 ItemID) {
	ItemKind_s *KindSlot = new ItemKind_s;
	ItemBin_s *ItemSlot = this->GetItemBinSlot(ItemID);

	if (!ItemSlot) {
		delete KindSlot;
		return nullptr;
	}

	u8 ItemCategory = ItemSlot->Category;
	delete ItemSlot;

	if (ItemCategory >= 0x9B) {
		delete KindSlot;
		return nullptr;

	} else if (this->GetItemKind()) {
		fseek(this->GetItemKind(), sizeof(ItemKind_s) * ItemCategory, SEEK_SET);

		if ((int)(fread(reinterpret_cast<void *>(KindSlot), 1, sizeof(ItemKind_s), this->GetItemKind())) >= 0) {
			return KindSlot;
		}
	}

	delete KindSlot;
	return nullptr;
}

/*
	Return the Axe Damage amount / value.

	u16 ItemID: The Item ID.
	u16 Flags: The Item's flags.
*/
u16 ItemKindWA::GetAxeDamageValue(u16 ItemID, u16 Flags) {
	/*
		Used for Normal Axe and Silver Axe.
	*/
	if (ItemID != 0x334D && ItemID != 0x334E) return 0;

	return (Flags & 0xF);
}

/*
	Return the Axe Damaged value icon index.

	u16 ItemID: The Item ID.
	u16 Flags: The Item's flags.
*/
u16 ItemKindWA::GetAxeDamageIcon(u16 ItemID, u16 Flags) {
	static constexpr u8 AxeDamageTable[] = { 0, 0, 0, 1, 1, 1, 2, 2 };

	u16 DamageValue = GetAxeDamageValue(ItemID, Flags);
	if (DamageValue >= 8) return ItemID;

	return ItemID + AxeDamageTable[DamageValue];
}

/*
	Return if the item is in the white list.

	u16 ItemID: The Item ID.
*/
bool ItemKindWA::IsInvWhiteListed(u16 ItemID) {
	u16 ID = ItemID;
	ID &= 0x6000;
	if (ID == 0x4000) return true; // If item is wrapping paper / Any item ID between 0x4000 <-> 0x5FFF.

	ItemKind_s *KindSlot = this->GetItemKindSlot(ID);

	if (!KindSlot) return false;

	u32 Unk = !(KindSlot->Unknown2 & 0x10);
	if (Unk == static_cast<u32>(-1)) return true;

	return false;
}

/*
	Get the Item's Category.

	u16 ItemID: The Item ID.
*/
u8 ItemKindWA::GetCategory(u16 ItemID) {
	ItemKindWA::ItemBin_s *ItemSlot = this->GetItemBinSlot(ItemID);

	if (!ItemSlot) return 0x9B;

	u8 category = ItemSlot->Category;
	delete ItemSlot;
	if (category >= 0x9B) return 0;

	return category;
}

/*
	Get the Item's icon ID.

	u16 ItemID: The Item ID.
	u16 Flags: The Item's flags.
*/
u16 ItemKindWA::GetIconID(u16 ItemID, u16 Flags) {
	ItemKindWA::ItemBin_s *ItemSlot = this->GetItemBinSlot(ItemID);
	if (!ItemSlot) return 0;

	u16 IconID = ItemSlot->ItemIcon;
	delete ItemSlot;

	if (IconID >= 0x1FB) return 0;

	u8 category = this->GetCategory(ItemID);
	if (category == 0xE && (ItemID == 0x334D || ItemID == 0x334E)) {
		IconID = this->GetAxeDamageIcon(IconID, Flags);
	}

	return IconID;
}

/*
	Get the SpriteSheet ID of the item.

	u16 ItemID: The Item ID.
	u16 Flags: The Item's flags.
*/
s32 ItemKindWA::GetSpritesheetID(u16 ItemID, u16 Flags) {
	if (ItemID == 0x7FFE) return -1;

	u16 iconID = 0;
	if (this->GetItemBin()) iconID = this->GetIconID(ItemID, Flags);

	return SpritesheetIDTable[iconID];
}