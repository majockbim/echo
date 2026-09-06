# echo

## Requirements
* Python 3
* PlatformIO Core (CLI)
* Neovim + `clangd` (for LSP)

## Commands

**1. Generate `compile_commands.json` (for Neovim LSP):**
```bash
pio run -t compiledb
```

**2. Compile project:**
```bash
pio run
```

**3. Upload to PLC:**
```bash
pio run -t upload
```

**4. View Serial Monitor:**
```bash
pio device monitor
```

## Cool things that made this possible
* [PlatformIO](https://platformio.org/)
* [Neovim](https://neovim.io/)
* [clangd](https://clangd.llvm.org/)
* [P1AM-100](https://www.olimex.com/Products/PLC/P1AM-100/Open-Source-Hardware)
* [P1-08SIM](https://www.olimex.com/Products/PLC/P1-08SIM/Open-Source-Hardware)
