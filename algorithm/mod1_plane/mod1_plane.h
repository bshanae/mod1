#pragma once

#include "mod1_exception.h"
#include "mod1_model.h"
#include "mod1_point2.h"
#include "mod1_point3.h"

class					mod1_plane : protected mod1_model
{
public :
						mod1_plane() = default;
						~mod1_plane() = default;

	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_coordinate, "Mod1 Plane : Bad coordinate")
	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_logic, "Mod1 Plane : Object not set")

	void				set(
						const mod1_point2<float> &min,
						const mod1_point2<float> &max,
						const float &delta);
	void				build() override;

	virtual mod1_model	*model();

protected :

	mod1_point2<int>	size;
	mod1_point2<float>	min;
	mod1_point2<float>	max;
	float				delta = 0;

	int 				get_index(const mod1_point2<int> &iter) const;

	void 				*get_ptr(const mod1_point2<int> &iter, const mod1_model_data::slot_type &slot);
	void const			*get_ptr(const mod1_point2<int> &iter, const mod1_model_data::slot_type &slot) const;

	bool				is_valid(const mod1_point2<int> &iter, const mod1_model_data::slot_type &slot) const;

	void 				update_normal();
	void 				update_normal_helper(const mod1_point2<int> &iter);
	void				update_normal_helper_test(const mod1_point2<int> &a, const mod1_point2<int> &b, const mod1_point2<int> &c);

	mod1_point3<float>	final_min;
	mod1_point3<float>	final_max;

	void 				update_final();

private :

	bool				is_set = false;

};