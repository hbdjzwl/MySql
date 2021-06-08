#include "Core/SimpleMysqlLinkType.h"

FMysqlFieldType::FMysqlFieldType()
{

}

FString FMysqlFieldType::ToString() const
{ 
	FString FieldTypeString;

	if (VariableLen > 0 || DecimalPoint > 0)	//�������Ⱥ�С����
	{
		FieldTypeString += TEXT("(") + FString::Printf(TEXT("%lld"), VariableLen) +	
			(DecimalPoint > 0 ? FString::Printf(TEXT(",%lld"), DecimalPoint) : FString("")) + TEXT(")");
	}
	if (bNULL)
	{
		FieldTypeString += TEXT(" NULL");
	}
	else
	{
		FieldTypeString += TEXT(" NOT NULL");
		if (!DefaultValue.IsEmpty())
		{
			FieldTypeString += TEXT(" DEFAULT ") + DefaultValue;
		}

		if (bAutoIncrement)
		{
			FieldTypeString += TEXT(" AUTO_INCREMENT");
		}
	}

	if (!Comment.IsEmpty())
	{
		FieldTypeString += TEXT(" COMMENT '") + Comment + ("'");
	}


	return FieldTypeString;
}

