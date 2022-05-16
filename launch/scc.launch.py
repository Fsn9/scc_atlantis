from launch import LaunchDescription
from launch_ros.actions import Node

from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    base_path = os.getcwd()
    print(base_path)
    rviz_path = base_path + '/src/scc_atlantis/rviz/scc.rviz'
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
            name='rviz2',
            output='screen',
            arguments=['-d',str(rviz_path)]
        )
    ])
