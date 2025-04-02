# Munchkin Card Game (Unreal Engine Project) - WORK IN PROGRESS

## Project Overview
This project aims to create a digital adaptation of the popular Munchkin card game using **Unreal Engine**. It leverages an earlier C++ console-based prototype as a starting point, which will be **refactored and integrated** into the Unreal Engine environment. The ultimate goal is a fully playable Munchkin experience within a modern game engine.

*(The original C++ console project, while unfinished, served as an initial exploration of the core game logic.)*

---

## Target Features (Unreal Engine Implementation)
The following core Munchkin gameplay mechanics are planned for the Unreal Engine version:

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
    * Set up the Unreal Engine project structure.
    * Refactor and adapt core C++ logic (cards, player state, basic rules) for Unreal.
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

---

## Getting Started (Unreal Project)

### Prerequisites
* **Unreal Engine** [Specify Version, e.g., 5.3 or later]
* **Git** for version control.
* An IDE compatible with Unreal Engine (e.g., Visual Studio with C++ workload, Rider for Unreal Engine).

### Steps
1.  Clone the repository:
    ```bash
    git clone [https://github.com/Rappich/MunchkinProject](https://github.com/Rappich/MunchkinProject)
    ```
2.  Navigate to the project directory.
3.  Generate project files (if needed, often done by right-clicking the `.uproject` file).
4.  Open the `.uproject` file with Unreal Engine.
5.  Compile and run the project from the Unreal Editor.

---

*(Note: The original, unfinished C++ console code might still exist in the repository history or a specific branch/folder for reference, but it is not the target platform for future development.)*
