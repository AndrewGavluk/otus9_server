#include <cstdlib>

#include <boost/asio.hpp>

#include "asyncLib.h"

using namespace boost::asio;


class ClientSession : public std::enable_shared_from_this<ClientSession> {
    public:
        explicit ClientSession(size_t bulk_size, ip::tcp::socket sock);
        ~ClientSession() = default;
        void start();
    
    private:
        void handle_read();

        static constexpr size_t buf_len = 1024;
        assyncLib                   m_assync;
        std::array<char, buf_len>   m_buf;
        ip::tcp::socket             m_sock;
        uint64_t                    m_handle{};
        std::shared_ptr<ClientSession>     m_self;
        size_t                      m_bulk_size;
        
};