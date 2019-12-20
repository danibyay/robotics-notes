// typical definition format for publishers
ros::Publisher pub1 = n.advertise<message_type>("/topic_name", queue_size);

// n is a NodeHandle, to communicate with ROS master
// advertise is to inform you want to publish to the topic

// queue_size indicates the max number of messages that will be
// stored until the messages can be sent.
// if limit is reached, oldest messages will be dropped.

pub1.publish(msg);

// docs : http://docs.ros.org/jade/api/roscpp/html/classros_1_1Publisher.html


//For CmakeLists.txt when adding a node.
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(simple_mover src/simple_mover.cpp)
target_link_libraries(simple_mover ${catkin_LIBRARIES})
add_dependencies(simple_mover simple_arm_generate_messages_cpp)


// definition format for services
ros::ServiceServer service = n.advertiseService(`service_name`, handler);
// from the command line, call a service
rosservice call service_name “request”
// in cpp within a node, define a client
ros::ServiceClient client = n.serviceClient<package_name::service_file_name>("service_name");
// request the service, via the client.
client.call(srv);


// create a service file inside the node file structure
// simple_arm/srv/Name.srv

// Modify the node's CmakeLists add_service_files macro.
// same for generate_messages macro.

// modify package.xml (dependencies should be there)

// see if ros sees thee service
cd catkin_ws
source devel/setup.bash
rossrv show GoToPosition


// build catkin_ws, modify launch file.
roslaunch simple_arm <node> robot_spawn.launch <launchfile>
rosenode list
rosservice list
// to view what the camera sees
rqt_image_view /rgb_camera/image_raw
//this time, instead of calling the simple_mover, which will move all the time.
//we can call the service upon a cmd line command., just once

rosservice call /arm_mover/safe_move "joint_1: 1.57
joint_2: 1.57"

// there has to be a line break between the two request parameters
// it can be written as param1 > param 2

rosparam set /arm_mover/max_joint_2_angle 1.57
// modify the maximum on the parameter server

// definition format for clients
ros::ServiceClient client = n.serviceClient<package_name::service_file_name>("service_name");
// definition format for subscribers
ros::Subscriber sub1 = n.subscribe("/topic_name", queue_size, callback_function);
// the callback function will be run when a message comes in.

roslaunch-logs
tells you where the logs are.
