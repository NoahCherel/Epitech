#!/bin/bash

# Check if the number of arguments is correct
if [ $# -ne 4 ]; then
    echo "Usage: $0 -n <number of AIs to start> -p <port>"
    exit 1
fi

# Get the number of times to start the binary
n=$2

# Get the port
port=$4

team_name_1="firstteam"
team_name_2="secondteam"

# Start the binary n times
for ((i=1; i<=n; i++)); do
    if [ $((i%2)) -eq 0 ]; then
        ./zappy_ai -p $port -n $team_name_2 &
    else
        ./zappy_ai -p $port -n $team_name_1 &
    fi
done
