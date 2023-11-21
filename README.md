# DPP_trasa
An application that finds the shortest path between two stations that are part of the PID system

This app needs the txt files form the "source_files.zip"
Alternative way to obtain these data is to download "PID_GTFS.zip" form "https://opendata.praha.eu/datasets/https%3A%2F%2Fapi.opendata.praha.eu%2Flod%2Fcatalog%2F9a6a1d8e-45b9-41de-b9ae-0bcec7126876"
From "PID_GTFS.zip" files "route_stops.txt", "stop_times.txt" and "stops.txt" are needed.
For the app to work properly all spaces within the txt files need to be replaced with underscores.

File DPP_trasa.cpp contains main function.
Files Stop.h and Stop.cpp are source files for the class Stop
Files functions.h and functions.cpp are source files for the functions within the main function.
