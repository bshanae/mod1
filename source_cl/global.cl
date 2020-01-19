#define NULL						0
#define EPSILON						0.01

#define IS_VALID(iter)				is_valid(size, &iter)

#define GET_TERRAIN(iter)			get_value_const(terrain_data, size, &iter)
#define GET_WATER(iter)				get_value(water_data, size, &iter)
#define GET_TOTAL(iter)				GET_TERRAIN(iter) + GET_WATER(iter)

typedef enum
{
	flow_right = 0,
	flow_up,
	flow_left,
	flow_down,
	flow_end
}									flow_type;

#define GET_FLOW(iter, flow)		get_flow(flow_horizontal, flow_vertical, size, &iter, flow)
#define SET_FLOW(iter, flow, value)	set_flow(flow_horizontal, flow_vertical, size, &iter, flow, value);

#define SET(data, iter, value)		set_value(data, size, &iter, value);

#define RIGHT(point)				(point2){(point).x + 1, (point).y + 0}
#define UP(point)					(point2){(point).x + 0, (point).y - 1}
#define LEFT(point)					(point2){(point).x - 1, (point).y + 0}
#define DOWN(point)					(point2){(point).x + 0, (point).y + 1}

#define CONST_FLOW					*const_flow

typedef struct
{
	int								x;
	int								y;
}									point2;