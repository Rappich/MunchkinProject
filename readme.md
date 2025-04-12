# Munchkin Card Game (Unreal Engine Project) - WORK IN PROGRESS

## Project Overview
This project aims to create a digital adaptation of the popular Munchkin card game using **Unreal Engine**. It leverages an earlier C++ console-based prototype from one of my school project as a starting point, which will be **refactored and integrated** into SFML environment. The ultimate goal is a fully playable Munchkin experience within a GUI.

*(The original C++ console project, while unfinished, served as an initial exploration of the core game logic.)*

---

## Target Features (final version)
The following core Munchkin gameplay mechanics are planned for the final version:

1.  **Deck Mechanics**:
    * Randomized Door and Treasure decks.
    * Visual representation of decks and discard piles.
2.  **Combat System**:
    * Engage in battles with monsters.
    * Use items, levels, and abilities (represented visually) to win.
    * Handle combat resolution, rewards, and consequences (like Bad Stuff).
3.  **Player Management**:
    * Manage player character stats (Level, Combat Strength).
    * Visual inventory and equipment slots.
    * Leveling up mechanics.
4.  **Turn-Based Gameplay**:
    * Structured turn phases (Kick Open The Door, Look For Trouble, Loot The Room, Charity).
    * Clear indication of the current player and phase.
5.  **Multiplayer Support**:
    * Initial focus on local hot-seat multiplayer (2-6 players).
    * (Future) Potential for networked multiplayer.

---

## Development Roadmap & Future Goals
* **Phase 1 (Current Focus):**
    * Set up the SFML project structure.
    * Refactor and adapt core C++ logic (cards, player state, basic rules) with SFML.
    * Implement basic card drawing and management UI.
    * Develop the core turn structure and phase transitions.
    * Implement a basic combat resolution system.
* **Phase 2:**
    * Flesh out card effects and interactions.
    * Improve UI/UX for inventory, combat, and player interaction.
    * Implement rules for asking for help, interfering in combat, etc.
    * Basic AI for potential single-player mode or filling empty slots (Optional).
* **Future Enhancements:**
    * Networked multiplayer.
    * Save and load game states.
    * Enhanced graphics, animations, and sound effects.
    * Support for expansions (potentially via data-driven card definitions).
    * Persistent player profiles or statistics (possible database integration).


*(Note: The original, unfinished C++ console code might still exist in the repository history or a specific branch/folder for reference, but it is not the target platform for future development.)*
