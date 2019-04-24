/*
 * Author: Chengx
 * Date: 2019-4-4
 * Description: hbase功能测试程序
*/

#include "hbaseHandler.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	if(argc < 3)
	{
		printf("usage: main ip port\n");
		return 0;
	}
	const char *host = argv[1];
	int port = atoi(argv[2]);
	
	CHbaseHandler handler;
	handler.connect(host, port);
	
	string tableName("tableMsgInfo");
	string resultStr;
	
	cout << "-----------------test gets------------------" << endl;
	cout << "test getRow: 'tableMsgInfo', 'msgid_11111'" << endl;
	handler.getRow(tableName, "msgid_11111", resultStr);
	cout << resultStr << endl;
	
	cout << "test getRow: 'tableMsgInfo', 'msgid_test'" << endl;
	handler.getRow(tableName, "msgid_test", resultStr);
	cout << resultStr << endl;
	
	cout << "test getRows 'tableMsgInfo', 'msgid_11111', 'msgid_test'" << endl;
	vector<string> rows{"msgid_11111", "msgid_test"};
	handler.getRows(tableName, rows, resultStr);
	cout << resultStr << endl;
	
	cout << "test getAllRows: " << tableName << endl;
	handler.getAllRows(tableName, resultStr);
	cout << resultStr << endl;
	
	cout << "-----------------test puts------------------" << endl;
	cout << "test putRow: tableMsgInfo MsgInfo:msg_id msg_main_code" << endl;
	handler.putRow(tableName, "msgid_code", "MsgInfo", "msg_id", "msg_main_code");
	cout << "getAllRows..." << endl;
	handler.getAllRows(tableName, resultStr);
	cout << resultStr << endl;
	
	cout << "-----------------test delete------------------" << endl;
	cout << "test delete: tableMsgInfo MsgInfo:msg_id msg_main_code" << endl;
	handler.delRow(tableName, "msgid_code");
	cout << "getAllRows..." << endl;
	handler.getAllRows(tableName, resultStr);
	cout << resultStr << endl;
	
	cout << "end test..." << endl;
	return 0;	
}