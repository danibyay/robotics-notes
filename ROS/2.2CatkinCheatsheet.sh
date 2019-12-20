catkin_init_workspace #only has to be done once
cd home/robot/catkin_ws
catkin_make #builds the workspace
 
#in catkin_ws/devel there is a new setup.bash
source devel/setup.bash
# this must be sourced before using the workspace

#read about naming conventions on catkin workspaces on
ros.org/reps/rep-0128.html

#on the src directory, I can clone git repos that will be existing packages.
cd src
git clone -b <name> <url>
cd ../
catkin_make


#before calling roslaunch always build and source
roslaunch simple_arm robot_spawn.launch
        # <new package>

#dependencies
#to check for missing dependencies in a ROS package
rosdep check <package name>
#to install the packages that are missing
sudo apt-get install ros-kinetic-PACKAGE

#example
sudo apt-get install ros-kinetic-gazebo-ros-control
# list of all packages
https://www.ros.org/browse/list.php


#create a new package.
catkin_create_pkg <name> [dep1 dep2 dep3 ..]
# convention is lower case
