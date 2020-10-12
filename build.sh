#!/bin/bash

apt-get update && apt-get upgrade -y
apt-get install -y build-essential qt5-default qt5-qmake qtdeclarative5-dev
qmake
make
