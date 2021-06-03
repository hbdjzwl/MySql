// Copyright (C) RenZhai.2020.All Rights Reserved.
#include "SimpleMySQLibrary.h"
#include "MySQL/mysql.h"
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

void USimpleMySQLLibrary::MySqlMain()
{
	//Text
	/*
		char  255  char �̶���С
		varchar 255 -> text �ɱ䳤��(��ʼ������255)
		text  65,535     255ƽ�� �ɱ䳤��(��ʼ�������ֽڴ�С)
		tinytext 255  �ɱ䳤��(��ʼ�������ֽڴ�С)
		blob     65,535(�����ƴ洢���󣬳�ʼ��65535������ͼƬ��)
		mediumtext 16,777,215 ���ַ����ַ�����64�Ĵη�(text��ͬ) 1M+
		mediumblob 16,777,215 ������
		longtext	4,294,967,295 ���ַ�
		longblob	4,294,967,295 ���ַ�
		ENUM(x,y,z,etc.)  65535  ���Ϊ""Ĭ��Ϊ0������0λ  ö��ȡ����ֵ
		SET() ����ȡ����ֵ�ļ��ϣ���������64����ͬ�Ķ���
	*/
	//Number
	/*	
		int(size)  4�ֽ�: -2147483648��2147483647  0��4294967295+ size= 11
		bigint(size) -9223372036854775808 �� 9223372036854775807 0��18446744073709551615 size= 20
		tinyint(size) -128��127 0��255 size = 4
		smallint(size) -32768��32767 �޷���0��65535 size = 6
		mediumint(size) -8388608��8388607 �޷��ŵķ�Χ��0��16777215  size = 9
		float(size,d)   ��С��С�������λ
		double(size,d)
		decimal(size,d) ��Ϊ�ַ����洢�� double ����  �����ʮ����
	*/
	//Date/time
	/*
		DATE() YYYY-MM-DD (1000-01-01 ~ 9999-12-31)  2020-6-27
		DATETIME() YYYY-MM-DD HH:MM:SS      (1000-01-01 00:00:00~ 9999-12-31 23:59:59�� 2020-6-27 09:30:01
		TIMESTAMP() 1970-01-01 00:00:01 - ���� �������洢
		TIME() HH:MM:SS -838:59:59 ~ 838:59:59
		YEAR() 
	*/

	const char *user = "root";
	const char *host = "127.0.0.1";//localhost
	const char *pawd = "root";
	const char *table = "hello";
	const uint32 port = 3306;

	MYSQL mysql;
	mysql_library_init(NULL, NULL, NULL);//��֤�̰߳�ȫ
	mysql_init(&mysql);//�����ڴ�

	char select[] = "SELECT name FROM W";
	if (mysql_real_connect(&mysql, host, user, pawd, table, port, 0, 0))//����
	{
		//1.���ٷ���������
		//2.��߷�������Ӧ���ٶ�
		//3.�����ṩ�������ƣ��ÿͻ��и����ѯ����

		//MYSQL_STMT
		//MYSQL_BIND

		//MYSQL_STMT *mysql_stmt_init(MYSQL *mysql)     
		//mysql_stmt_close(MYSQL_STMT *)

		//int mysql_stmt_prepare(MYSQL_STMT *stmt, const char *query, unsigned long length)
		//my_bool mysql_stmt_bind_param(MYSQL_STMT *stmt, MYSQL_BIND *bind) 
		//my_bool mysql_stmt_bind_result(MYSQL_STMT *stmt, MYSQL_BIND *bind) 

		//int mysql_stmt_execute(MYSQL_STMT *stmt)
		//int mysql_stmt_store_result(MYSQL_STMT *stmt)  
		//int mysql_stmt_fetch(MYSQL_STMT *stmt) 

		MYSQL_STMT *Ptr = mysql_stmt_init(&mysql);

		char *SQL = "INSERT INTO ppp1 VALUES(?,?)";//��ֹע�빥��
		int ret = mysql_stmt_prepare(Ptr, SQL, FString(ANSI_TO_TCHAR(SQL)).Len());
		if (ret != 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_stmt_error(Ptr));
			return;
		}
		int32 id = 100;
		MYSQL_BIND Pram[2];
		FMemory::Memset(Pram, 0, sizeof(Pram)); //�����ʼ����Ȼ�����
		Pram[0].buffer_type = MYSQL_TYPE_LONG;	//�ֶ�����
		Pram[0].buffer = &id;	//ֵ
		Pram[0].length = 0;	

		char *content = "Hello";
		uint32 contentlen = strlen(content);
		Pram[1].buffer_type = MYSQL_TYPE_VARCHAR;
		//Pram[1].is_null = 0;	//��Ƶ˵Memset�Ϳ��п���
		Pram[1].buffer = content;
		Pram[1].length = (unsigned long*)&contentlen;
		Pram[1].buffer_length = contentlen;
		
		ret = mysql_stmt_bind_param(Ptr, Pram);
		if (ret != 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_stmt_error(Ptr));
			return;
		}

		ret = mysql_stmt_execute(Ptr);
		if (ret != 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_stmt_error(Ptr));
			return;
		}

		mysql_stmt_close(Ptr);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "connect failed!");
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mysql_error(&mysql));
	}

	mysql_close(&mysql);
	mysql_library_end();
}