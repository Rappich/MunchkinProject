# Software Requirements Specification

## 1. Introduction

### 1.1 Purpose
The goal of this project is to develop a fully functional digital version of the Munchkin card game, initially designed for terminal-based gameplay. The game will later include database support, save/load functionality, and a graphical user interface (GUI).

### 1.2 Scope
This project recreates the gameplay experience of the Munchkin card game, including:
- Drawing cards from Door and Treasure decks.
- Managing inventory, combat, and player stats.
- Multiplayer mode for 2–6 players.
- Future-proof architecture for additional features like expansions and GUI.

The system will eventually allow for saving/loading game states and a user-friendly interface to extend accessibility and scalability.

---

## 2. Functional Requirements

### Core Gameplay
1. **Deck Mechanics**
   - Randomized shuffling of Door and Treasure decks.
   - Separate discard piles for both deck types.
   - Dynamic addition/removal of cards to/from decks.

2. **Player Actions**
   - Drawing and playing cards.
   - Managing inventory, equipping, and unequipping items.
   - Fighting monsters and applying "bad stuff."

3. **Combat System**
   - Calculating combat strength from levels, items, and class/race abilities.
   - Allowing players to assist or hinder in combat.
   - Handling post-combat outcomes.

4. **Turn System**
   - Sequential turns for players with clear phase transitions.
   - End-turn mechanics, including cleanup and next player setup.

5. **Victory Conditions**
   - Declaring a winner once a player reaches the victory level (default: 10).

---

## 3. Non-Functional Requirements
- **Performance:** Game state updates within 0.5 seconds.
- **Scalability:** Support for additional expansions and future GUI.
- **Reliability:** Prevent rule-breaking actions and ensure game state integrity.
- **Usability:** Intuitive terminal commands, with clear documentation.

---

## 4. Constraints
1. The system must adhere to Munchkin rules.
2. Initial implementation will be terminal-based.
3. Written in C++ with the standard library.

---

## 5. Assumptions
1. Users are familiar with Munchkin rules.
2. Future GUI will integrate with the current logic seamlessly.

---

## 6. Future Roadmap
- Save/Load functionality using file I/O.
- Database support for persistent game states.
- GUI for intuitive gameplay and card management.

---

## 7. References
1. Munchkin Official Rules.
2. GitHub Repository: [MunchkinProject](https://github.com/Rappich/MunchkinProject)
