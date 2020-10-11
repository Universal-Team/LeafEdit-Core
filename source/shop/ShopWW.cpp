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
#include "ShopWW.hpp"

/*
	Return the able sister pattern.

	u8 pattern: Pattern Index.
*/
std::unique_ptr<Pattern> ShopWW::ableSisterPattern(u8 pattern) const {
	if (pattern > 7) return nullptr;

	switch(this->SaveRegion) {
		case WWRegion::EUR_USA:
			return std::make_unique<PatternWW>(this->ShopData, this->Offset + 0xFAFC + pattern * 0x228, this->SaveRegion);

		case WWRegion::JPN:
			return std::make_unique<PatternWW>(this->ShopData, this->Offset + 0xDAF8 + pattern * 0x220, this->SaveRegion);

		case WWRegion::KOR:
			return std::make_unique<PatternWW>(this->ShopData, this->Offset + 0x10AD0 + pattern * 0x234, this->SaveRegion);
	}

	return nullptr;
}