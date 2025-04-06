#!/bin/bash

# Create a new directory called rover_mission and navigate into it.
mkdir -p rover_mission
cd rover_mission || exit

# Create three empty files: log1.txt, log2.txt, log3.txt
touch log1.txt log2.txt log3.txt

# Rename log1.txt to mission_log.txt
mv log1.txt mission_log.txt

# Find all files in the current directory that have a .log extension
echo "Finding .log files:"
find . -type f -name "*.log"

# Display contents of mission_log.txt without opening it in an editor
echo "Displaying contents of mission_log.txt:"
cat mission_log.txt

# Find and display lines containing the word 'ERROR' in mission_log.txt
echo "Searching for lines containing 'ERROR' in mission_log.txt:"
grep "ERROR" mission_log.txt

# Count the number of lines in mission_log.txt
echo "Counting lines in mission_log.txt:"
wc -l mission_log.txt

# Show system's current date and time
echo "Date and time:"
date

# Display CPU usage (one-time snapshot)
echo "CPU usage snapshot:"
top -b -n 1 | head -n 10

# Schedule a system shutdown in 10 minutes
echo "Scheduling system shutdown in 10 minutes..."
sudo ./script.sh
echo "System shutting down in 10 minutes."
