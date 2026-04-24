# Target_Shooting

`TargetShooting` is a C++ console application that simulates a small target shooting competition between three shooters.  
The project demonstrates inheritance, polymorphism, encapsulation, and abstract classes through a simple game loop with two different target types.

## Overview

The program lets the user choose one of two targets:

- `BiathlonTarget`
- `GunTarget`

After that, the user enters the names of three shooters.  
Each shooter fires at the selected target until one of these conditions is met:

- one of the shooters reaches the winning score;
- the target reaches its maximum allowed number of shots.

At the end, the program prints the winner or reports a draw.

## Class Structure

### `AbstractTarget`

Base abstract class for all targets.

Responsibilities:

- stores the maximum number of shots allowed for the target;
- stores the current number of performed shots;
- stores the target range;
- checks whether the target can still be shot;
- defines the polymorphic `Shot(int x, int y)` interface.

Key members:

- `bool canShot() const`
- `virtual float Shot(int x, int y) = 0`
- `size_t GetMaxShotsCount() const`
- `int GetMaxRange() const`

### `BiathlonTarget`

Derived target with a square hit zone in the range `[-5; 5]`.

Scoring rules:

- `(0, 0)` gives `7` points;
- `(-5, 0)`, `(0, -5)`, `(5, 0)`, `(0, 5)` give `1.5` points;
- any other shot inside the valid biathlon zone gives `3` points;
- any shot outside the zone gives `0` points.

Maximum shots:

- `12`

### `GunTarget`

Derived target with concentric scoring zones.

Scoring rules:

- outer miss zone gives `0` points;
- sectors `1-2` give `1` point;
- sectors `3-6` give `2` points;
- sectors `7-8` give `3` points;
- sector `9` gives `4` points;
- sector `10` gives `5` points.

Maximum shots:

- `21`

### `Shooter`

Represents a participant in the competition.

Responsibilities:

- stores the shooter name;
- stores the accumulated score;
- stores a pointer to the currently selected target;
- generates random shot coordinates;
- sends the shot to the chosen target and accumulates the result.

Key members:

- `string GetName() const`
- `float GetShotsRate() const`
- `void SetName(string name)`
- `void SetTarget(AbstractTarget* target)`
- `void AddShotsRate(float rate)`
- `float Shot(int& x, int& y)`

## Game Rules

- There are always three shooters in the match.
- The user selects exactly one target type before the match starts.
- Every shooter fires in turn.
- Shot coordinates are generated randomly in the range `[-20; 20]`.
- The winner is the shooter with the highest score once the round ends.
- If all results are equal, the game ends in a draw.

## Project Goals

This project is a compact educational example of how to model a real-world domain with C++ classes:

- abstract base class for shared behavior;
- derived classes for specialized targets;
- runtime polymorphism through a virtual shooting method;
- simple score aggregation and game flow control.
