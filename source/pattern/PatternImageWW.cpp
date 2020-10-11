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

#include "PatternImageWW.hpp"
#include "saveUtils.hpp"

/*
	Return the palette color index as an uint8_t.

	u8 plt: Index of the palette color.
*/
u8 PatternImageWW::getPaletteColor(u8 plt) const {
	if (plt > 15) return 0;

	u8 paletteIndex = (u8)(((this->paletteData()[0]) & 0xF0) >> 4);
	return (u8)((paletteIndex * 15) + plt);
}

/*
	Return the Palette Index.
*/
u8 PatternImageWW::getWWPaletteIndex() const { return (u8)(((this->paletteData()[0]) & 0xF0) >> 4); }

/*
	Set the Palette Index instead of color for the palette.

	u8 index: The new palette index. (0 - 14)
	u8 color: The color index. (Unused)
*/
void PatternImageWW::setPaletteColor(u8 index, u8 color) {
	if (index > 14) return;

	this->paletteData()[0] = (u8)(((index) << 4) & 0xF0);
}

/*
	Return a pixel struct for the Left & Right pixel buffer.

	u16 index: The pixel index of the pattern.
*/
pixel PatternImageWW::getPixel(u16 index) const {
	if (this->Valid) {
		if (this->pixelPointer()) {
			return this->pixelPointer()[index];
		}
	}

	return { 0, 0 };
}

/*
	Set a pixel's color to the Pattern Image.

	u16 index: The pixel index of the pattern.
	u8 color: The color index.
*/
void PatternImageWW::setPixel(u16 index, u8 color) {
	if (color > 15 || index > 0x3FF) return; // Out of scope.

	if (this->Valid) {
		if (this->pixelPointer()) {
			if (index % 2 == 0) this->pixelPointer()[index / 2].left = color;
			else this->pixelPointer()[index / 2].right = color;
		}
	}
}

/*
	Same as above, just with X & Y position instead of index.
*/
void PatternImageWW::setPixel(u8 x, u8 y, u8 color) { this->setPixel((x + (y * 32)), color); }