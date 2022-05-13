// #include <chrono>
#include <memory>
#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "scc.h"

int main(int argc, char ** argv)
{
	rclcpp::init(argc, argv);
	std::shared_ptr<Scc> scc_node = std::make_shared<Scc>();
	while(rclcpp::ok())
	{
		scc_node->talk();
		//rclcpp::spin_some(scc_node);
	}
	rclcpp::shutdown();
	return 0;
}
