# Clash Royale RTS (Unreal Engine 5 + Blender)

This repository is a starter project for a single-player mobile RTS inspired by Clash Royale, built for Unreal Engine 5 with procedural low-poly generation via Blender and sound generation via Python.

Features included in the starter foundation:
- Vertical dual-lane arena layout optimized for mobile portrait gameplay
- Elixir economy system with cap at 10 and final-minute speed boost
- 4-card active deck and next preview slot
- Troop archetypes: Tank, Ranged Splash, Swarm, Heavy
- Tower defense rules with King Tower win condition and 3-minute timer
- Basic unit state machine architecture: Idle → Move → Attack → Die
- Enemy/ally targeting logic and lane navigation setup
- Procedural low-poly Blender asset generation
- SFX generation script for card placement, hit, and death
- Unreal project scaffold and gameplay starter classes

Project structure:
- `Source/ClashRoyaleRTS/` — Unreal gameplay classes
- `Config/` — project configuration
- `Tools/` — Blender and audio generation scripts
- `Docs/` — design notes and setup guidance

Quick start:
1. Install Unreal Engine 5.3+.
2. Open `ClashRoyaleRTS.uproject`.
3. Generate project files, then build C++ modules.
4. Create your arena in the editor and wire the actors/cameras.
5. Use the Blender script in `Tools/blender_generate_lowpoly_units.py` to generate low-poly troop meshes.
6. Run `Tools/generate_sfx.py` to create the sound effects.

Notes:
- This is a strong starter foundation, not a complete commercial game build.
- The project is designed for iterative development and expansion into a full mobile RTS with polished gameplay.
