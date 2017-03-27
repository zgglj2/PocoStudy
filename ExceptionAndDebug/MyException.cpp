//
// Created by glj on 2017/3/27.
//
#include "MyException.h"
#include <typeinfo>

POCO_IMPLEMENT_EXCEPTION(MyException, Poco::Exception, "My Exception")
