#pragma once

#define STD        ::std::
#define LOG	       ::my::singleton<my::clog>::get().object

#define Fu(item)					\
	{								\
		int _[] = { (item,0)... };	\
	}								\

#define Call(func,...) (::my::F_<func , __VA_ARGS__>)

namespace stdr = ::std::ranges;
namespace stdv = ::std::views;
namespace stdf = ::std::filesystem;
namespace stdl = ::std::literals;
namespace stdc = ::std::chrono;
namespace stdp = ::std::pmr;
namespace stde = ::std::experimental;
namespace my = ::mylib;
namespace mylibf = ::mylib::file;

using namespace my::literals;
using namespace std::literals;