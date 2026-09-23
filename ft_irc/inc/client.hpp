#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <iostream>

class Client
{
	private:
		int						_fd;
		std::string				_nickname;
		std::string				_username;
		std::string				_read_buffer;
		std::string				_write_buffer;
		bool					_registered;
		bool					_pass;
		bool					_hasNickname;
		bool					_hasUsername;
		static const size_t		MAX_BUFFER_SIZE = 8192;
		static const size_t		MAX_IRC_LINE_SIZE = 512;
	
	public:
		Client();
		Client(int fd);
		~Client();
	
		int							getFd() const;
		const std::string			&getNickname() const;
		const std::string			&getUsername() const;
		bool						isRegistered() const;
		void						setNickname(std::string const &nickname);
		void						setUsername(std::string const &username);
		void						setRegistered(bool value);
		void						setPassed(bool value);
		bool						get_Passed();
		void						set_hasNickname(bool value);
		bool						get_hasNickname();
		void						set_hasUsername(bool value);
		bool						get_hasUsername();
		bool						appendToReadBuffer(char const *data, int len);
		bool						hasCompleteLine() const;
		bool						hasLineTooLong() const;
		std::string					extractLine();
		void						appendToWriteBuffer(std::string const &data);
		const std::string			&getWriteBuffer() const;
		void						eraseWriteBuffer(size_t n);
		bool						hasDataToWrite() const;
};

#endif
