# Clash Royale RTS — Game Design Notes

This project follows a Clash Royale-inspired vertical RTS loop:

- Two lanes with a central river and bridges
- One player-side arena and one enemy-side arena
- Real-time elixir economy capped at 10
- Four player deck cards with one next-card preview
- Troop collection: Tank, Ranged Splash, Swarm, Heavy
- Defensive towers: two princess towers + one king tower per side
- Tower destruction and king tower elimination win states
- Match timer ends after 3 minutes with crown comparison

## Core systems to implement in the editor
- Create a vertical `GameplayMap` in Unreal
- Add a `Blueprint` version of `AClashRoyaleRTSGameModeBase`
- Spawn `ATower` instances for each side
- Build two lane paths with `ALaneWaypoint` actors
- Connect troop logic to `CurrentTarget` and `TeamName`
- Add a widget for the Elixir bar and card deck
- Add simple touch input for deploy actions

## Recommended iteration order
1. Arena and lane setup
2. Elixir + deck UI
3. Troop movement and targets
4. Tower combat and king tower logic
5. Match timer / win conditions
6. Visual polish and procedural art
7. Audio and mobile UX tuning
