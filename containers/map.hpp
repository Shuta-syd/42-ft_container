#ifndef MAP_HPP_
#define MAP_HPP_

#include <memory>
#include <functional>
#include <utility.hpp>
#include <reverse_iterator.hpp>
#include <bidirectional_iterator.hpp>
#include <algorithm.hpp>

namespace ft {
	template <class Key, class T , class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<Key, T> > >
	class map {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<Key, T> value_type;
			typedef node<value_type> node_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef Compare key_compare;
			typedef typename std::equal_to<Key> equal_to;
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef AVLtree<value_type, key_compare, node_type> tree_type;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef typename tree_type::iterator iterator;
			typedef typename tree_type::const_iterator const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			class value_compare : public std::binary_function<value_type,value_type,bool> {
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
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
			map(const allocator_type &alloc = allocator_type()):key_compare_(Compare()), alloc_(alloc) {}

			// empty constructor
			explicit map( const Compare& comp, const Allocator& alloc = Allocator() ): key_compare_(comp) ,alloc_(alloc) {}

			// range constructor
			template<class InputIt>
			map(
				InputIt first,
				InputIt last,
				const Compare& comp = Compare(),
				const Allocator& alloc = Allocator()
				): key_compare_(comp), alloc_(alloc){
					this->insert(first, last);
			}

			// copy constructor
			map(const map &rhs)
					: tree_(), key_compare_(rhs.key_compare_), alloc_(rhs.alloc_) {
					this->insert(rhs.begin(), rhs.end());
			}

			// destructor
			~map() {}

			// copy operator
			map& operator=( const map& rhs ) {
					if (rhs == this)
						return *this;
					this->clear();
					this->insert(rhs.begin(), rhs.end());
					return *this;
			}

			allocator_type get_allocator() const { return alloc_; }

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
			bool empty() const { return tree_.size() == 0; }
			size_type size() const { return tree_.size(); }
			size_type max_size() const { return tree_.max_size(); }

			/*----------------------------------------
			[Element access]
			----------------------------------------*/
			mapped_type& operator[] (const key_type& k) {
				node_type *node = tree_.search(k);
				if (node == tree_.getNullNode()) {
					tree_.insert(ft::make_pair<key_type, mapped_type>(k, mapped_type()));
					node = tree_.search(k);
				}
				return node->val_.second;
			}

			/*----------------------------------------
			[Modifiers]
			----------------------------------------*/
			/** @brief Inserts value */
			pair<iterator,bool> insert (const value_type& val) { return tree_.insert(val); }

			/** @brief Inserts value in the position as close as possible to the position just prior to pos */
			iterator insert (iterator pos, const value_type& val) {
				(void)pos;
				return this->insert(val).first;
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				for (; first != last; first++)
					this->insert(*first);
			}

			void erase (iterator pos) {
				const key_type &key = pos->first;
				this->erase(key);
			}

			size_type erase (const key_type& key) {
				return tree_.erase(key);
			}

			void erase (iterator first, iterator last) {
				tree_.erase(first, last);
			}

			void clear() { this->erase(this->begin(), this->end()); }

			void swap (map& x) { tree_.swap(x.tree_); }

			/*----------------------------------------
			[Look up]
			----------------------------------------*/
			/**  @brief Returns the number of elements with key that compares equivalent to the specified argument */
			size_type count(const Key &key) const { return tree_.search(key) != tree_.getNullNode(); }

			iterator find(const Key &key) { return tree_.find(key); }
			const_iterator find(const Key &key) const { return tree_.const_find(key); }

			/** @brief Returns a range containing all elements with the given key in the container */
			ft::pair<iterator,iterator> equal_range( const Key& key ) {
				return ft::make_pair<iterator, iterator>(this->lower_bound(key), this->upper_bound(key));
			}

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
				return ft::make_pair<const_iterator, const_iterator>(this->lower_bound(key), this->upper_bound(key));
			}

			iterator lower_bound( const Key& key ) {
				iterator begin = this->begin();
				iterator end = this->end();
				for (; begin != end; begin++) {
					if (equal_to()(key, begin->first) || key_compare_(key, begin->first))
						return begin;
				}
				return this->end();
			}

			const_iterator lower_bound( const Key& key ) const {
				const_iterator begin = this->begin();
				const_iterator end = this->end();
				for (; begin != end; begin++) {
					if (equal_to()(key, begin->first) || key_compare_(key, begin->first))
						return begin;
				}
				return this->end();
			}

			iterator upper_bound( const Key& key ) {
				iterator begin = this->begin();
				iterator end = this->end();
				for (; begin != end; begin++) {
					if (key_compare_(key, begin->first))
						return begin;
				}
				return this->end();
			}

			const_iterator upper_bound( const Key& key ) const {
				const_iterator begin = this->begin();
				const_iterator end = this->end();
				for (; begin != end; begin++) {
					if (key_compare_(key, begin->first))
						return begin;
				}
				return this->end();
			}

			value_compare value_comp() const { return value_compare(key_compare_); }
			key_compare key_comp() const { return key_compare_; }

	private:
		tree_type tree_;
		key_compare key_compare_;
		allocator_type alloc_;

	};
	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal<iterator, iterator>(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) { return !(lhs == rhs); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) { return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) { return !(lhs < rhs); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) { return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) { return !(lhs > rhs); }
}

#endif
