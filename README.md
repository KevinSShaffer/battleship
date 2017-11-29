*******************************************************
*  Name      :  Kevin Shaffer
*  Student ID:  106069743
*  Class     :  CSCI 2312-001        
*  HW#       :  Final
*  Due Date  :  Nov 28th, 2017
*******************************************************

## Read Me


*******************************************************
   Description of the program
*******************************************************

This application is a duplication of the board game 
Battleship.  The player is against the computer and 
the game takes turns until one of the players has lost.


*******************************************************
   Source files
*******************************************************

Name: board.cpp
  Implementation for the Board class methods.

Name: board.h
  Declaration for the Board class.

Name: csv_reader.cpp
  Implementation for the CsvReader static class methods.

Name: csv_reader.h
  Declaration for the CsvReader static class.

Name: exceptions.h
  Contains the definitions for the custom
  exceptions used by the animal classes.

Name: exceptions.cpp
  Contains the member functions for the exception
  classes.

Name: game.cpp
  Implementation for the Game class.  This class
  drives the game logic.

Name: game.h
  Declaration for the Game class.

Name: grid.cpp
  Implementation of the Grid class methods.  The
  Grid class is mainly a 2d vector with additional
  functionality.

Name: grid.h
  Declaration for the Grid class.

Name: main.cpp
  Main program.  This is the driver program that 
  creates the game object and loops until complete.

Name: player.cpp
  Implementation for the Player class methods.

Name: player.h
  Declaration for the Player class.

Name: position.cpp
  Implementation for the classes in the Position
  namespace.

Name: position.h
  Declaration for the classes in the Position
  namespace.

Name: ship.cpp
  Immplementation for the Ship class methods.

Name: ship.h
  Declaration for the Ship class.

Name: shot.cpp
  Implementation for the Shot class methods.

Name: shot.h
  Declaration for the Shot class.

Name: str_func.h
  Contains the definitions for the string functions
  and places them in their own namespace.

Name: str_func.cpp
  Contains the member functions for the string 
  functions.   
   
*******************************************************
   Circumstances of programs
*******************************************************

   The program runs successfully.
   
   The program was developed using visual studios and 
   compiled using gcc version 7.2.0 
   (Rev1, Built by MSYS2 project).

   The program was also tested by compiling and running
   on CSEGrid.

   This application lives in an open source repository
   at https://github.com/KevinSShaffer/battleship


*******************************************************
   How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip Final.zip

   Now you should see:
    Directory named 'battleship' with the files:
      ai_ships.csv
      board.cpp
      board.h
      csv_reader.cpp
      csv_reader.h
      exceptions.cpp
      exceptions.h
      game.cpp
      game.h
      grid.cpp
      grid.h
      main.cpp
      makefile
      player.cpp
      player.h
      player_ships.csv
      position.cpp
      position.h
      README.md
      ship.cpp
      ship.h
      shot.cpp
      shot.h
      str_func.cpp
      str_func.h

    Directory named 'ships' with the files:
      ai.csv
      player.csv

2. Build the program.
    Change to the directory that contains the file by:
    % cd battleship 

    Compile the program by:
    % make

3. Run the program by:
   % ./battleship

4. Delete the obj files, executables, and core dump by
   % make clean