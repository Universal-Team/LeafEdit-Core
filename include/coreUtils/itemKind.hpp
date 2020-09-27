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

#ifndef _LEAFEDIT_CORE_ITEM_KIND_HPP
#define _LEAFEDIT_CORE_ITEM_KIND_HPP

#include "types.hpp"

namespace ItemKind {
	void loadItemBins();
	void closeItemBins();

	/* Return if that's a "normal" item. */
	s32 IsNormalItem(u16 itemID);

	/* Axe Damage stuff. */
	u16 GetAxeDamageValue(u16 ItemID, u16 Flags = 0);
	u16 GetAxeDamageIcon(u16 ItemID, u16 Flags = 0);

	/*
		Return if item is in the whitelist.
		This should avoid having a full grown Tree or such in a pocket.
	*/
	bool IsInvWhitelisted(u16 ItemID);

	/* Get an Item's category. */
	u8 GetCategory(u16 ItemID);

	/* Get an Item's icon. */
	u16 GetIconID(u16 ItemID, u16 Flags = 0);
	s32 GetSpritesheetID(u16 ItemID, u16 Flags = 0);
}

#endif