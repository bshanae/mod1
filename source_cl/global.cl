#define NULL						0
#define EPSILON						0.01

typedef enum
{
	flow_right = 0,
	flow_up,
	flow_left,
	flow_down,
	flow_end
}									flow_type;

typedef struct
{
	int								x;
	int								y;
}									point2;


#define RIGHT(point)				(point2){(point).x + 1, (point).y + 0}
#define UP(point)					(point2){(point).x + 0, (point).y - 1}
#define LEFT(point)					(point2){(point).x - 1, (point).y + 0}
#define DOWN(point)					(point2){(point).x + 0, (point).y + 1}