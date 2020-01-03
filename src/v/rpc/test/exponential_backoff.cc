#define BOOST_TEST_MODULE bytes
#include "rpc/reconnect_transport.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_exponential_backoff) {
    uint32_t bo = 0;
    for (auto i = 0; i < 32; ++i) {
        bo = rpc::reconnect_transport::next_backoff(bo);
        BOOST_CHECK(bo >= 1 && bo <= 300);
    }
}