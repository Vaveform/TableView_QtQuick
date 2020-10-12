# Table View for text file
![TableView image](https://user-images.githubusercontent.com/47713033/95736731-4573b680-0c8f-11eb-83b7-6eaaed065c96.png)
This is programm read text file and show it in Qt Table View
# To build this programm on Linux you should:
* If file **build.sh** have not enoungh permissions (to run this bash script) use **chmod 111 build.sh**
* Run the bash script **build.sh** using **./build.sh** command
Script download all needed packages to build project and use commands **qmake and make** build project

# To build programm in Docker (if you have not a Docker you should download):
* Run build docker image from Dockerfile: **docker build -t TableView -f Dockerfile .**
* Run docker container from docker image: **docker docker run --name TableViewDocker -it**
* In docker image run all steps from building for Linux
