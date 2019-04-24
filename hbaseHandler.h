/*
 * Author: Chengx
 * Date: 2019-4-2
 * Description: hbase操作类的头文件
*/

#ifndef _HBASE_HANDLER_H_
#define _HBASE_HANDLER_H_
#include "THBaseService.h" 
#include <string>
#include <vector> 
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <thrift/config.h> 
#include <thrift/transport/TSocket.h> 
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h> 
#include <glog/logging.h>
#include <boost/lexical_cast.hpp>

const char* const hbaseHost = "127.0.0.1";	//hbase服务器地址
const int hbasePort = 9090;			//hbase端口号
const char* const tableName = "tableMsgInfo";

class CHbaseHandler : boost::noncopyable
{
public:
	CHbaseHandler();
	~CHbaseHandler();
	
private:
	boost::shared_ptr<apache::thrift::transport::TSocket> socket;
	boost::shared_ptr<apache::thrift::transport::TTransport> transport;
	boost::shared_ptr<apache::thrift::protocol::TProtocol> protocol;
	
	//boost::shared_ptr<apache::hadoop::hbase::thrift2::THBaseServiceClient> client;
	
	std::string  hbaseServiceHost;
	int     hbaseServicePort;
	bool    isConnected;
	
public:
	bool connect();
	bool connect(const std::string &host, int port);	
	bool disconnect();
	bool putRow(const std::string &tableName,
				const std::string &rowKey,
				const std::string &family,
				const std::string &qualifier,
				const std::string &rowValue
				);
	bool getRow(const std::string &tableName,
				const std::string &rowKey,
				std::string &resultStr
				);
	bool getRows(const std::string &tableName,
				const std::vector<std::string> &rowKeyVec,
				std::string &resultStr
				);
	bool getRowsByTime(const std::string &tableName, int64_t startTimestamp, int64_t endTimestamp, std::string &resultStr);
	bool getAllRows(const std::string &tableName, std::string &resultStr);	
	bool getSeqValue(const std::string &tableName, const std::string &rowKey, std::string &columnValue);
	bool delRow(const std::string &tableName, const std::string &rowKey);
	bool delRows(const std::string &tableName, const std::vector<std::string> &rowKeyVec);
};

#endif