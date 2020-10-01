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

#ifndef _LEAFEDIT_CORE_ITEM_KIND_NL_HPP
#define _LEAFEDIT_CORE_ITEM_KIND_NL_HPP

#include "itemKind.hpp"
#include "types.hpp"

class ItemKindNL : public ItemKind {
public:
	ItemKindNL();
	~ItemKindNL();

	void loadItemBins() override;
	void closeItemBins() override;

	/* Return if that's a "normal" item. */
	s32 IsNormalItem(u16 itemID) override;

	/* Axe Damage stuff. */
	u16 GetAxeDamageValue(u16 ItemID, u16 Flags = 0) override;
	u16 GetAxeDamageIcon(u16 ItemID, u16 Flags = 0) override;

	/*
		Return if item is in the whitelist.
		This should avoid having a full grown Tree or such in a pocket.
	*/
	bool IsInvWhiteListed(u16 ItemID) override;

	/* Get an Item's category. */
	u8 GetCategory(u16 ItemID) override;

	/* Get an Item's icon. */
	u16 GetIconID(u16 ItemID, u16 Flags = 0) override;
	s32 GetSpritesheetID(u16 ItemID, u16 Flags = 0) override;

	FILE *GetItemBin() const { return this->g_ItemBin; }
	FILE *GetItemKind() const { return this->g_ItemKindBin; }
private:
	FILE *g_ItemBin = nullptr, *g_ItemKindBin = nullptr;

	struct ItemBin_s {
		u16 ItemIcon;
		u16 ItemPrice;
		u16 Unknown0;
		u16 RefurbishID;
		u16 SoundID;
		u8  Category;
		s8  Unknown2;
		s8  Unknown3;
		s8  Unknown4;
		s8  PriceMultiplier;
		u8  Unknown5;
		s8  ClothingGroup;
		u8  CanRefurbish___;
		u8  DinosaurGroup;
		s8  ArtGroup;
		u8  Unknown6;
		u8  Unknown7;
		u8  Unknown8;
		u8  Unknown9;
		u8  Unknown10;
		u8  Unknown11;
		u8  Unknown12;
		u8  Unknown13;
		u8  Unknown14;
		u8  Unknown15;
		u8  Unknown16;
		u8  Unknown17;
		u8  Unknown18;
		u8  Unknown19;
	};

	/* Real Max Item ID is 0x31B4 (excludes wrap paper) but for checks, ID -= 0x2000 from orig item ID. */
	static constexpr u16 maxID = 0x11B4; // is that right? TODO: CHECK!!!!

	ItemKindNL::ItemBin_s* GetItemBinSlot(u16 ItemID);
	ItemKind_s* GetItemKindSlot(u16 ItemID);
};

#endif