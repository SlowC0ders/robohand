# RoboHand
### That is the open source project, whose main purpose is to create an automatic manipulator.
***Languages: C++, Python.***
    
* Our system is built in ROS (robot operation system) framework.
* All projects are described with Nodes and Topics.
*
    
### Structure (parts):
1. Image analysing and detecting reference points
2. Convering object's coordinates from image to real
3. Inverse kinematics problem
4. Hand control by results of the previous part
5. ...

### How to install ROS:
Here you can see tiny instruction how to install ROS enviroment:
1. Setup your computer to accept software from packages.ros.org. 
    sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
2. Set up your keys.
    sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
3. Make sure your Debian package index is up-to-date.
    sudo apt update
4. Install ROS.
    sudo apt install ros-melodic-desktop
5. Install tools.
    sudo apt install python-rosinstall python-rosinstall-generator python-wstool build-essential
For more information go there: [ROS instalation](http://wiki.ros.org/melodic/Installation/Ubuntu)

### Working with ROS:
In order to work with ROS you must:
1. Go to the project folder
    cd robohand
2. Here you must enter in the "devel"
    cd devel
3. And run bash's script "setup.bash"
    source setup.bash
4. Now you can use various tools of the ROS enviroment
  
Every changes in the project are assembeled by "catkin_make" command:
    catkin_make

### How run system
If you have made all mentioned above (espetialy run setup.bash), then you can run system (now we can make run it only by hands :[).
1. Run the system core with command:
```
    roscore
```
2. Look there, if you want /src/arm/scrips/detector.py
  * Here you can find the file for first task (Image analysis).
  * In order to run this node, you must type that command:
```
    rosrun arm detector.py
```
3. Ang here we have another important part /src/arm/src/converter.cpp
  * That part responsible for mathematical calculation for the purpose to determine real coordinates.
  * In order to run this node, you must type that command:
```
    rosrun arm converter
```
