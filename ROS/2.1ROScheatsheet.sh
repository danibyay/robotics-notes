#Cheatsheet

source /opt/ros/kinetic/setup.bash

roscore # starts the ros master

#run a node
rosrun turtlesim turtlesim_node
                 turtle_teleop_key
#      package name   node

#list the nodes that are running
rosnode list
#ROSOUT is a node that is always running
#automatically launched by the ros master, is responsible for log messages.
#the rosout topic is the topic to which all nodes send log messages.

#list all the topics
rostopic list

# get info on the pubs and subs of a topic, and the type of message associated
# with the topic
rostopic info <rostopic>
# get info on the message type
rosmsg info <message_type/MessageClass>
#To learn more about messages, it will open small documentation on an editor.
rosed <message type> <Class.msg> 

rostopic echo <name of topic/sth>
# will print the info of a message when its published (live, not a history)
