import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/jy/ros2/colcon_ws/src/install/my_first_python_pkg'
