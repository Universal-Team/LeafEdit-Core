/*
*   This file is part of LeafEdit-Core
*   Copyright (C) 2020 Universal-Team
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

#include "checksum.hpp"
#include "SavHHD.hpp"

/* Get Player data. For now uses special player class for AC:HHD. */
std::unique_ptr<Player> SavHHD::player(int player, int index) const {
	return nullptr;
}

/* Get Villager data. */
std::unique_ptr<Villager> SavHHD::villager(int villager) const {
	return nullptr;
}

/* Get Town data. Will likely use a special class. */
std::unique_ptr<Town> SavHHD::town() const {
	return nullptr;
}

/* Get Island data. */
std::unique_ptr<Island> SavHHD::island() const {
	return nullptr;
}

std::unique_ptr<Shop> SavHHD::shop() const {
	return nullptr;
}

/* Last call before writing to file. Update Checksum. */
void SavHHD::Finish(void) {
	Checksum::FixHHDChecksum(this->savePointer());
}