#!/bin/bash

ARGUMENTS=(
	"0"
	"nan"
	"42.0f"
)

# Run valgrind for each argument
for arg in "${ARGUMENTS[@]}"; do
	echo "./convert $arg"
	./ex00 "$arg"
	echo "--------------------------------------------"
done