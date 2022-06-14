// #include <chrono>
#include <memory>
#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "scc.h"
#include "mavros_msgs/srv/set_mode.hpp"
#include "scc_atlantis/srv/rtl.hpp"
using std::placeholders::_1;
using std::placeholders::_2;

int main(int argc, char ** argv)
{
	// Initialize scc node
	rclcpp::init(argc, argv);
	std::shared_ptr<Scc> scc_node = std::make_shared<Scc>();

	// Initialize SCC RTL service
	rclcpp::Service<scc_atlantis::srv::RTL>::SharedPtr service =
		scc_node->create_service<scc_atlantis::srv::RTL>("return_to_launch",
			std::bind(&Scc::rtl_srv_cb, scc_node, _1, _2));
	// Some logs
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to provide return to launch service");

	// Main cycle
	while(rclcpp::ok())
	{
		scc_node->talk();
		rclcpp::spin_some(scc_node);
	}
	rclcpp::shutdown();
	return 0;
}
