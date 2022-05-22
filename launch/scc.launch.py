from launch import LaunchDescription
from launch_ros.actions import Node

from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    base_path = os.getcwd()
    rviz_crow_path = base_path + '/src/scc_atlantis/rviz/crow.rviz'
    rviz_raven_path = base_path + '/src/scc_atlantis/rviz/raven.rviz'
    rviz_sense_path = base_path + '/src/scc_atlantis/rviz/sense.rviz'
    return LaunchDescription(
    [
        Node(
            package='scc_atlantis',
            namespace='scc',
            executable='run_scc',
            name='scc',
            output='screen'
        ),
        Node(
            package='rviz2',
            namespace='rviz2',
            executable='rviz2',
            name='rviz_crow',
            output='screen',
            arguments=['-d',str(rviz_crow_path)]
        ),
        Node(
            package='rviz2',
            namespace='rviz2',
            executable='rviz2',
            name='rviz_raven',
            output='screen',
            arguments=['-d',str(rviz_raven_path)]
        ),
        Node(
            package='rviz2',
            namespace='rviz2',
            executable='rviz2',
            name='rviz_sense',
            output='screen',
            arguments=['-d',str(rviz_sense_path)]
        ),
        Node(
            package = "tf2_ros",
            executable = "static_transform_publisher",
            arguments = ["0","0","0","0","0","0","map","os_sensor"]
        ),
        Node(
            package = "tf2_ros",
            executable = "static_transform_publisher",
            arguments = ["0","0","0","0","0","0","os_sensor","lidar"])
    ])
