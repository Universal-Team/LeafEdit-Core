# LeafEdit-Core

## This is the core which LeafEdit uses for save editing.

### LeafEdit-Core is going to support the following games:
- Animal Crossing: Wild World
- Animal Crossing: New Leaf
- Animal Crossing: New Leaf Welcome amiibo
- Animal Crossing: Happy Home Designer

For a list of all currently implemented features, please take a look [here](https://github.com/Universal-Team/LeafEdit-Core/blob/master/core-features.md).

If you notice a bug, which might be related to the core, feel free to create an issue at the issues section or let us know on the Universal-Team's discord server [here](https://universal-team.net/discord). Just let us know at the `#animal-crossing` channel, that's where all of the LeafEdit-Core and LeafEdit | WildEdit app stuff gets discussed.

## Using LeafEdit-Core
NOTE: This requires C++17 or later(?), to compile. LeafEdit uses C++17.

To use LeafEdit-Core, you will need to create a file called `leafedit_core.hpp`.

The file SHOULD look like this:
```cpp
#ifndef _LEAFEDIT_CORE_HPP
#define _LEAFEDIT_CORE_HPP

#define _LANG_PATH "romfs:/lang/strings"
#define _ITEM_BIN_PATH "romfs:/itemBins"

#endif
```

You can also do it within the Makefile with the CXXFLAGS for example.

`-D_CORE_CONFIGURED` would be required if you use this.. so it does not read from the `leafedit_core.hpp` file then.

While.. the definitions should be, where the specific stuff is stored. On 3DS, it'll be inside the ROM filesystem, hence `romfs:/`, while on different platforms, it might be just the path.. such as `strings`.

If you would like to work with Item Whitelisting, you will also need the `.bin` files from the [ItemBins](https://github.com/Universal-Team/LeafEdit-Extras/tree/master/assets). These files should be placed in the path defined by `_ITEM_BIN_PATH`.

## Credits
- [Cuyler](https://github.com/Cuyler36), [Slattz](https://github.com/Slattz), [NLTK](https://github.com/Slattz/NLTK), [ACSE](https://github.com/Cuyler36/ACSE): For previous core work from NLTK, ACSE and research.

- [piepie62](https://github.com/piepie62): For helping me out by problems and [PKSM-Core](https://github.com/FlagBrew/PKSM-Core)'s Save Structure. LeafEdit's Core Structure is very similar to the one from PKSM-Core.

- [Pk11](https://github.com/Epicpkmn11): For helping me with the Core Rewrite.

- [RedShyGuy](https://github.com/RedShyGuy): For helping with the core.

- [SuperSaiyajinStackZ](https://github.com/SuperSaiyajinStackZ): The Main Developer of LeafEdit.

## Contributors
For a list of all contributors, look at [Contributors.md](https://github.com/Universal-Team/LeafEdit-Core/blob/master/Contributors.md).