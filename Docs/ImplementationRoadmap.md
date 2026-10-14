# Unreal gameplay implementation checklist

This is the next build sequence for the prototype:

1. Create `GameplayMap` and place arena builder in the scene.
2. Spawn Blue and Red towers with correct team names and king tower status.
3. Add `AClashRoyaleRTSGameModeBase` to the level and assign it to the map.
4. Add a `PlayerController` with a `DeckComponent` and `RTSPlayerController`.
5. Add a `UCombatHUDWidget` and link it to HUD update events.
6. Add `EnemyWaveManager` in the level and assign spawn points.
7. Place models generated from Blender into the `Content/Art` folder and assign them to units and towers.
8. Add a touch-friendly input flow for mobile deployment.
9. UMG HUD: elixir bar, deck slots, match timer, crown counters, result panel.
10. Final QA: compile, run in editor, verify elixir generation, spawning, tower damage, win conditions.

Focus areas:
- Arena and lane setup
- Elixir economy
- Troop AI movement and attack loops
- Tower detection and destruction
- Enemy rhythm and match balance
- Mobile deployment controls and UI polish
