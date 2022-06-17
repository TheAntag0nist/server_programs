# Technical description of the project
This project it's just template for server and client on C/C++.    
It's open and free for using (License - MIT).

## What your need to compile and execute
For compile code and use it you need:
+ g++ (version 9.4.0)
+ make (version 4.2.1) 
+ C++14

## How to install needed packages
For installing all needed packages execute that commands
- sudo apt install g++
- sudo apt install make  
or  execute script in root folder
- sh install_pkgs.sh

## How to compile
To compile project just execute build_all.sh in root directory   
Example: sh build_all.sh
If you want rebuild or rebuild and run only one project  
Just go to project directory (example: for client it's _user_part)
and execute in terminal command:  
- make rebuild - for rebuilding
- make run - for rebuilding and executing project

## How to use it
Template version contains two basic functions:
+ -exit - close connection
+ -send - basic function for sending message  
(In future can be more functions)
