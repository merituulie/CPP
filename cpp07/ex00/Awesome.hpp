
#pragma once

#include <iostream>

class Awesome
{
	public:
		Awesome(void): _n(0) {}
		Awesome(int n): _n(n) {}

		Awesome& operator=(Awesome& a) { _n = a._n; return *this; }

		bool operator==(Awesome const& rhs) const { return (this->_n == rhs._n); }
		bool operator!=(Awesome const& rhs) const { return (this->_n != rhs._n); }
		bool operator>(Awesome const& rhs) const { return (this->_n > rhs._n); }
		bool operator<(Awesome const& rhs) const { return (this->_n < rhs._n); }
		bool operator>=(Awesome const& rhs) const { return (this->_n >= rhs._n); }
		bool operator<=(Awesome const& rhs) const { return (this->_n <= rhs._n); }

		int get_n() const { return _n; }
	private:
		int _n;
};

std::ostream& operator<<(std::ostream& out, const Awesome& a) { out << a.get_n(); return out; }
