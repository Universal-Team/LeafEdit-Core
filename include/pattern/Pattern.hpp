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

#ifndef _LEAFEDIT_CORE_PATTERN_HPP
#define _LEAFEDIT_CORE_PATTERN_HPP

#include "PatternImage.hpp"
#include "Player.hpp"
#include "types.hpp"
#include <memory>

class Player;

class Pattern {
protected:
	std::shared_ptr<u8[]> PatternData;
	u32 Offset;
public:
	virtual ~Pattern() { };
	Pattern(std::shared_ptr<u8[]> data, u32 offset) :
		PatternData(data), Offset(offset) { };
	Pattern(const Pattern& pattern) = delete;
	Pattern& operator=(const Pattern& pattern) = delete;

	virtual std::u16string name() const = 0;
	virtual void name(std::u16string v) = 0;

	virtual u16 creatorid() const = 0;
	virtual void creatorid(u16 v) = 0;

	virtual std::u16string creatorname() const = 0;
	virtual void creatorname(std::u16string v) = 0;

	virtual u8 creatorGender() const = 0;
	virtual void creatorGender(u8 v) = 0;

	virtual u16 origtownid() const = 0;
	virtual void origtownid(u16 v) = 0;

	virtual std::u16string origtownname() const = 0;
	virtual void origtownname(std::u16string v) = 0;

	virtual u8 designtype() const = 0;
	virtual void designtype(u8 v) = 0;

	/*
		Pattern Misc.
	*/
	virtual void ownPattern(std::unique_ptr<Player> player) = 0;
	virtual void dumpPattern(const std::string fileName) = 0;
	virtual void injectPattern(const std::string fileName) = 0;

	/*
		Pattern Image.
	*/
	virtual std::unique_ptr<PatternImage> image(u8 pattern) const = 0;
};

#endif