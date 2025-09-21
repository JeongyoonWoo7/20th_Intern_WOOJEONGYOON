from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([

        Node(
            package="robot_arm_gui",
            executable="robot_arm_gui",
            name="robot",
            namespace="turtlesim1"
        ),

        Node(
            package="turtlesim_drawer",
            executable="drawer",
            name="turtle",
            namespace="turtlesim2"
        )
    ])

