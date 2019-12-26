#pragma once

#include "mod1_model.h"
#include "mod1_point2.h"
#include "mod1_point3.h"

class					mod1_plane : public mod1_model
{
public :
						mod1_plane() = default;
						~mod1_plane() = default;

	struct				exception_bad_coordinate : public std::exception
	{
		const char		*what() const noexcept override;
	};

	struct				exception_not_set : public std::exception
	{
		const char		*what() const noexcept override;
	};

	void				set(
						const mod1_point2<int> &min,
						const mod1_point2<int> &max,
						const int &delta);
	void				build() final;

protected :

	mod1_point2<int>	size;
	mod1_point2<int>	min;
	mod1_point2<int>	max;
	int					delta = 0;

	int 				get_index(const mod1_point2<int> &iter) const;

	void 				*get_ptr(const mod1_point2<int> &iter, const mod1_model_data::slot_type &slot);
	void const			*get_ptr(const mod1_point2<int> &iter, const mod1_model_data::slot_type &slot) const;

private :

	bool				is_set = false;
};


