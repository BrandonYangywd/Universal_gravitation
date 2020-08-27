#include "multi_thread.h"
#include "gtest/gtest.h"
TEST(test, hello){
	std::thread t(hello);
	t.join();
}
