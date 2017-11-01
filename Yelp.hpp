#include <memory>
#include <odb/core.hxx>
#include <odb/lazy-ptr.hxx>
#include <set>
#include <string>

#pragma db view
class StarCount{
public:
	int stars;
	int count;
};

#pragma db view query("select top 1 text, last_elapsed_time from sys.dm_exec_query_stats cross apply sys.dm_exec_sql_text(sql_handle) order by last_execution_time desc")
class LastQueryTime{
public:
	std::string text;
	long elapsed_time;
};

// ---------------------------------------------
// No need to change anything above this line
// ---------------------------------------------

//user class
#pragma db object
class User
{
	public:
		#pragma db id auto
		std::string id;
		std::string name;

		user () {};
};

//review class
#pragma db object
class Review
{
	public:
		#pragma db id auto
		std::string user_id;
		std::string business_id;

		review () {};
};

//hours class
#pragma db object
class Hours
{
	public:
		#pragma db id auto
		std::string business_id;
		std::string hours;

		hours () {};
};
