#define IS_VALID(iter)								is_valid(size, &iter)

#define GET_TERRAIN(iter)							get_value_const(terrain_data, size, &iter)

#define GET_FLOW(iter, flow)						get_flow(flow_horizontal, flow_vertical, size, &iter, flow)
#define SET_FLOW(iter, flow, value)					set_flow(flow_horizontal, flow_vertical, size, &iter, flow, value)
#define ADD_FLOW(iter, flow, value)					set_flow(flow_horizontal, flow_vertical, size, &iter, flow, GET_FLOW(iter, flow) + value)

#define GET_WATER_UNBALANCED(iter)					get_value(water_data, size, &iter)
#define GET_WATER_BALANCED(iter)					(GET_WATER_UNBALANCED(iter) > EPSILON ? GET_WATER_UNBALANCED(iter) : 0)
#define SET_WATER(iter, value)						set_value(water_data, size, &iter, value)
#define ADD_WATER(iter, value)						set_value(water_data, size, &iter, GET_WATER_BALANCED(iter) + value)
#define ADD_WATER_DIFFUSED(iter, value, diffuse)	ADD_WATER(iter, value * diffuse)

#define GET_TOTAL(iter)								GET_TERRAIN(iter) + GET_WATER_BALANCED(iter)

#define CONST_FLOW									*const_flow
#define CONST_DEPTH									*const_depth