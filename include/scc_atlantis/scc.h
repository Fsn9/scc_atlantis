#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Scc : public rclcpp::Node
{
	public:
		Scc();
		void talk();
	private:
		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};
