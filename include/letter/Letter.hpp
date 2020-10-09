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

#ifndef _LEAFEDIT_CORE_LETTER_HPP
#define _LEAFEDIT_CORE_LETTER_HPP

#include "Item.hpp"
#include "types.hpp"
#include <memory>

class Letter {
protected:
	std::shared_ptr<u8[]> LetterData;
	u32 Offset;
public:
	virtual ~Letter() { };
	Letter(std::shared_ptr<u8[]> data, u32 offset) :
		LetterData(data), Offset(offset) { };
	Letter(const Letter& letter) = delete;
	Letter& operator=(const Letter& letter) = delete;

	virtual u16 playerid(bool sender) const = 0;
	virtual void playerid(u16 v, bool sender) = 0;

	virtual std::u16string playername(bool sender) const = 0;
	virtual void playername(std::u16string v, bool sender) = 0;

	virtual u16 townid(bool sender) const = 0;
	virtual void townid(u16 v, bool sender) = 0;

	virtual std::u16string townname(bool sender) const = 0;
	virtual void townname(std::u16string v, bool sender) = 0;

	virtual u8 playerindex() const = 0;
	virtual void playerindex(u8 v) = 0;

	virtual std::u16string intro() const = 0;
	virtual void intro(std::u16string v) = 0;

	virtual std::u16string body() const = 0;
	virtual void body(std::u16string v) = 0;

	virtual std::u16string end() const = 0;
	virtual void end(std::u16string v) = 0;

	virtual u8 nameindex() const = 0;
	virtual void nameindex(u8 v) = 0;

	virtual u8 paperid() const = 0;
	virtual void paperid(u8 v) = 0;

	virtual u8 flag() const = 0;
	virtual void flag(u8 v) = 0;

	virtual u8 senderid() const = 0;
	virtual void senderid(u8 v) = 0;

	virtual u8 lettertype() const = 0;
	virtual void lettertype(u8 v) = 0;

	virtual std::unique_ptr<Item> item() const = 0;
};

#endif