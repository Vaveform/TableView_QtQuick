FROM ubuntu:18.04

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y build-essential qt5-default qt5-qmake qtdeclarative5-dev

RUN mkdir /Table

WORKDIR /Table

COPY . .

ENTRYPOINT ["/bin/bash"]
