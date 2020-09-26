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

#ifndef _LEAFEDIT_CORE_LETTER_WW_HPP
#define _LEAFEDIT_CORE_LETTER_WW_HPP

#include "ItemWW.hpp"
#include "Letter.hpp"

#include <memory>

class ItemWW;

class LetterWW : public Letter {
protected:
	u32 Offset;
	std::shared_ptr<u8[]> data;
	WWRegion region;
public:
	virtual ~LetterWW() { }
	LetterWW(std::shared_ptr<u8[]> letterData, u32 offset, WWRegion saveregion) :
		Letter(letterData, offset), Offset(offset), data(letterData), region(saveregion) { }

	u16 playerid(bool sender) const override;
	void playerid(u16 v, bool sender) override;

	std::u16string playername(bool sender) const override;
	void playername(std::u16string v, bool sender) override;

	u16 townid(bool sender) const override;
	void townid(u16 v, bool sender) override;

	std::u16string townname(bool sender) const override;
	void townname(std::u16string v, bool sender) override;

	u8 playerindex() const override;
	void playerindex(u8 v) override;

	std::u16string intro() const override;
	void intro(std::u16string v) override;

	std::u16string body() const override;
	void body(std::u16string v) override;

	std::u16string end() const override;
	void end(std::u16string v) override;

	u8 nameindex() const override;
	void nameindex(u8 v) override;

	u8 paperid() const override;
	void paperid(u8 v) override;

	u8 flag() const override;
	void flag(u8 v) override;

	u8 senderid() const override;
	void senderid(u8 v) override;

	u8 lettertype() const override;
	void lettertype(u8 v) override;

	std::unique_ptr<Item> item() const override;
private:
	u8* letterPointer() const {
		return data.get() + Offset;
	}
};

#endif