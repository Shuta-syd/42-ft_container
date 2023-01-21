#ifndef MAP_HPP_
#define MAP_HPP_

#include <memory>
#include <functional>
#include <utility.hpp>
#include <reverse_iterator.hpp>
#include <bidirectional_iterator.hpp>

namespace ft {
	template <class Key, class T , class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
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
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::bidirectional_iterator<pointer, Compare> iterator;
		typedef ft::bidirectional_iterator<const_pointer, Compare> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		class value_compare : public std::binary_function<value_type,value_type,bool> {
			friend class map;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
		};

		/*----------------------------------------
		[Constructors & Destructor]
		----------------------------------------*/
		// default constructor
		map() {}

		// empty constructor
		explicit map( const Compare& comp, const Allocator& alloc = Allocator() ): key_compare_(comp), alloc_(alloc) {}

		// range constructor
		template<class InputIt>
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) {}

		// copy constructor
		map( const map& rhs ): tree_(rhs.tree_), key_compare(rhs.key_compare) {}

		// destructor
		~map() {}

		// copy operator
		map& operator=( const map& rhs ) {}

		allocator_type get_allocator() const {}


		/*----------------------------------------
		[Iterators]
		----------------------------------------*/
		iterator begin() { return tree_.begin(); }
		const_iterator begin() const { return tree_.begin(); }
		iterator end() { return tree_.end(); }
		const_iterator end() const { return tree_.end(); }
		reverse_iterator rbegin() { return tree_.end(); }
		const_reverse_iterator rbegin() const { return tree_.end(); }
		reverse_iterator rend() { return tree_.begin(); }
		const_reverse_iterator rend() const { return tree_.begin(); }

		/*----------------------------------------
		[Capacity]
		----------------------------------------*/
		bool empty() const {}
		size_type size() const {}
		size_type max_size() const {}

		/*----------------------------------------
		[Element access]
		----------------------------------------*/
		mapped_type& operator[] (const key_type& k) {}
		mapped_type& at (const key_type& k) {}
		const mapped_type& at (const key_type& k) const {}

		/*----------------------------------------
		[Modifiers]
		----------------------------------------*/
		pair<iterator,bool> insert (const value_type& val) {}
		iterator insert (iterator position, const value_type& val) {}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {}

		void erase (iterator position) {}
		size_type erase (const key_type& k) {}
		void erase (iterator first, iterator last) {}

		void clear() {}

		void swap (map& x) {}

		/*----------------------------------------
		[Look up]
		----------------------------------------*/
		size_type count( const Key& key ) const {}

		iterator find( const Key& key ) {}
		const_iterator find( const Key& key ) const {}

		ft::pair<iterator,iterator> equal_range( const Key& key ) {}
		ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {}

		iterator lower_bound( const Key& key ) {}
		const_iterator lower_bound( const Key& key ) const {}

		iterator upper_bound( const Key& key ) {}
		const_iterator upper_bound( const Key& key ) const {}

		value_compare value_comp() const { return val_compare_; }
		key_compare key_comp() const { return key_compare_; }

	private:
		typedef AVLtree<value_type, key_compare> tree_type;
		tree_type tree_;
		value_compare val_compare_;
		key_compare key_compare_;
		allocator_type alloc_;


	};
	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {}
}

#endif
