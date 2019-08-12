# bestgameever
Working title for long-running single-player game.

## Rules

1. Player starts at a 100 HP. If HP goes to 0, player dies.
2. Player starts with 1 life.
3. Score is how far they have gotten in the shortest time.
4. They can win by getting to the last box/door in the last room after beating the last monster.

## Gameplay

1. Use mouse, or up-down-left-right keys to navigate player across screen.
2. Player moves left to right (left-right keys). Player came jump (up key).
3. What are the obstacles?
- The ground varies in elevation (player has to jump to get over elevation).   
- Monsters (moving up-down and left-right). If player runs into monster, player loses HP (depending on monster).
- To advance through the game, they have to go through doors.
- Each room has different monsters.
4. Player can attack and kill monsters (d key is for block, spacebar is for main attack).

Game currently has 5 rooms:
- Each room has a monster.
- Each monster requires a certain # of attacks to kill.
- Each monsters' attack on you removes a certain amount of life.
- Rooms alternate by day and night cycle. Night monsters are night-themed.

## Game Theme/Visuals

"Princess Werebear"

Princess who is a werebear fighting the monsters.
- During the day, she's a princess.
- At night, she is a werebear and her fighting style changes.
- Night to day switch happens every 4 minutes.

Setting is in a castle with different rooms.

Monster Ideas:
- Witch
- Troll (Medium or Large troll) - an entire family of trolls
- Animated armor (which comes to life and attacks in the armor room)
- Prince (twin brother who wants her throne, mini-boss)
- Dragon (boss at the end)

Rooms:
- Dungeons (troll family)
- Dining hall (witch)
- Courtyard (prince)
- Armory (animated armor)
- Throne room (boss)

## UI User Flow

1. User opens desktop app.
Home-page has the top 10 scores.
2. User clicks start button to start the game.
3. Players screen displays:
- HP (out of 100)
- Monsters defeated (out of 5)
- Time "elapsed" in number of days
- Current score (determine formula for this)
- Pause button to pause the game.
(Esc button is also a pause and space-bar can restart - or by pressing the start button)
4. When they die, it displays the score and whether it is a high score.
They have the option to:
- Play again
- Go to home screen of game

## Feature to be added later
1. Save progress in game:
- In paper Mario, there are saved blocks but no "pause button"
- In temple run, there is a pause button but no "saving" of gameplay
- Perhaps we can later implement a "saved block", i.e. "saved progress" based on room.
