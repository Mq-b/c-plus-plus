#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include<iterator>
#include<type_traits>

namespace mylib {

	template<typename Ty>
	struct _vector_iterator {
		using value_type = std::remove_cv_t<Ty>;
		using pointer = Ty*;
		using reference = Ty&;

	};

	template<typename Ty>
	struct _vector_const_iterator : _vector_iterator<Ty> {

	};

	template<typename Ty, typename Alloc = std::allocator<Ty>>
	class vector {
	public:

		using value_type				= Ty;
		using allocator_type			= Alloc;
		using size_type					= std::allocator_traits<Alloc>::size_type;
		using difference_type			= std::allocator_traits<Alloc>::difference_type;
		using reference					= value_type&;
		using const_reference			= const value_type&;
		using pointer					= std::allocator_traits<Alloc>::pointer;
		using const_pointer				= std::allocator_traits<Alloc>::const_pointer;
		using iterator					= _vector_iterator;
		using const_iterator			= const _vector_iterator;
		using reverse_iterator			= std::reverse_iterator<iterator>;
		using const_reverse_iterator	= std::reverse_iterator<const_iterator>;

	};

}
#endif // !__VECTOR_HPP