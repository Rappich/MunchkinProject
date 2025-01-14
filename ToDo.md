### **To-Do List**

#### Core Development
1. **Game Initialization:**
   - [x] Implement player setup (number of players, names).
   - [ ] Populate Door and Treasure decks with cards from predefined configurations.

2. **Deck Operations:**
   - [x] Create shuffle logic using `Deck::shuffleDeck`.
   - [x] Implement dynamic card drawing with `Deck::drawCard`.

3. **Turn System:**
   - [ ] Implement `Game::playerTurn` to handle:
     - Drawing a card from the Door deck.
     - Combat or non-combat logic.
   - [ ] Manage end-turn transitions with `Game::endTurn`.

4. **Combat System:**
   - [ ] Calculate player combat strength (base + items + bonuses).
   - [ ] Handle monster levels and bad stuff logic.
   - [ ] Allow other players to assist or hinder during combat.

5. **Player Mechanics:**
   - [x] Add inventory operations (`equipItem`, `unequipItem`, etc.).
   - [x] Implement level-up and level-down mechanisms.

6. **Victory Check:**
   - [ ] Finalize `Game::checkVictory` for determining a winner.

---

#### Testing
- [ ] Unit tests for:
  - Deck shuffling and drawing mechanics.
  - Combat logic with varied scenarios.
  - Player level and inventory management.
- [ ] Integration tests for turn sequences and edge cases.

---

#### Future Development
1. **Save/Load System:**
   - [ ] Design save structures for player states and deck contents.
   - [ ] Implement file-based save/load using serialization.

2. **Database Integration:**
   - [ ] Store persistent game states and statistics in a database.

3. **GUI Design:**
   - [ ] Build a basic GUI prototype.
   - [ ] Integrate drag-and-drop functionality for cards.
   - [ ] Display player stats and inventory visually.

---

