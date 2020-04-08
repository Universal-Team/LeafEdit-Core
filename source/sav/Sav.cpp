/*
*   This file is part of LeafEdit-Core
*   Copyright (C) 2020 DeadPhoenix8091, Epicpkmn11, Flame, RocketRobz, StackZ, TotallyNotGuy
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

// Save class.
#include "Sav.hpp"
#include "SavWW.hpp"
#include "SavNL.hpp"
#include "SavWA.hpp"

#include <cstring>

std::unique_ptr<Sav> Sav::getSave(std::shared_ptr<u8[]> dt, u32 length) {
	switch (length) {
		// 4 known cases for AC:WW.
		case 0x40000:
		case 0x4007A:
		case 0x8007A:
			if (memcmp(dt.get(), dt.get() + 0x12224, 0x12224) == 0) {
				return std::make_unique<SavWW>(dt, WWRegion::JPN, length);
			} else if (memcmp(dt.get(), dt.get() + 0x15FE0, 0x15FE0) == 0) {
				return std::make_unique<SavWW>(dt, WWRegion::EUR, length);
			} else if (memcmp(dt.get(), dt.get() + 0x173FC, 0x173FC) == 0) {
				return std::make_unique<SavWW>(dt, WWRegion::KOR, length);
			} else {
				return nullptr;
			}
		case 0x7FA00:
			return std::make_unique<SavNL>(dt, length);
		case 0x80000:
			return check080000(dt, length);
		case 0x89B00:
			return std::make_unique<SavWA>(dt, length);
	default:
		return nullptr;
	}
}

std::unique_ptr<Sav> Sav::check080000(std::shared_ptr<u8[]> dt, u32 length) {
	if (memcmp(dt.get(), dt.get() + 0x12224, 0x12224) == 0) {
		return std::make_unique<SavWW>(dt, WWRegion::JPN, length);
	} else if (memcmp(dt.get(), dt.get() + 0x15FE0, 0x15FE0) == 0) {
		return std::make_unique<SavWW>(dt, WWRegion::EUR, length);
	} else if (memcmp(dt.get(), dt.get() + 0x173FC, 0x173FC) == 0) {
		return std::make_unique<SavWW>(dt, WWRegion::KOR, length);
	} else {
		return std::make_unique<SavNL>(dt, length);
	}
}