#include<boost/beast.hpp>
#include<boost/asio/connect.hpp>
#include<boost/asio/ip/tcp.hpp>
#include<string>

const static std::string site = "www.cbr-xml-daily.ru";
const static std::string Json = "/daily_json.js";

namespace http = boost::beast::http;

class Client
{
	public:
	static std::string Get_response(std::string ip)
	{
		boost::asio::io_context io;
		boost::asio::ip::tcp::resolver resolver(io);
		boost::asio::ip::tcp::socket socket(io);


		boost::asio::connect(socket, resolver.resolve(site, "80"));

		std::string argument = Json + ip;
		http::request<http::string_body> req(http::verb::get, argument, 11);

		req.set(http::field::host, site);
		req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		http::write(socket, req);

		std::string response;
		{
			boost::beast::flat_buffer buffer;
			http::response<http::dynamic_body> res;
			http::read(socket, buffer, res);
			response = boost::beast::buffers_to_string(res.body().data());
		}
		socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
		return response;
	}
};