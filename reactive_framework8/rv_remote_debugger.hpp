#pragma once
#include "stdafx.h"
#include "rv_abstract_debugger.hpp"

namespace reactive_framework8
{
	struct tcp_message;

	class rv_remote_debugger : public rv_abstract_debugger
	{
	public:
		rv_remote_debugger();
		~rv_remote_debugger();

		void notify_value_change(std::string rv_name_, std::string value_);
		void notify_rv_assigned_to(std::string rv_name_);
		void notify_new_operator(std::string op_name_);

		void add_edge_from(void* node_ptr_, std::type_index node_type_, void* operator_ptr_, std::type_index operator_type_);
		void add_edge_to(void* operator_ptr_, std::type_index operator_type_, void* node_ptr_, std::type_index node_type_);

	private:
		utility::client _client;

		std::unordered_set<std::string> _known_objects;

		void _send_message(tcp_message&);
	};

}
