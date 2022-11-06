#!/bin/bash

echo "YOU CAN DO IT!!!!!!"

read comm

git add .
git commit -m "$comm"
git push -u  origin main
