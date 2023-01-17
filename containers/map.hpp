#ifndef MAP_HPP_
#define MAP_HPP_

#include <memory>
#include <map>
#include <functional>
#include <pair.hpp>
#include <AVLtree.hpp>

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T>>>
	class map {
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef Allocator::pointer pointer;
		typedef Allocator::const_pointer pointer;

		private:
			typedef AVLtree<key_type, mapped_type, key_compare, allocator_type> tree_type;
			tree_type tree_;
	};
}

#endif
