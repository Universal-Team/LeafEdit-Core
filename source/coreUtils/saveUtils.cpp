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

#include "saveUtils.hpp"

/* Credits: PKSM-Core: https://github.com/FlagBrew/PKSM-Core/blob/master/source/utils/flagUtil.cpp. */

/*
	Get a bit.

	const u8 *data: The save buffer.
	int offset: The offset.
	u8 bitIndex: The index of the bit.
*/
bool SaveUtils::GetBit(const u8 *data, int offset, u8 bitIndex) {
	bitIndex &= 7; // ensure bit access is 0-7.
	return (data[offset] >> bitIndex & 1) != 0;
}

/*
	Set a bit.

	const u8 *data: The save buffer.
	int offset: The offset.
	u8 bitIndex: The index of the bit.
	bool bit: if the bit is 1 (true) or 0 (false).
*/
void SaveUtils::SetBit(u8 *data, int offset, u8 bitIndex, bool bit) {
	bitIndex &= 7; // ensure bit access is 0-7.
	data[offset] &= ~(1 << bitIndex);
	data[offset] |= (bit ? 1 : 0) << bitIndex;
	if (save) save->changesMade();
}