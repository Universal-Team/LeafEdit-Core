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

#ifndef _LEAFEDIT_CORE_ACRE_WW_HPP
#define _LEAFEDIT_CORE_ACRE_WW_HPP

#include "Acre.hpp"
#include <memory>

class AcreWW : public Acre {
protected:
	std::shared_ptr<u8[]> AcreData;
	u32 Offset;
public:
	virtual ~AcreWW() { };
	AcreWW(std::shared_ptr<u8[]> acreData, u32 offset) :
		Acre(acreData, offset), AcreData(acreData), Offset(offset) { };

	u32 maxAcre() const { return 131; };

	u8 id() const override;
	void id(u8 v) override;
private:
	u8 *acrePointer() const { return this->AcreData.get() + this->Offset; };
};

#endif