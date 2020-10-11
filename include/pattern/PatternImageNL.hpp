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

#ifndef _LEAFEDIT_CORE_PATTERN_IMAGE_NL_HPP
#define _LEAFEDIT_CORE_PATTERN_IMAGE_NL_HPP

#include "PatternImage.hpp"

class PatternImageNL : public PatternImage {
protected:
	std::shared_ptr<u8[]> PatternData;
	u32 PatternOffset;
	u32 PaletteOffset;
public:
	virtual ~PatternImageNL() { };
	PatternImageNL(std::shared_ptr<u8[]> data, u32 patternOffset, u32 paletteOffset) :
		PatternImage(), PatternData(data), PatternOffset(patternOffset), PaletteOffset(paletteOffset) { };

	bool isValid() const override { return this->Valid; };

	u8 getPaletteColor(u8 plt) const override;

	u8 getWWPaletteIndex() const override;

	void setPaletteColor(u8 index, u8 color) override;

	pixel getPixel(u16 pixel) const override;

	void setPixel(u16 index, u8 color) override;

	void setPixel(u8 x, u8 y, u8 color) override;
private:
	bool Valid = true;

	pixel *pixelPointer() const { return (pixel *)(this->PatternData.get() + this->PatternOffset); };
	u8 *paletteData() const { return this->PatternData.get() + this->PaletteOffset; };
};

#endif