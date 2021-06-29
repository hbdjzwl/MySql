// Copyright (C) RenZhai.2020.All Rights Reserved.
#include "SimpleMySQLibrary.h"
#include "MySQL/mysql.h"
#include "Core/SimpleMysqlLink.h"
#include "Blueprint/SimpleMysqlObject.h"

//---------------------------------------------------���Ӳ��� ��ѯ
// void USimpleMySQLLibrary::MySqlMain()
// {
// 	const char* user = "root";		//�û�
// 	const char* host = "127.0.0.1";	//localhoust
// 	const char* pawd = "root";		//����
// 	const char* table = "hello";	//���ݿ�db
// 	const char* db = "Mysql";		//���ݿ�����
// 	const uint32 port = 3306;		//�˿�
// 
// 	MYSQL mysql;
// 	MYSQL_RES* result = NULL;		//��ѯ���
// 
// 	int32 result_int = INDEX_NONE;	//���ؽ���ɹ�ʧ��
// 
// 	mysql_init(&mysql);
// 	if (mysql_real_connect(&mysql, host, user, pawd, table/*db*/, port, 0, 0))	//�������ݿ�
// 	{
// 		//SELECT * FROM ��
// 		if ((result_int = mysql_query(&mysql,"SELECT * FROM W"/*���*/)) == 0)
// 		{
// 				//�洢�����ش���Ĭ�ϴ�С64MB;
// 			if ((result = mysql_store_result(&mysql)) != NULL)
// 			{;
// 				while(MYSQL_ROW sql_row = mysql_fetch_row(result))//��ĳ�ַ�ʽ������
// 				{
// 					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,*FString::Printf(TEXT("name:%s"), ANSI_TO_TCHAR(sql_row[0])));
// 					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("age:%s"), ANSI_TO_TCHAR(sql_row[1])));
// 					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("size:%s"), ANSI_TO_TCHAR(sql_row[2])));
// 					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("height:%s"), ANSI_TO_TCHAR(sql_row[3])));
// 				}
// 			}
// 		}
// 		else
// 		{
// 			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "query sql failed!");
// 			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
// 		}
// 	}
// 	else
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "query sql failed!");
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
// 	}
// 
// 	if(result != NULL)
// 	{
// 		mysql_free_result(result);
// 	}
// 
// 	mysql_close(&mysql);
// }

//--------------------------------------------------------
// void USimpleMySQLLibrary::MySqlMain()
// {
// 	const char* user = "root";		//�û�
// 	const char* host = "127.0.0.1";	//localhoust
// 	const char* pawd = "root";		//����
// 	const char* table = "hello";	//���ݿ�db
// 	const char* db = "Mysql";		//���ݿ�����
// 	const uint32 port = 3306;		//�˿�
// 
// 	MYSQL mysql;
// 
// 	mysql_library_init(NULL, NULL, NULL);	//��֤�̰߳�ȫ����Ӧmysql_library_end
// 	mysql_init(&mysql);	//�����ڴ�(���ǣ�����߳̿��ܻ�����ڴ�й¶������mysql_library_init�����̰߳�ȫ)
// 	
// 
// 	mysql_close(&mysql);
// 	mysql_library_end();	//��Ӧmysql_library_init
// }

//--------------------------------------------------------------------����
//void USimpleMySQLLibrary::MySqlMain()
//{
//	const char *user = "root";
//	const char *host = "127.0.0.1";//localhost
//	const char *pawd = "root";
//	const char *table = "hello";
//	const uint32 port = 3306;
//
//	MYSQL mysql;
//	mysql_library_init(NULL, NULL, NULL);//��֤�̰߳�ȫ
//	mysql_init(&mysql);//�����ڴ�
//
//	/*CLIENT_COMPRESS 
//	CLIENT_FOUND_ROWS
//	CLIENT_IGNORE_SPACE
//	CLIENT_INTERACTIVE
//	CLIENT_LOCAL_FILES
//	CLIENT_MULTI_STATEMENTS
//	CLIENT_MULTI_RESULTS  
//	CLIENT_NO_SCHEMA db_name.tbl_name.col_name ODBC
//	CLIENT_ODBC  
//	CLIENT_SSL*/ //openSSL
//	if (mysql_real_connect(&mysql, host, user, pawd, table, port, 0, 0))//����
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "connect success !");
//	}
//	else
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "connect failed!");
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
//	}
//	
//	int ret = mysql_ping(&mysql);
//	if (ret == 0)
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "mysql_ping success!");
//	}
//	else
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "mysql_ping failed!");
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
//	}
//
//
//	mysql_close(&mysql);
//	mysql_library_end();
//}

//-----------------------------------------------------------------------------------------

// void USimpleMySQLLibrary::MySqlMain()
// {
// 	const char *user = "root";
// 	const char *host = "127.0.0.1";//localhost
// 	const char *pawd = "root";
// 	const char *table = "hello";
// 	const uint32 port = 3306;
// 
// 	MYSQL mysql;
// 	mysql_library_init(NULL, NULL, NULL);//��֤�̰߳�ȫ
// 	mysql_init(&mysql);//�����ڴ�
// 
// 	int time = 4;
// 	//MYSQL_OPT_RECONNECT ��������
// 	//MYSQL_OPT_CONNECT_TIMEOUT ��ʱ��ʱ�� �� ��
// 	int ret = mysql_options(&mysql, MYSQL_OPT_RECONNECT,&time);
// 
// 	if (mysql_real_connect(&mysql, host, user, pawd, table, port, 0, 0))//����
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "connect success !");
// 	}
// 	else
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "connect failed!");
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
// 	}
// 
// 	 ret = mysql_ping(&mysql);
// 	if (ret == 0)
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "mysql_ping success!");
// 	}
// 	else
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "mysql_ping failed!");
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
// 	}
// 
// 	mysql_close(&mysql);
// 	mysql_library_end();
// 
// }

//---------------------------------------------Mysql��ѯ---------------------------------------------------

//
// void USimpleMySQLLibrary::MySqlMain()
// {
// 	const char *user = "root";
// 	const char *host = "127.0.0.1";//localhost
// 	const char *pawd = "root";
// 	const char *table = "hello";
// 	const uint32 port = 3306;
// 
// 	MYSQL mysql;
// 	mysql_library_init(NULL, NULL, NULL);//��֤�̰߳�ȫ
// 	mysql_init(&mysql);//�����ڴ�
// 
// 	my_bool reconnect = 1;
// 	int ret = mysql_options(&mysql, MYSQL_OPT_RECONNECT, &reconnect);
// 	int BufSize = 1024 * 1024 * 64 ;//1MB
// 	//MYSQL_OPT_MAX_ALLOWED_PACKET 64MB
// 	ret = mysql_options(&mysql, MYSQL_OPT_MAX_ALLOWED_PACKET, &BufSize);
// 
// 	char select[] = "SELECT name FROM W";
// 	if (mysql_real_connect(&mysql, host, user, pawd, table, port, 0, 0))//����
// 	{
// 		//mysql_real_query(&mysql, select, strlen(select));
// 		if ((ret = mysql_query(&mysql, select)) == 0)
// 		{
// 			if (MYSQL_RES *result = mysql_store_result(&mysql))
// 			{
// 				while (MYSQL_ROW sql_row = mysql_fetch_row(result))
// 				{
// 					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("name [%s]"), ANSI_TO_TCHAR(sql_row[0])));
// 				}
// 			}
// 		}
// 	}
// 	else
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "connect failed!");
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
// 	}
// 
// 	ret = mysql_ping(&mysql);
// 	if (ret == 0)
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "mysql_ping success!");
// 	}
// 	else
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "mysql_ping failed!");
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
// 	}
// 
// 	mysql_close(&mysql);
// 	mysql_library_end();
// }

//---------------------------------------�Բ�ѯ������з�������ȡ���߱��ػ����ȡ-------------------

//void USimpleMySQLLibrary::MySqlMain()
//{
//	const char *user = "root";
//	const char *host = "127.0.0.1";//localhost
//	const char *pawd = "root";
//	const char *table = "hello";
//	const uint32 port = 3306;
//
//	MYSQL mysql;
//	mysql_library_init(NULL, NULL, NULL);//��֤�̰߳�ȫ
//	mysql_init(&mysql);//�����ڴ�
//
//	my_bool reconnect = 1;
//	int ret = mysql_options(&mysql, MYSQL_OPT_RECONNECT, &reconnect);
//	int BufSize = 1024 * 1024 * 64;//1MB
//	//MYSQL_OPT_MAX_ALLOWED_PACKET 64MB
//	ret = mysql_options(&mysql, MYSQL_OPT_MAX_ALLOWED_PACKET, &BufSize);
//
//	char select[] = "SELECT name FROM W";
//	if (mysql_real_connect(&mysql, host, user, pawd, table, port, 0, 0))//����
//	{
//		//mysql_real_query(&mysql, select, strlen(select));
//		if ((ret = mysql_query(&mysql, select)) == 0)
//		{
//			//mysql_use_result();		//ͨ��������ȥ��ѯȻ�󷵻ؽ�������˷ѷ�������Դ
//			//mysql_store_result();		//����ѯ�������������浽���ػ�������ȥ���� 
//			if (MYSQL_RES *result = mysql_use_result(&mysql))	
//			{
//				while (MYSQL_ROW sql_row = mysql_fetch_row(result))
//				{
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("name [%s]"), ANSI_TO_TCHAR(sql_row[0])));
//				}
//			}
//		}
//	}
//	else
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "connect failed!");
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
//	}
//
//	ret = mysql_ping(&mysql);
//	if (ret == 0)
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "mysql_ping success!");
//	}
//	else
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "mysql_ping failed!");
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
//	}
//
//	mysql_close(&mysql);
//	mysql_library_end();
//}

//------------------------------------------------------------------------------------------------
// void USimpleMySQLLibrary::MySqlMain()
// {
// 	const char *user = "root";
// 	const char *host = "127.0.0.1";//localhost
// 	const char *pawd = "root";
// 	const char *table = "hello";
// 	const uint32 port = 3306;
// 
// 	MYSQL mysql;
// 	mysql_library_init(NULL, NULL, NULL);//��֤�̰߳�ȫ
// 	mysql_init(&mysql);//�����ڴ�
// 
// 	my_bool reconnect = 1;
// 	int ret = mysql_options(&mysql, MYSQL_OPT_RECONNECT, &reconnect);
// 	int BufSize = 1024 * 1024 * 64;//1MB
// 	//MYSQL_OPT_MAX_ALLOWED_PACKET 64MB
// 	ret = mysql_options(&mysql, MYSQL_OPT_MAX_ALLOWED_PACKET, &BufSize);
// 
// 	char select[] = "SELECT * FROM W";
// 	if (mysql_real_connect(&mysql, host, user, pawd, table, port, 0, 0))//����
// 	{
// 		
// 		if ((ret = mysql_query(&mysql, select)) == 0)
// 		{
// 			//mysql_field_count(mysql)	//���ӳɹ���connect:��ȡ�ֶε�������"SELECT * FROM W"  *���м����ֶ�
// 			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("fields num: %u"), mysql_field_count(mysql)));
// 
// 			mysql_errno(&mysql);
// 			{
// 				//  1005 : ������ʧ��
// 				//	1006 : �������ݿ�ʧ��
// 				//	1007 : ���ݿ��Ѵ��ڣ��������ݿ�ʧ��
// 				//	1008 : ���ݿⲻ���ڣ�ɾ�����ݿ�ʧ��
// 				//	1009 : ����ɾ�����ݿ��ļ�����ɾ�����ݿ�ʧ��
// 				//	1010 : ����ɾ������Ŀ¼����ɾ�����ݿ�ʧ��
// 				//	1011 : ɾ�����ݿ��ļ�ʧ��
// 				//	1012 : ���ܶ�ȡϵͳ���еļ�¼
// 				//	1016 : �޷����ļ�
// 				//	1020 : ��¼�ѱ������û��޸�
// 				//	1021 : Ӳ��ʣ��ռ䲻�㣬��Ӵ�Ӳ�̿��ÿռ�
// 				//	1022 : �ؼ����ظ������ļ�¼ʧ��
// 				//	1023 : �ر�ʱ��������
// 				//	1024 : ���ļ�����
// 				//	1025 : ��������ʱ��������
// 				//	1026 : д�ļ�����
// 				//	1032 : ��¼������
// 				//	1036 : ���ݱ���ֻ���ģ����ܶ��������޸�
// 				//	1037 : ϵͳ�ڴ治�㣬���������ݿ������������
// 				//	1038 : ����������ڴ治�㣬���������򻺳���
// 				//	1040 : �ѵ������ݿ���������������Ӵ����ݿ����������
// 				//	1041 : ϵͳ�ڴ治��
// 				//	1042 : ��Ч��������
// 				//	1043 : ��Ч����
// 				//	1044 : ��ǰ�û�û�з������ݿ��Ȩ��
// 				//	1045 : �����������ݿ⣬�û������������
// 				//	1040 : ���������
// 				//	1048 : �ֶβ���Ϊ��
// 				//	1049 : ���ݿⲻ����
// 				//	1050 : ���ݱ��Ѵ���
// 				//	1051 : ���ݱ�����
// 				//	1054 : �ֶβ�����
// 				//	1065 : ��Ч��SQL��䣬SQL���Ϊ��
// 				//	1081 : ���ܽ���Socket����
// 				//	1114 : ���ݱ����������������κμ�¼
// 				//	1116 : �򿪵����ݱ�̫��
// 				//	1129 : ���ݿ�����쳣�����������ݿ�
// 				//	1130 : �������ݿ�ʧ�ܣ�û���������ݿ��Ȩ��
// 				//	1133 : ���ݿ��û�������
// 				//	1141 : ��ǰ�û���Ȩ�������ݿ�
// 				//	1142 : ��ǰ�û���Ȩ�������ݱ�
// 				//	1143 : ��ǰ�û���Ȩ�������ݱ��е��ֶ�
// 				//	1146 : ���ݱ�����
// 				//	1147 : δ�����û������ݱ�ķ���Ȩ��
// 				//	1149 : SQL����﷨����
// 				//	1158 : ������󣬳��ֶ�����������������״��
// 				//	1159 : ������󣬶���ʱ��������������״��
// 				//	1160 : ������󣬳���д����������������״��
// 				//	1161 : �������д��ʱ��������������״��
// 				//	1062 : �ֶ�ֵ�ظ������ʧ��
// 			}
// 			if (MYSQL_RES *result = mysql_use_result(&mysql))	
// 			{
// 				//mysql_num_fields(result)	//��ȡ������ɹ���:��ȡ�ֶε�������"SELECT * FROM W"  *���м����ֶ�
// 				GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("fields num: %u"),mysql_num_fields(result)));
// 
// 				while (MYSQL_ROW sql_row = mysql_fetch_row(result))
// 				{
// 					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("name [%s]"), ANSI_TO_TCHAR(sql_row[0])));
// 				}
// 			}
// 		}
// 	}
// 	else
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "connect failed!");
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
// 	}
// 
// 	ret = mysql_ping(&mysql);
// 	if (ret == 0)
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "mysql_ping success!");
// 	}
// 	else
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "mysql_ping failed!");
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
// 	}
// 
// 	mysql_close(&mysql);
// 	mysql_library_end();
// }

//------------------------------------mysql_fetch_lengths ��ȡ�ֶ���Ϣ�ĳ���--------------------------------------- 

//void USimpleMySQLLibrary::MySqlMain()
//{
//	const char *user = "root";
//	const char *host = "127.0.0.1";//localhost
//	const char *pawd = "root";
//	const char *table = "hello";
//	const uint32 port = 3306;
//
//	MYSQL mysql;
//	mysql_library_init(NULL, NULL, NULL);//��֤�̰߳�ȫ
//	mysql_init(&mysql);//�����ڴ�
//
//	my_bool reconnect = 1;
//	int ret = mysql_options(&mysql, MYSQL_OPT_RECONNECT, &reconnect);
//	int BufSize = 1024 * 1024 * 64;//1MB
//	//MYSQL_OPT_MAX_ALLOWED_PACKET 64MB
//	ret = mysql_options(&mysql, MYSQL_OPT_MAX_ALLOWED_PACKET, &BufSize);
//
//	char select[] = "SELECT name FROM W";
//	if (mysql_real_connect(&mysql, host, user, pawd, table, port, 0, 0))//����
//	{
//		if ((ret = mysql_query(&mysql, select)) == 0)
//		{
//			if (MYSQL_RES *result = mysql_use_result(&mysql))
//			{
//				while (MYSQL_ROW sql_row = mysql_fetch_row(result))
//				{
//					unsigned long *len = mysql_fetch_lengths(result);// \0 "renzhai" strlen()
//
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("name len [%i]"), *len));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("name [%s]"), ANSI_TO_TCHAR(sql_row[0])));
//				}
//			}
//		}
//	}
//	else
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "connect failed!");
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
//	}
//
//	mysql_close(&mysql);
//	mysql_library_end();
//}

//---------------------------------------------------------------------------------------------------------
// void USimpleMySQLLibrary::MySqlMain()
// {
// 	const char *user = "root";
// 	const char *host = "127.0.0.1";//localhost
// 	const char *pawd = "root";
// 	const char *table = "hello";
// 	const uint32 port = 3306;
// 
// 	MYSQL mysql;
// 	mysql_library_init(NULL, NULL, NULL);//��֤�̰߳�ȫ
// 	mysql_init(&mysql);//�����ڴ�
// 
// 	my_bool reconnect = 1;
// 	int ret = mysql_options(&mysql, MYSQL_OPT_RECONNECT, &reconnect);
// 	int BufSize = 1024 * 1024 * 64;//1MB
// 	//MYSQL_OPT_MAX_ALLOWED_PACKET 64MB
// 	ret = mysql_options(&mysql, MYSQL_OPT_MAX_ALLOWED_PACKET, &BufSize);
// 
// 	char select[] = "SELECT name FROM W";
// 	if (mysql_real_connect(&mysql, host, user, pawd, table, port, 0, 0))//����
// 	{
// 		if ((ret = mysql_query(&mysql, select)) == 0)
// 		{
// 			if (MYSQL_RES *result = mysql_use_result(&mysql))
// 			{
// 				int num_fields = mysql_num_fields(result);
// 				while (MYSQL_ROW sql_row = mysql_fetch_row(result))
// 				{
// 					for (int i = 0 ;i < num_fields; i++)
// 					{
// 						MYSQL_FIELD *find_sql = mysql_fetch_field_direct(result, i);
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("name [%s]"), find_sql->name));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("org_name [%s]"), find_sql->org_name));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("table [%s]"), find_sql->table));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("org_table [%s]"), find_sql->org_table));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("db [%s]"), find_sql->db));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("catalog [%s]"), find_sql->catalog));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("def [%s]]"), find_sql->def));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("length [%i]"), find_sql->length));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("max_length [%i]"), find_sql->max_length));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("name_length [%i]"), find_sql->name_length));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("org_name_length [%i]"), find_sql->org_name_length));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("db_length [%i]"), find_sql->db_length));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("catalog_length [%i]"), find_sql->catalog_length));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("flags [%i]"), find_sql->flags));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("def_length [%i]"), find_sql->def_length));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("decimals [%i]"), find_sql->decimals));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("charsetnr [%i]"), find_sql->charsetnr));
// 						GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("enum_field_types [%i]"), find_sql->type));
// 						//enum enum_field_types type; /* Type of field. See mysql_com.h for types */
// 						//void *extension;
// 					}
// 					
// 					unsigned long *len = mysql_fetch_lengths(result);// \0 "renzhai" strlen()
// 
// 					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("name len [%i]"), *len));
// 					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("name [%s]"), ANSI_TO_TCHAR(sql_row[0])));
// 				}
// 			}
// 		}
// 	}
// 	else
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "connect failed!");
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
// 	}
// 
// 	mysql_close(&mysql);
// 	mysql_library_end();
// }

//------------------------------------������һ��---------------------------------------------------------------
//
//void USimpleMySQLLibrary::MySqlMain()
//{
//	const char *user = "root";
//	const char *host = "127.0.0.1";//localhost
//	const char *pawd = "root";
//	const char *table = "hello";
//	const uint32 port = 3306;
//
//	MYSQL mysql;
//	mysql_library_init(NULL, NULL, NULL);//��֤�̰߳�ȫ
//	mysql_init(&mysql);//�����ڴ�
//
//	my_bool reconnect = 1;
//	int ret = mysql_options(&mysql, MYSQL_OPT_RECONNECT, &reconnect);
//	int BufSize = 1024 * 1024 * 64;//1MB
//	//MYSQL_OPT_MAX_ALLOWED_PACKET 64MB
//	ret = mysql_options(&mysql, MYSQL_OPT_MAX_ALLOWED_PACKET, &BufSize);
//
//	char select[] = "SELECT * FROM W";
//	if (mysql_real_connect(&mysql, host, user, pawd, table, port, 0, 0))//����
//	{
//		if ((ret = mysql_query(&mysql, select)) == 0)
//		{
//			if (MYSQL_RES *result = mysql_use_result(&mysql))
//			{
//				int num_fields = mysql_num_fields(result);
//				MYSQL_FIELD *find_sql_org = mysql_fetch_field(result);
//				for (int i = 0; i < num_fields; i++)
//				{
//					MYSQL_FIELD *find_sql = &find_sql_org[i];
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("name [%s]"), find_sql->name));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("org_name [%s]"), find_sql->org_name));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("table [%s]"), find_sql->table));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("org_table [%s]"), find_sql->org_table));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("db [%s]"), find_sql->db));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("catalog [%s]"), find_sql->catalog));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("def [%s]]"), find_sql->def));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("length [%i]"), find_sql->length));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("max_length [%i]"), find_sql->max_length));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("name_length [%i]"), find_sql->name_length));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("org_name_length [%i]"), find_sql->org_name_length));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("db_length [%i]"), find_sql->db_length));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("catalog_length [%i]"), find_sql->catalog_length));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("flags [%i]"), find_sql->flags));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("def_length [%i]"), find_sql->def_length));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("decimals [%i]"), find_sql->decimals));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("charsetnr [%i]"), find_sql->charsetnr));
//					GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, *FString::Printf(TEXT("enum_field_types [%i]"), find_sql->type));
//					//enum enum_field_types type; /* Type of field. See mysql_com.h for types */
//					//void *extension;
//				}
//			}		
//		}
//	}
//	else
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "connect failed!");
//		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
//	}
//
//	mysql_close(&mysql);
//	mysql_library_end();
//}
//
//------------------------------------Ԥ����---------------------------------------------------------------
// 
// // void USimpleMySQLLibrary::MySqlMain()
// {
// 	//Text
// 	/*
// 		char  255  char �̶���С
// 		varchar 255 -> text �ɱ䳤��(��ʼ������255)
// 		text  65,535     255ƽ�� �ɱ䳤��(��ʼ�������ֽڴ�С)
// 		tinytext 255  �ɱ䳤��(��ʼ�������ֽڴ�С)
// 		blob     65,535(�����ƴ洢���󣬳�ʼ��65535������ͼƬ��)
// 		mediumtext 16,777,215 ���ַ����ַ�����64�Ĵη�(text��ͬ) 1M+
// 		mediumblob 16,777,215 ������
// 		longtext	4,294,967,295 ���ַ�
// 		longblob	4,294,967,295 ���ַ�
// 		ENUM(x,y,z,etc.)  65535  ���Ϊ""Ĭ��Ϊ0������0λ  ö��ȡ����ֵ
// 		SET() ����ȡ����ֵ�ļ��ϣ���������64����ͬ�Ķ���
// 	*/
// 	//Number
// 	/*	
// 		int(size)  4�ֽ�: -2147483648��2147483647  0��4294967295+ size= 11
// 		bigint(size) -9223372036854775808 �� 9223372036854775807 0��18446744073709551615 size= 20
// 		tinyint(size) -128��127 0��255 size = 4
// 		smallint(size) -32768��32767 �޷���0��65535 size = 6
// 		mediumint(size) -8388608��8388607 �޷��ŵķ�Χ��0��16777215  size = 9
// 		float(size,d)   ��С��С�������λ
// 		double(size,d)
// 		decimal(size,d) ��Ϊ�ַ����洢�� double ����  �����ʮ����
// 	*/
// 	//Date/time
// 	/*
// 		DATE() YYYY-MM-DD (1000-01-01 ~ 9999-12-31)  2020-6-27
// 		DATETIME() YYYY-MM-DD HH:MM:SS      (1000-01-01 00:00:00~ 9999-12-31 23:59:59�� 2020-6-27 09:30:01
// 		TIMESTAMP() 1970-01-01 00:00:01 - ���� �������洢
// 		TIME() HH:MM:SS -838:59:59 ~ 838:59:59
// 		YEAR() 
// 	*/
// 
// 	const char *user = "root";
// 	const char *host = "127.0.0.1";//localhost
// 	const char *pawd = "root";
// 	const char *table = "hello";
// 	const uint32 port = 3306;
// 
// 	MYSQL mysql;
// 	mysql_library_init(NULL, NULL, NULL);//��֤�̰߳�ȫ
// 	mysql_init(&mysql);//�����ڴ�
// 
// 	char select[] = "SELECT name FROM W";
// 	if (mysql_real_connect(&mysql, host, user, pawd, table, port, 0, 0))//����
// 	{
// 		//1.���ٷ���������
// 		//2.��߷�������Ӧ���ٶ�
// 		//3.�����ṩ�������ƣ��ÿͻ��и����ѯ����
// 
// 		//MYSQL_STMT
// 		//MYSQL_BIND
// 
// 		//MYSQL_STMT *mysql_stmt_init(MYSQL *mysql)     
// 		//mysql_stmt_close(MYSQL_STMT *)
// 
// 		//int mysql_stmt_prepare(MYSQL_STMT *stmt, const char *query, unsigned long length)
// 		//my_bool mysql_stmt_bind_param(MYSQL_STMT *stmt, MYSQL_BIND *bind) 
// 		//my_bool mysql_stmt_bind_result(MYSQL_STMT *stmt, MYSQL_BIND *bind) 
// 
// 		//int mysql_stmt_execute(MYSQL_STMT *stmt)
// 		//int mysql_stmt_store_result(MYSQL_STMT *stmt)  
// 		//int mysql_stmt_fetch(MYSQL_STMT *stmt) 
// 
// 		MYSQL_STMT *Ptr = mysql_stmt_init(&mysql);
// 
// 		char *SQL = "INSERT INTO ppp1 VALUES(?,?)";//��ֹע�빥��
// 		int ret = mysql_stmt_prepare(Ptr, SQL, FString(ANSI_TO_TCHAR(SQL)).Len());
// 		if (ret != 0)
// 		{
// 			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_stmt_error(Ptr));
// 			return;
// 		}
// 		int32 id = 100;
// 		MYSQL_BIND Pram[2];
// 		FMemory::Memset(Pram, 0, sizeof(Pram)); //�����ʼ����Ȼ�����
// 		Pram[0].buffer_type = MYSQL_TYPE_LONG;	//�ֶ�����
// 		Pram[0].buffer = &id;	//ֵ
// 		Pram[0].length = 0;	
// 
// 		char *content = "Hello";
// 		uint32 contentlen = strlen(content);
// 		Pram[1].buffer_type = MYSQL_TYPE_VARCHAR;
// 		//Pram[1].is_null = 0;	//��Ƶ˵Memset�Ϳ��п���
// 		Pram[1].buffer = content;
// 		Pram[1].length = (unsigned long*)&contentlen;
// 		Pram[1].buffer_length = contentlen;
// 		
// 		ret = mysql_stmt_bind_param(Ptr, Pram);
// 		if (ret != 0)
// 		{
// 			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_stmt_error(Ptr));
// 			return;
// 		}
// 
// 		ret = mysql_stmt_execute(Ptr);
// 		if (ret != 0)
// 		{
// 			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_stmt_error(Ptr));
// 			return;
// 		}
// 
// 		mysql_stmt_close(Ptr);
// 	}
// 	else
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "connect failed!");
// 		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
// 	}
// 
// 	mysql_close(&mysql);
// 	mysql_library_end();
// }


//------------------------------------�﷨---------------------------------------------------------------

void USimpleMySQLLibrary::MySqlMain()
{
	return;

	const char *user = "root";
	const char *host = "127.0.0.1";//localhost
	const char *pawd = "root";
	const char *table = "hello";
	const uint32 port = 3306;

	MYSQL mysql;
	mysql_library_init(NULL, NULL, NULL);//��֤�̰߳�ȫ
	mysql_init(&mysql);//�����ڴ�

	my_bool reconnect = 1;
	int ret = mysql_options(&mysql, MYSQL_OPT_RECONNECT, &reconnect);
	int BufSize = 1024 * 1024 * 64;//1MB
	//MYSQL_OPT_MAX_ALLOWED_PACKET 64MB
	ret = mysql_options(&mysql, MYSQL_OPT_MAX_ALLOWED_PACKET, &BufSize);
	//CREATE DATABASE ���ݿ��� //�������ݿ�
	//CREATE DATABASE IF NOT EXISTS renzhai DEFAULT CHARSET utf8 COLLATE utf8_general_ci;��������ݴ��ھͲ�������
	//DROP DATABASE ���ݿ��� //ɾ�����ݿ�
	//CREATE TABLE ���� (���� ������);
	//DROP TABLE ���� ����ȫ��ɾ�� �ͷ��ڴ� ��֧�ֻع� Innodb �� MyISAM ȫ�����
	//TRUNCATE TABLE ���� ����� �ͷ��ڴ� ��֧�ֻع� Innodb �� MyISAM ȫ�����
	//delete from ���� where ɾ������ Innodb �� MyISAM
	//optimise table ���� �����ͷ��ڴ�
	//use hello;delete from hp where name=\"xiaohei\";optimise table hp;
	//insert into ����(�ֶ�1���ֶ�2���ֶ�3���ֶ�4) values (1,2,3,4); ������� 
	//insert into ���� values(id,"name",'2020-09-06');
	//SELECT * FROM W LIMIT 2 ,4;  3-7
	//LIMIT 2 ,4 ;3-7
	//LIMIT 2;0,2
	//order by �ֶ���			��С����	 ����
	//order by �ֶ��� desc		�Ӵ�С  ����
	//where �ֶ� = xxx ����				������ѯ			
	//where �ֶ� between "1" and "123";	��Χ��ѯ
	//where �ֶ� like "";				ģ����ѯ
	//where �ֶ� in ("","");				ͨ���̶�������ѯ
	//where �ж� and �ж�;				��ѯ��������������
	//where �ж� or �ж�;	
	//left join ��  on  �ж�				�����
	//left join ��  on  �ж�				�ҹ���
	//Where �ж� 
	//Where A = B
	//Where A != B
	//Where A > B
	//Where A >= B
	//Where A <= B
	//Where �ж� and �ж� 
	//Where �ж� or �ж� 
	//group by 
	//update ���� set �ֶ�="asdasdqwe",�ֶ�="asdawd".... where 
	//update ���� set �ֶ�=replace(�ֶ�,'������','������') �ж�����
	//select * from w where name like ģ�����ֶ� ģ����ѯ
	//XXX% ǰ�����XXXȫ����ѯ����
	//%XXX ��׺��XXXȫ����ѯ����
	//XX%bb �м�������ʲô ֻҪ������XX bbȫ����ѯ����
	//_a //___zhai %zhai
	//_a_
	//a_
	//[]
	//[^]
	//group by
	//count()

	//inner join     on 
	//right join ��  on  �ж�	
	//left join ��  on  �ж�	

	// IS NULL
	// IS NOT NULL

	//��������4������
	//ԭ�Ӳ���
	//һ��
	//����
	//�־�
	//ENGINE=InnoDB
	//START TRANSACTION ����һ������
	//set autocommit = 0 //���Զ��ύ����Ϊ�ֶ�
	//SQL��� ��������
	//COMMIT �ύ
	//ROLLBACK �ع�
	//set autocommit = 1 ���û���
	//savepoint �洢������
	//release savepoint �洢������
	//rollback to �洢������
	//��
	//InnoDB �м������  ֧��
	//MyISAM ������ ��֧�ֻع�
	//alter 
	//alter table ���� engine=myisam;innodb
	//ALTER TABLE ���� DROP �ֶ�;
	//ALTER TABLE ���� ADD �ֶ� ����;
	//ALTER TABLE ���� modify �ֶ� ����(char(100));
	//ALTER TABLE ���� CHANGE �ֶ�1 �ֶ�2 ����;
	//ALTER TABLE ���� MODIFY �ֶ� BIGINT NOT NULL DEFAULT value;
	//ALTER TABLE ���� RENAME TO �±���;
	//ALTER TABLE ���� ALTER �ֶ� DROP DEFAULT;
	//ALTER TABLE ���� ADD INDEX ��������(�ֶ�(����));

	//create index �������� on ��(�ֶ�(����));
	//show index from ��;


	// create temporary table ���� (�ֶ� ���ͣ�...) ;
	// create temporary table ���� (�ֶ� ���ͣ�...) SELECT �ֶ�, �ֶ� FROM ���� where ����;
	// DROP TEMPORARY TABLE IF EXISTS ��;
	// insert into ��ʱ���� (�ֶ� ,�ֶΣ�... or *) SELECT �ֶ� ,�ֶΣ�... or * FROM Ҫ����ı�;
	// insert into �� (�ֶ� ,�ֶΣ�... or *) SELECT �ֶ� ,�ֶΣ�... or * FROM ��;   ���Ʊ�
	//memory�洢���� 
	//innodb�洢���� myisam�洢���� 

	//DROP TEMPORARY TABLE IF EXISTS hello_c; 
	//CREATE TABLE ���� LIKE ����1; //������ͬ��
	//INSERT INTO ���� SELECT * FROM ����1;
	//CREATE TABLE ���� AS (SELECT �ֶ�, �ֶ� FROM ����1);
	//CREATE TABLE ���� AS (SELECT �ֶ�, �ֶ� as �������� FROM ����1);
	//CREATE TABLE ����(�ֶ� INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY) AS (SELECT * FROM ����);
	//SELECT VERSION();
	//SELECT DATABASE();
	//SELECT USER();
	//SHOW STATUS;
	//primary key (�ֶ�1, �ֶ�2...) //�ֶβ���ΪNULL
	//UNIQUE  (�ֶ�1, �ֶ�2...)	//��֤Ψһ�� 
	//insert ignore into ���� (�ֶ�1, �ֶ�2... ) values( 'ֵ1', 'ֵ2' ...); //���ھ�����
	//replace into ���� (�ֶ�1, �ֶ�2... ) values( 'ֵ1', 'ֵ2' ...); //���� ���滻
	//SELECT COUNT(*) as ����, �ֶ�1, �ֶ�2 FROM ����  GROUP BY �ֶ�1, �ֶ�2 HAVING ����; ͳ���ظ�����
	//SELECT DISTINCT �ֶ�1, �ֶ�2 FROM ����; �����ظ�����1
	//SELECT �ֶ�1 FROM ���� GROUP BY(�ֶ�1);   �����ظ�����2

	char select[] = "SHOW STATUS ;";//
	if (mysql_real_connect(&mysql, host, user, pawd, table, port, 0, CLIENT_MULTI_STATEMENTS))//����
	{
		//char *sql = "begin;";//begin START TRANSACTION
		//if ((ret = mysql_query(&mysql, sql)) != 0)
		//{
		//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, ANSI_TO_TCHAR(mysql_error(&mysql)));
		//}
		if ((ret = mysql_query(&mysql, select)) == 0)
		{
			if (MYSQL_RES *result = mysql_store_result(&mysql))
			{
				int32 num_row = mysql_num_fields(result);
				while (MYSQL_ROW sql_row = mysql_fetch_row(result))
				{
					FString RowString;
					for (int i = 0; i < num_row; i++)
					{
						if (sql_row[i] != NULL)
						{
							int32 Len = FString(ANSI_TO_TCHAR(sql_row[i])).Len() / 2;
							int32 Add_Len = 10 - Len;//ʣ��ռ�� ����
							RowString += "|";
							for (int j = 0; j < Add_Len; j++)
							{
								RowString += " ";
							}

							RowString += ANSI_TO_TCHAR(sql_row[i]);

							for (int j = 0; j < Add_Len; j++)
							{
								RowString += " ";
							}
						}
						else
						{
							int32 Len = FString("NULL").Len() / 2;
							int32 Add_Len = 10 - Len;//ʣ��ռ�� ����
							RowString += "|";
							for (int j = 0; j < Add_Len; j++)
							{
								RowString += " ";
							}

							RowString += "NULL";

							for (int j = 0; j < Add_Len; j++)
							{
								RowString += " ";
							}
						}
					}

					RowString += "|";

					GEngine->AddOnScreenDebugMessage(-1, 1000, FColor::Red, *RowString);
				}
			}
		}

		//char *sql = "insert into cpy_table (id,date_table,number) SELECT id,table_date,number FROM hp;";
		//if ((ret = mysql_query(&mysql, sql)) != 0)
		//{
		//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, ANSI_TO_TCHAR(mysql_error(&mysql)));
		//}

		//sql = "SHOW CREATE TABLE cpy_table;";//ROLLBACK WORK
		//if ((ret = mysql_query(&mysql, sql)) == 0)
		//{
		//	if (MYSQL_RES *result = mysql_store_result(&mysql))
		//	{
		//		int32 num_row = mysql_num_fields(result);
		//		while (MYSQL_ROW sql_row = mysql_fetch_row(result))
		//		{
		//			FString RowString;
		//			for (int i = 0; i < num_row; i++)
		//			{
		//				if (sql_row[i] != NULL)
		//				{
		//					int32 Len = FString(ANSI_TO_TCHAR(sql_row[i])).Len() / 2;
		//					int32 Add_Len = 10 - Len;//ʣ��ռ�� ����
		//					RowString += "|";
		//					for (int j = 0; j < Add_Len; j++)
		//					{
		//						RowString += " ";
		//					}

		//					RowString += ANSI_TO_TCHAR(sql_row[i]);

		//					for (int j = 0; j < Add_Len; j++)
		//					{
		//						RowString += " ";
		//					}
		//				}
		//				else
		//				{
		//					int32 Len = FString("NULL").Len() / 2;
		//					int32 Add_Len = 10 - Len;//ʣ��ռ�� ����
		//					RowString += "|";
		//					for (int j = 0; j < Add_Len; j++)
		//					{
		//						RowString += " ";
		//					}

		//					RowString += "NULL";

		//					for (int j = 0; j < Add_Len; j++)
		//					{
		//						RowString += " ";
		//					}
		//				}
		//			}

		//			RowString += "|";

		//			GEngine->AddOnScreenDebugMessage(-1, 1000, FColor::Red, *RowString);
		//		}
		//	}
		//}
		//sql = "savepoint hello_v1;";//ROLLBACK WORK
		//if ((ret = mysql_query(&mysql, sql)) != 0)
		//{
		//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, ANSI_TO_TCHAR(mysql_error(&mysql)));
		//}

		//sql = "DROP TABLE hello_c;";
		//if ((ret = mysql_query(&mysql, sql)) != 0)
		//{
		//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, ANSI_TO_TCHAR(mysql_error(&mysql)));
		//}

		//sql = "insert into hp (name,table_date) values('hello333','2064-07-14');";
		//if ((ret = mysql_query(&mysql, sql)) == 0)
		//{
		//	if (MYSQL_RES *result = mysql_store_result(&mysql))
		//	{
		//		int32 num_row = mysql_num_fields(result);
		//		while (MYSQL_ROW sql_row = mysql_fetch_row(result))
		//		{
		//			FString RowString;
		//			for (int i = 0; i < num_row; i++)
		//			{
		//				if (sql_row[i] != NULL)
		//				{
		//					int32 Len = FString(ANSI_TO_TCHAR(sql_row[i])).Len() / 2;
		//					int32 Add_Len = 10 - Len;//ʣ��ռ�� ����
		//					RowString += "|";
		//					for (int j = 0; j < Add_Len; j++)
		//					{
		//						RowString += " ";
		//					}

		//					RowString += ANSI_TO_TCHAR(sql_row[i]);

		//					for (int j = 0; j < Add_Len; j++)
		//					{
		//						RowString += " ";
		//					}
		//				}
		//				else
		//				{
		//					int32 Len = FString("NULL").Len() / 2;
		//					int32 Add_Len = 10 - Len;//ʣ��ռ�� ����
		//					RowString += "|";
		//					for (int j = 0; j < Add_Len; j++)
		//					{
		//						RowString += " ";
		//					}

		//					RowString += "NULL";

		//					for (int j = 0; j < Add_Len; j++)
		//					{
		//						RowString += " ";
		//					}
		//				}
		//			}

		//			RowString += "|";

		//			GEngine->AddOnScreenDebugMessage(-1, 1000, FColor::Red, *RowString);
		//		}
		//	}
		//}

		//sql = "rollback to savepoint hello_v1;";//
		//if ((ret = mysql_query(&mysql, sql)) != 0)
		//{
		//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, ANSI_TO_TCHAR(mysql_error(&mysql)));
		//}

		//sql = "RELEASE SAVEPOINT hello_v1;";//
		//if ((ret = mysql_query(&mysql, sql)) != 0)
		//{
		//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, ANSI_TO_TCHAR(mysql_error(&mysql)));
		//}

		//sql = "COMMIT;";
		//if ((ret = mysql_query(&mysql, sql)) != 0)
		//{
		//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, ANSI_TO_TCHAR(mysql_error(&mysql)));
		//}

		//sql = "set autocommit = 1;";
		//if ((ret = mysql_query(&mysql, sql)) != 0)
		//{
		//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, ANSI_TO_TCHAR(mysql_error(&mysql)));
		//}

		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, ANSI_TO_TCHAR(mysql_error(&mysql)));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "connect failed!");
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, ANSI_TO_TCHAR(mysql_error(&mysql)));
	}

	mysql_close(&mysql);
	mysql_library_end();

	/*
	SYSTEM_USER()
	SESSION_USER()
	NULLIF(x,y) x=y return null; x
	LAST_INSERT_ID() ����������ɵ� AUTO_INCREMENT ֵ
	ISNULL (expression) �жϱ��ʽ�Ƿ�Ϊ NULL
	IF(expr,v1,v2) ������ʽ expr ���������ؽ�� v1�����򣬷��ؽ�� v2��
	CURRENT_USER()���ص�ǰ�û�
	CONVERT(s USING cs) �������ַ��� s ���ַ������ cs
	CHARSET() �ַ���
	CONV(x,f1,f2) ���� f1 ��������� f2 ������
	CONNECTION_ID() ���ط�������������
	COALESCE(expr1, expr2, ...., expr_n) ���ز����еĵ�һ���ǿձ��ʽ���������ң�
	CAST(x AS type) ת����������
	BINARY(s) ���ַ��� s ת��Ϊ�������ַ���
	BIN(x) ���� x �Ķ����Ʊ���


	YEARWEEK(date, mode) 0-53  366/7  ������ݼ��ڼ��ܣ�0��53����mode �� 0 ��ʾ���죬1��ʾ��һ���Դ�����
	YEAR(d) �������
	WEEKOFYEAR(d) �������� d �Ǳ���ĵڼ������ڣ���Χ�� 0 �� 53
	WEEKDAY(d) ���� d �����ڼ���0 ��ʾ����һ��1 ��ʾ���ڶ�
	WEEK(d) �������� d �Ǳ���ĵڼ������ڣ���Χ�� 0 �� 53
	TO_DAYS(d) �������� d ���� 0000 �� 1 �� 1 �յ�����
	TIMESTAMP(expression, interval) ��������ʱ�������������ڻ�����ʱ����ʽ����2������ʱ���������Ӻ�
	TIMEDIFF(time1, time2) ����ʱ���ֵ
	TIME_TO_SEC(t) ��ʱ�� t ת��Ϊ��
	TIME_FORMAT(t,f) �����ʽ f ��Ҫ����ʾʱ�� t
	TIME(expression) ��ȡ������ʽ��ʱ�䲿��
	SYSDATE()	���ص�ǰ���ں�ʱ��
	SUBTIME(t,n) ʱ�� t ��ȥ n ���ʱ��
	STR_TO_DATE(string, format_mask) ���ַ���ת��Ϊ����
	SEC_TO_TIME(s) ������Ϊ��λ��ʱ�� s ת��Ϊʱ����ĸ�ʽ
	SECOND(t) ���� t �е�����ֵ
	QUARTER(d) ��������d�ǵڼ����ڣ����� 1 �� 4
	PERIOD_DIFF(period1, period2) ��������ʱ��֮����·ݲ�ֵ
	PERIOD_ADD(period, number)Ϊ ��-�� ����������һ��ʱ��
	NOW() ���ص�ǰ���ں�ʱ��
	MONTH(d) ��������d�е��·�ֵ��1 �� 12
	MONTHNAME(d)�������ڵ��е��·����ƣ��� November
	MINUTE(t) ���� t �еķ���ֵ
	MICROSECOND(date) �������ڲ�������Ӧ��΢����
	MAKETIME(hour, minute, second) ���ʱ�䣬�����ֱ�ΪСʱ�����ӡ���
	MAKEDATE(year, day-of-year) ���ڸ���������� year ���������е�������� day-of-year ����һ������
	LOCALTIMESTAMP() ���ص�ǰ���ں�ʱ��
	LOCALTIME() ���ص�ǰ���ں�ʱ��
	LAST_DAY(d) ���ظ��������ڵ���һ�·ݵ����һ��
	HOUR(t) ���� t �е�Сʱֵ
	FROM_DAYS(n) ����� 0000 �� 1 �� 1 �տ�ʼ n ��������
	EXTRACT(type FROM d) ������ d �л�ȡָ����ֵ��type ָ�����ص�ֵ��
	DAYOFYEAR(d) �������� d �Ǳ���ĵڼ���
	DAYOFWEEK(d) ���� d ���������ڼ���1 �����գ�2 ����һ���Դ�����
	DAYOFMONTH(d) �������� d �Ǳ��µĵڼ���
	DAYNAME(d) �������� d �����ڼ����� Monday,Tuesday
	DAY(d) ��������ֵ d �����ڲ���
	DATE_SUB(date,INTERVAL expr type) ���������ڼ�ȥָ����ʱ������
	DATE_FORMAT(d,f) �����ʽ f��Ҫ����ʾ���� d
	ADDDATE(d��INTERVAL expr type) ������ʼ���� d ����һ��ʱ��κ������
	DATEDIFF(d1,d2) �������� d1->d2 ֮�����������
	DATE() �����ڻ�����ʱ����ʽ����ȡ����ֵ
	CURTIME() ���ص�ǰʱ��
	CURRENT_TIMESTAMP()���ص�ǰ���ں�ʱ��
	CURRENT_TIME() ���ص�ǰʱ��
	CURRENT_DATE() ���ص�ǰ����
	CURDATE() ���ص�ǰ����
	ADDTIME(t,n)ʱ�� t ���� n ���ʱ��

	ABS(x) ���� x �ľ���ֵ
	ACOS(x) �� x �ķ�����ֵ(�����ǻ���)
	ASIN(x) ������ֵ(�����ǻ���)
	ATAN(x) ������ֵ(�����ǻ���)
	ATAN2(n, m) ������ֵ(�����ǻ���)
	AVG(expression) ����һ�����ʽ��ƽ��ֵ��expression ��һ���ֶ�
	SELECT AVG(Price) FROM Products

	CEIL(x) ���ش��ڻ���� x ����С������
	CEILING(x) ���ش��ڻ���� x ����С������
	COS(x) ������ֵ(�����ǻ���)
	COT(x) ������ֵ(�����ǻ���)
	COUNT(expression) ���ز�ѯ�ļ�¼������expression ������һ���ֶλ��� * ��
	DEGREES(x)������ת��Ϊ�Ƕȡ���
	n DIV m
	EXP(x) ���� e �� x �η����� e=2.718281828
	FLOOR(x) ����С�ڻ���� x �������������
	GREATEST(expr1, expr2, expr3, ...) �����б��е����ֵ
	LEAST(expr1, expr2, expr3, ...) �����б��е���Сֵ
	LN(n) �������ֵ���Ȼ�������� e Ϊ�ס�
	LOG(x) �� LOG(base, x) ������Ȼ����(�� e Ϊ�׵Ķ���)��������� base �������� base Ϊָ������������
	LOG10(x) ������ 10 Ϊ�׵Ķ�������
	LOG2(x) ������ 2 Ϊ�׵Ķ���
	MAX(expression)�����ֶ� expression �е����ֵ
	SELECT MAX(Price) FROM hp;
	MIN(expression) �����ֶ� expression �е���Сֵ
	SELECT MIN(Price) FROM hp;
	MOD(x,y) ���� x ���� y �Ժ��������
	PI() ����Բ����(3.141593������
	POW(x,y) ���� x �� y �η���
	POWER(x,y) ���� x �� y �η�
	RADIANS(x) ���Ƕ�ת��Ϊ���ȡ���
	RAND() ���� 0 �� 1 �����������
	ROUND(x) ������ x ���������
	SIGN(x) ���� x �ķ��ţ�x �Ǹ�����0�������ֱ𷵻� -1��0 �� 1
	SQRT(x) ���� x ��ƽ��������
	SUM(expression) ����ָ���ֶε��ܺ�
	SELECT SUM(id) AS daslfas FROM hp;
	TAN(x) ������ֵ(�����ǻ���)
	TRUNCATE(x,y) ������ֵ x ������С����� y λ��ֵ���� ROUND ���������ǲ�������������룩

	UPPER(s) ���ַ���ת��Ϊ��д
	UCASE(s ���ַ���ת��Ϊ��д
	TRIM(s) ȥ���ַ��� s ��ʼ�ͽ�β���Ŀո�
	SUBSTRING_INDEX(s, delimiter, number)
		���ش��ַ��� s �ĵ� number �����ֵķָ��� delimiter ֮����Ӵ���
		��� number �����������ص� number ���ַ���ߵ��ַ�����
		��� number �Ǹ��������ص�(number �ľ���ֵ(���ұ���))���ַ��ұߵ��ַ�����
	SUBSTRING(s, start, length) ���ַ��� s �� start λ�ý�ȡ����Ϊ length �����ַ���
	SUBSTR(s, start, length)
	STRCMP(s1,s2) �Ƚ��ַ��� s1 �� s2����� s1 �� s2 ��ȷ��� 0 ����� s1>s2 ���� 1����� s1<s2 ���� -1
	SPACE(n) ���� n ���ո�
	RTRIM(s)ȥ���ַ��� s ��β���Ŀո�
	RPAD(s1,len,s2) ���ַ��� s1 �Ľ�β������ַ��� s2��ʹ�ַ����ĳ��ȴﵽ len
	RIGHT(s,n) �����ַ��� s �ĺ� n ���ַ�
	LEFT(s,n) �����ַ��� s ��ǰ n ���ַ�
	REVERSE(s) ���ַ���s��˳�򷴹���
	REPLACE(s,s1,s2) ���ַ��� s2 ����ַ��� s �е��ַ��� s1
	REPEAT(s,n) ���ַ��� s �ظ� n ��
	POSITION(s1 IN s) ���ַ��� s �л�ȡ s1 �Ŀ�ʼλ��
	MID(s,n,len) ���ַ��� s �� n λ�ý�ȡ����Ϊ len �����ַ�����ͬ SUBSTRING(s,n,len)
	LTRIM(s)ȥ���ַ��� s ��ʼ���Ŀո�
	LOWER(s) ���ַ��� s ��������ĸ���Сд��ĸ
	LCASE(s) ���ַ��� s ��������ĸ���Сд��ĸ
	LOCATE(s1,s) ���ַ��� s �л�ȡ s1 �Ŀ�ʼλ��
	INSERT(s1,x,len,s2) �ַ��� s2 �滻 s1 �� x λ�ÿ�ʼ����Ϊ len ���ַ���
	FORMAT(x,n) �������Խ����� x ���и�ʽ�� "#,###.##", �� x ������С����� n λ�����һλ�������롣
	FIND_IN_SET(s1,s2) �������ַ���s2����s1ƥ����ַ�����λ��
	FIELD(s,s1,s2...)���ص�һ���ַ��� s ���ַ����б�(s1,s2...)�е�λ��
	CONCAT_WS(x, s1,s2...sn) ͬ CONCAT(s1,s2,...) ����������ÿ���ַ���֮��Ҫ���� x��x �����Ƿָ���
	CONCAT(s1,s2...sn) �ַ��� s1,s2 �ȶ���ַ����ϲ�Ϊһ���ַ���
	CHARACTER_LENGTH(s) �����ַ��� s ���ַ���
	CHAR_LENGTH(s) �����ַ��� s ���ַ���
	ASCII(s) �����ַ��� s �ĵ�һ���ַ��� ASCII �롣

	create function ������([�����б�]) returns ��������
	begin
	 sql���;
	 return ֵ;
	end;
	���� create function holleworld() returns int return 123;
	select helleworld();

	create function holleworld1() returns char(100)
	begin
		return CONCAT('qwe','eee','ddfa');
	end;
	select holleworld1();

	create function holleworld2(name varchar(15)) returns char(100)
	begin
		return CONCAT(name,':','hello');
	end;
	select holleworld2();

	IN		�ֶ�ֱ�Ӵ���ȥ
	OUT		ȡ����
	INOUT	�����ȡֵ
	SET @Q = 1;
	create PROCEDURE holleworld4(IN name varchar(15))
	begin
		SET name = 'Hello';
	end;
	CALL holleworld4(@Q);
	select @Q;

	SET @Q1 = 0;
	SET @Q2 = 1;
	create PROCEDURE holleworld7(IN name varchar(15),INOUT name1 varchar(15))
	begin
		SET name = 'Hello';
		SET name1 = 'name1';
	end;
	CALL holleworld7(@Q1,Q2);
	select @Q1,@Q2;
	*/


}

USimpleMysqlObject* USimpleMySQLLibrary::CreateMysqlObject(UObject* WorldContextObject, const FString &InUser, const FString &InHost, const FString &InPawd, const FString &InDB, const int32 InPort, const TArray<ESimpleClientFlags>& InClientFlag, const FString& Unix_Socket)
{
	if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		if (USimpleMysqlObject* Object = NewObject<USimpleMysqlObject>(World))
		{
			Object->InitMysql(InUser, InHost, InPawd, InDB, InPort, Unix_Socket, InClientFlag);

			return Object;
		}
	}
	return nullptr;
}

bool USimpleMySQLLibrary::CreateDataBase(USimpleMysqlObject *Object, const FString &DataBaseName, EMysqlCharset Charset, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->CreateDataBase(DataBaseName, Charset, ErrorMsg);
	}

	return false;
}



bool USimpleMySQLLibrary::CreateAndSelectDataBase(USimpleMysqlObject *Object, const FString &DataBaseName, EMysqlCharset Charset, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->CreateAndSelectDataBase(DataBaseName, Charset, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::DropDataBase(USimpleMysqlObject *Object, const FString &DataBaseName, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->DropDataBase(DataBaseName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::CreateTable(USimpleMysqlObject *Object, const FString &TableName, const TMap<FString, FMysqlFieldType> &InFields, const TArray<FString> &InPrimaryKeys, const FMysqlCreateTableParam &Param, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->CreateTable(TableName, InFields, InPrimaryKeys, Param, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::DropTable(USimpleMysqlObject* Object, const FString& TableName, FString& ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->DropTable(TableName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::TruncateTable(USimpleMysqlObject* Object, const FString& TableName, FString& ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->TruncateTable(TableName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::DeleteFromTable(USimpleMysqlObject* Object, const FString& TableName, FString& ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->DeleteFromTable(TableName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::OptimiseTable(USimpleMysqlObject* Object, const FString& TableName, FString& ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->OptimiseTable(TableName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::DeleteFromTableWhereData(USimpleMysqlObject* Object, const FString& TableName, const FString& Condition, FString& ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->DeleteFromTableWhereData(TableName, Condition, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::SelectNewDB(USimpleMysqlObject *Object, const FString &NewDB, FString &ErrMesg)
{
	if (Object)
	{
		return Object->GetLink()->SelectNewDB(NewDB, ErrMesg);
	}

	return false;
}
bool USimpleMySQLLibrary::QueryLink(USimpleMysqlObject *Object, const FString &SQL, FString &ErrMesg)
{
	if (Object)
	{
		return Object->GetLink()->QueryLink(SQL, ErrMesg);
	}

	return false;
}






bool USimpleMySQLLibrary::PrintResult(USimpleMysqlObject *Object, const TArray<FSimpleMysqlResult>& Results, bool bPrintToScreen /*= true*/, bool bPrintToLog /*= true*/)
{
	if (Object)
	{
		return Object->GetLink()->PrintResult(Results, bPrintToScreen, bPrintToLog);
	}

	return false;
}

bool USimpleMySQLLibrary::GetSelectTableDataSQL(USimpleMysqlObject* Object, FString& SQL, const FString& TableName, const TArray<FString>& InFields, const FSimpleMysqlQueryParameters& QueryParam)
{
	if (Object)
	{
		return Object->GetLink()->GetSelectTableDataSQL(SQL,TableName, InFields, QueryParam);
	}

	return false;
}

TArray<FString> USimpleMySQLLibrary::GetStringNULLArray()
{
	return TArray<FString>();
}

TArray<FSimpleMysqlQueryOrderBy> USimpleMySQLLibrary::GetSimpleMysqlQueryOrderByNULLArray()
{
	return TArray<FSimpleMysqlQueryOrderBy>();
}

TArray<FSimpleMysqlJoinParameters> USimpleMySQLLibrary::GetFSimpleMysqlJoinParametersByNULLArray()
{
	return TArray<FSimpleMysqlJoinParameters>();
}

